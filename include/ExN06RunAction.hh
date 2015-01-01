
#ifndef ExN06RunAction_h
#define ExN06RunAction_h 1


//#include "../include/ExN06RunAction.hh"
//#include "../include/ExN06Run.hh"

#include "G4UserRunAction.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Run;


class ExN06RunAction : public G4UserRunAction
{
  public:
    ExN06RunAction();
   ~ExN06RunAction();

  public:
    //virtual void BeginOfRunAction(const G4Run* aRun);
    virtual void EndOfRunAction(const G4Run* aRun);
    G4Run* GenerateRun();

  //  ExN06Run ExN06RunO = new ExN06Run();

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif //ExN06RunAction_h


