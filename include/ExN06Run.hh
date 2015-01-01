#ifndef ExN06Run_h
#define ExN06Run_h 1

#include "globals.hh"
#include "G4Run.hh"

#include "G4THitsMap.hh"

class G4Event;

class ExN06Run : public G4Run
{
  public:
    ExN06Run();
    virtual ~ExN06Run();

  public:
    virtual void RecordEvent(const G4Event*);

  private:
    G4double GetTotal(const G4THitsMap<G4double> &map) const;

  private:
    // Maps for accumulation
    // mapSum[i][j]
    //  i = 0 : Calor-A_abs    j = 0 : total eDep
    //  i = 1 : Calor-A_gap    j = 1 : number of gamma
    //  i = 2 : Calor-B_abs    j = 2 : number of electron
    //  i = 3 : Calor-B_gap    j = 3 : number of positron
    //  i = 4 : Calor-C_abs    j = 4 : total step length for e+/e-
    //  i = 5 : Calor-C_gap    j = 5 : total number of steps for e+/e-
    G4THitsMap<G4double> mapSum[1][1];
    G4int colIDSum[1][1];

  public:
    inline G4double GetTotalE() const
    { return GetTotal(mapSum[0][0]); }

};

#endif



















/*
#include "globals.hh"
#include "G4Run.hh"

#include "G4THitsMap.hh"

//#include "G4Event.hh"

class G4Event;

class ExN06Run : public G4Run
{
    public:      
        ExN06Run();
        virtual ~ExN06Run();

    public:
        virtual void RecordEvent(const G4Event*);//Records all data into 1 variable

    private:
        G4int numberOfEvent;
        G4int colID[48];

        G4double GetTotal(const G4THitsMap<G4double> &map) const;

        G4THitsMap<G4double> runHitsMap[48];         //Total number of events (ID)
        G4THitsMap<G4double>* eventTotalEDep;   //Actual data for event

//access methods
    public:
        inline G4double GetTotalEDep() const
        {
            return GetTotal(runHitsMap[48]);
           // return totalEDep;
        }
};

*/
