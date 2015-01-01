
#include "../include/ExN06Run.hh"
#include "../include/G4Event.hh"
#include "../include/G4HCofThisEvent.hh"
#include "../include/G4SDManager.hh"

ExN06Run::ExN06Run()
{
  G4String detName[1] = {"MFDetName"};
  G4String primNameSum[1] = {"totalEDep"};

  G4SDManager* SDMan = G4SDManager::GetSDMpointer();
  G4String fullName;
  size_t i,j;
  for(i=0;i<1;i++)
  {
    for(j=0;j<1;j++)
    {
      fullName = detName[i]+"/"+primNameSum[j];
      colIDSum[i][j] = SDMan->GetCollectionID(fullName);
    }
  }
}

ExN06Run::~ExN06Run()
{;}

void ExN06Run::RecordEvent(const G4Event* evt)
{
    G4HCofThisEvent* HCE = evt->GetHCofThisEvent();
    if(!HCE) return;
    numberOfEvent++;
    size_t i,j;
    for(i=0;i<1;i++)
    {
      for(j=0;j<1;j++)
      {
        G4THitsMap<G4double>* evtMap = (G4THitsMap<G4double>*)(HCE->GetHC(colIDSum[i][j]));
        mapSum[i][j] += *evtMap;
        for(j=0;j<1;j++)
        {
          std::map<G4int,G4double*>::iterator itr = evtMap->GetMap()->begin();
          for(; itr != evtMap->GetMap()->end(); itr++)
          {
            G4int key = (itr->first);
            G4double val = *(itr->second);
            G4double* mapP = mapSum[i][j][key];
            if( mapP && (val>*mapP) ) continue;
            mapSum[i][j].set(key,val);
      }

        }
      }
    }
}

G4double ExN06Run::GetTotal(const G4THitsMap<G4double> &map) const
{
  G4double tot = 0.;
  std::map<G4int,G4double*>::iterator itr = map.GetMap()->begin();
  for(; itr != map.GetMap()->end(); itr++)
  { tot += *(itr->second); }
  return tot;
}



















/*
#include "../include/ExN06Run.hh"

#include "../include/G4Event.hh"

#include "../include/G4HCofThisEvent.hh"
#include "../include/G4SDManager.hh"

// #include "../include/ExN06RunAction.hh"

class G4Event;

ExN06Run::ExN06Run()
{
    G4SDManager* SDM = G4SDManager::GetSDMpointer();
    //Get Sensitive Detector Manager Pointer (Get control from sensitive detectors)
    colID[0] = SDM -> GetCollectionID("MFDetName/totalEDep");
    //Point to object of sensitive collector - Collection ID's
}

ExN06Run::~ExN06Run(){
    ;
}

void ExN06Run::RecordEvent(const G4Event* evt)
{
   // numberOfEvent++;   //increment to get total number of events - Whole system not per photon
   // G4HCofThisEvent* HCE = evt-> GetHCofThisEvent();
                //HCofThisEvent stores hits collection for 1 event, but deletes after
   // G4THitsMap<G4double>* evtMap = (G4THitsMap<G4Double*)(HCE->GetHC(totalEDepID));
   // G4int n = evtMap->entries();

    if(HCE){
        for(G4int i =0; i<48; i++){
            G4THitsMap<G4double>* eventHitsMap = (G4THitsMap<G4double>*)(HCE->GetHC(colID[i]);
                    runHitsMap[i]= *eventsHitMap;
        }
    }


    eventTotalEDep = (G4THitsMap<G4double>*)(HCE->GetHC(totalEDepID));
        //Total data for event stored from the temporary HCofThisEvent

    totalEDep += *eventTotalEDep;
}

G4double ExN06Run::GetTotal(const G4THitsMap<G4double> &map) const
{
    //G4double tot = 0.;

    //convert to G4int from G4double* (pointer)
    std::map<G4int,G4double*>::iterator itr = evtMap->GetMap()->begin();
    for( ; itr != evtMap->GetMap()->end(); itr++) //keep adding until finally mapped
        {
        G4int key = (itr->first);
        G4double val = *(itr->second);//return pointer
        //    tot += *(itr->second);
        }
    return tot;
}
*/
