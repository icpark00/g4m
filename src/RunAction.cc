#include "RunAction.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4SystemOfUnits.hh"
#include "THFile.hh"

RunAction::RunAction() : G4UserRunAction() { }

RunAction::~RunAction() { }

void RunAction::BeginOfRunAction(const G4Run* run)
{ 
	//inform the runManager to save random number seed
	G4RunManager::GetRunManager()->SetRandomNumberStore(false);

	THFile* file = THFile::Instance();
	file->SetFileName("LN");
	file->mkdir("Secondaries");
	file->mkdir("proton-neutron");
	
}

void RunAction::EndOfRunAction(const G4Run* run)
{
	THFile* file = THFile::Instance();
	file->Close();
}
