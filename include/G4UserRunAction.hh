
// $Id$
//

#ifndef G4UserRunAction_h
#define G4UserRunAction_h 1

class G4Run;

// class description:
//
//  This is the base class of a user's action class which defines the
// user's action at the begining and the end of each run. The user can
// override the following two methods but the user should not change 
// any of the contents of G4Run object.
//    virtual void BeginOfRunAction(const G4Run* aRun);
//    virtual void EndOfRunAction(const G4Run* aRun);
// The user can override the following method to instanciate his/her own
// concrete Run class. G4Run has a virtual method RecordEvent, so that
// the user can store any information useful to him/her with event statistics.
//    virtual G4Run* GenerateRun();
//  The user's concrete class derived from this class must be set to
// G4RunManager via G4RunManager::SetUserAction() method.
//

class G4UserRunAction
{
  public:
    G4UserRunAction();
    virtual ~G4UserRunAction();

  public:
    virtual G4Run* GenerateRun();
    virtual void BeginOfRunAction(const G4Run* aRun);
    virtual void EndOfRunAction(const G4Run* aRun);
};

#endif


