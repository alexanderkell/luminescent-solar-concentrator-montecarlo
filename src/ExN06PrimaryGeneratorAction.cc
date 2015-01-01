#include "ExN06PrimaryGeneratorAction.hh"
#include "ExN06PrimaryGeneratorMessenger.hh"

#include "Randomize.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN06PrimaryGeneratorAction::ExN06PrimaryGeneratorAction()
{
  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);

  //create a messenger for this class
  gunMessenger = new ExN06PrimaryGeneratorMessenger(this);

  //default kinematic
  //
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle("opticalphoton");
    G4int nParticles = 10;
  particleGun->SetParticleDefinition(particle);
  particleGun->SetParticleTime(0.0*ns);
  particleGun->SetParticleMomentumDirection(G4ThreeVector(0,-1,0));
  particleGun->SetNumberOfParticles(10);
  //particleGun->SetParticleMomentumDirection(G4ThreeVector(-1,-1,-1));

  particleGun->SetParticleEnergy(2.885*eV);

  for(G4int i = 0; i<nParticles; i++){
      G4int v1 = rand() % 10;
    particleGun->SetParticlePosition(G4ThreeVector(0*m,10*m,v1*m));
  }
  //particleGun->SetParticlePosition(G4ThreeVector(10*m,10*m,10*m));

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ExN06PrimaryGeneratorAction::~ExN06PrimaryGeneratorAction()
{
  delete particleGun;
  delete gunMessenger;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN06PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  particleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN06PrimaryGeneratorAction::SetOptPhotonPolar()
{
 G4double angle = G4UniformRand() * 360.0*deg;
 SetOptPhotonPolar(angle);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExN06PrimaryGeneratorAction::SetOptPhotonPolar(G4double angle)
{
 if (particleGun->GetParticleDefinition()->GetParticleName() != "opticalphoton")
   {
     G4cout << "--> warning from PrimaryGeneratorAction::SetOptPhotonPolar() :"
               "the particleGun is not an opticalphoton" << G4endl;
     return;
   }

 G4ThreeVector normal (1., 0., 0.);
 G4ThreeVector kphoton = particleGun->GetParticleMomentumDirection();
 G4ThreeVector product = normal.cross(kphoton);
 G4double modul2       = product*product;

 G4ThreeVector e_perpend (0., 0., 1.);
 if (modul2 > 0.) e_perpend = (1./std::sqrt(modul2))*product;
 G4ThreeVector e_paralle    = e_perpend.cross(kphoton);

 G4ThreeVector polar = std::cos(angle)*e_paralle + std::sin(angle)*e_perpend;
 particleGun->SetParticlePolarization(polar);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
