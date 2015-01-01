
#include "../include/ExN06RunAction.hh"
#include "../include/ExN06Run.hh"

#include "../include/G4RegionStore.hh"
#include "../include/G4Region.hh"
#include "../include/G4ProductionCuts.hh"
#include "../include/G4ios.hh"
#include "../include/G4UnitsTable.hh"

#include "../include/G4VSteppingVerbose.hh"
#include "../include/ExN06SteppingVerbose.hh"

ExN06RunAction::ExN06RunAction()
{;}

ExN06RunAction::~ExN06RunAction()
{;}

G4Run* ExN06RunAction::GenerateRun()
{ return new ExN06Run; }
/*
void ExN06RunAction::BeginOfRunAction(const G4Run*)
{
  ExN06SteppingVerbose* sv = (ExN06SteppingVerbose*)(G4VSteppingVerbose::GetInstance());
  sv->InitializeTimers();
}
*/
void ExN06RunAction::EndOfRunAction(const G4Run* aRun)
{
  static G4String regName[1] = {"MFDetName"};

  const ExN06Run* theRun = (const ExN06Run*)aRun;

  G4cout
    << "############################################################" << G4endl;
  G4cout
    << " Run Summary - Number of events : " << theRun->GetNumberOfEvent()
    << G4endl;
  G4cout
    << "############################################################" << G4endl;

  G4double nEvt = (G4double)(theRun->GetNumberOfEvent());



    G4cout << " Energy deposition in an event :" << G4endl << "   "
           << " Absorber " << G4BestUnit((theRun->GetTotalE()),"Energy")
           << "      Gap " << G4BestUnit((theRun->GetTotalE()),"Energy")
           << G4endl;
}
















/*
#include "../include/ExN06RunAction.hh"
#include "../include/ExN06Run.hh"


ExN06RunAction::ExN06RunAction()
{;}

ExN06RunAction::~ExN06RunAction()
{;}

G4Run* ExN06RunAction::GenerateRun()
{
   //ExN06Run* theRun = new ExN06Run();
  return new ExN06Run;
  //  return 0;
}

void ExN06RunAction::EndOfRunAction(const G4Run* aRun)
{
    const ExN06Run* theRun = (const ExN06Run*)aRun; //analyse/record/print run summary
            //MyRun object has everything required
    G4cout
       << "############################################################" << G4endl;
    G4cout
       << " Run Summary - Number of events : " << theRun->GetNumberOfEvent()
       << G4endl;
    G4cout
       << "############################################################" << G4endl;

    G4double nEvt = (G4double)(theRun->GetNumberOfEvent());

    G4cout
            << "Total Energy Deposited" << (theRun->GetTotalEDep());

}
*/

