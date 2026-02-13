#include "MyRunAction.hh"
#include "G4RunManager.hh"
#include "G4PrimaryVertex.hh"
#include "G4AccumulableManager.hh"
#include "G4Run.hh"
#include "G4TaskRunManager.hh"
using namespace std;

MyRunAction::MyRunAction()
{
  Dose_MeV = 0;
  Dose_Gr = 0;
  Dose_Zi = 0;
  Dose_Ph1 = 0;
  Dose_ZPh1 = 0;
  Dose_Ph2 = 0;
  Dose_ZPh2 = 0;
  Dl5 = 0;
  Dl6 = 0;
  auto analysisManager = G4AnalysisManager::Instance();

  G4RunManager::GetRunManager()->SetPrintProgress(0);

  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);
  analysisManager->SetFirstNtupleId(1);
//  analysisManager->SetFirstH1Id(1);
// Fluences for all particles, for a given particle easy to get taking a projection on a particle type

//  man->CreateNtuple("Fluences", "Fluences");
//  man->CreateNtupleIColumn("Event");
//  man->CreateNtupleDColumn("X");
//  man->CreateNtupleDColumn("Y");
//  man->CreateNtupleDColumn("Zsurf");
//  man->CreateNtupleDColumn("Energy");
//  man->CreateNtupleIColumn("particle_id");
//  man->CreateNtupleSColumn("particle_name");
//  man->CreateNtupleSColumn("material_name_end");
//  man->FinishNtuple(0);

// Differential energy for the primary particle (step will be an input parameter)

//  man -> CreateNtuple("dEdz","dEdz");
//  man->CreateNtupleDColumn("Edep_MeV");
//  man->CreateNtupleDColumn("Step");
//  man->CreateNtupleDColumn("Z");
//  man->CreateNtupleDColumn("En");
//  man->CreateNtupleIColumn("Event");
//  man->FinishNtuple(1);
/*
  analysisManager->CreateNtuple("Dose_Ev", "Dose_Ev");
  analysisManager->CreateNtupleIColumn("Event");
  analysisManager->CreateNtupleDColumn("Energy");
  analysisManager->CreateNtupleDColumn("Dose_MeV");
  analysisManager->CreateNtupleDColumn("Dose_Gr");
  analysisManager->CreateNtupleDColumn("Dose_Zi");
  analysisManager->FinishNtuple();

  analysisManager->CreateNtuple("Dose_Run", "Dose_Run");
  analysisManager->CreateNtupleIColumn("Nevent");
  analysisManager->CreateNtupleDColumn("Dose_MeV");
  analysisManager->CreateNtupleDColumn("Dose_Gr");
  analysisManager->CreateNtupleDColumn("Dose_Zi");
  analysisManager->FinishNtuple();
*/

  analysisManager->CreateNtuple("Dose", "Dose");
  analysisManager->CreateNtupleIColumn("Event");
  analysisManager->CreateNtupleDColumn("En");
  analysisManager->CreateNtupleSColumn("name");
  analysisManager->CreateNtupleSColumn("particle");
  analysisManager->CreateNtupleDColumn("zpos");
  analysisManager->CreateNtupleDColumn("Edep");
  analysisManager->CreateNtupleDColumn("Dose_Gr");
//  analysisManager->CreateNtupleDColumn("mass");
  analysisManager->CreateNtupleDColumn("Dose_Zi");
  analysisManager->CreateNtupleDColumn("cross");
  analysisManager->CreateNtupleDColumn("step");
  analysisManager->CreateNtupleDColumn("L");
  analysisManager->CreateNtupleDColumn("QF");
  analysisManager->CreateNtupleIColumn("sindex");
  analysisManager->FinishNtuple(1);

//  analysisManager->CreateH1("h1","",60,0.,30.);
//  analysisManager->CreateH1("h2","",60,0.,30.);
//  analysisManager->CreateH1("h3","",410,0.,410.);
//  analysisManager->CreateH1("h4","",410,0.,410.);
//  analysisManager->CreateH1("h5","",410,0.,410.);
//  analysisManager->CreateH1("h6","",410,0.,410.);
//  analysisManager->CreateH1("h7","",410,0.,410.);

//  analysisManager->CreateH1("h8","",410,0.,410.);
//  analysisManager->CreateH1("h9","",410,0.,410.);
//  analysisManager->CreateH1("h10","",410,0.,410.);
//  analysisManager->CreateH1("h11","",410,0.,410.);
//  analysisManager->CreateH1("h12","",410,0.,410.);

//  analysisManager->CreateH1("h13","",410,0.,410.);
//  analysisManager->CreateH1("h14","",410,0.,410.);
//  analysisManager->CreateH1("h15","",410,0.,410.);
//  analysisManager->CreateH1("h16","",410,0.,410.);
//  analysisManager->CreateH1("h17","",410,0.,410.);
//  std::vector<double> xbins = {0.1,0.15,0.2,0.3,0.4,0.5,0.6,0.7,1.0,1.5,2.,3.,4.,5.,6.,7.,10.,15.,20.,30.,40.,50.,60.,70., 100.,150.,200.,300.,400.,410.};
//  analysisManager->CreateH1("h1","",10000000,0.09,410.);
//  analysisManager->CreateH1("h1","", xbins);
//  analysisManager->CreateH1("h2","",820,0.9,410.);
//  analysisManager->CreateH1("h3","",200,0.,200.);
//  analysisManager->CreateH1("h4","",200,-1.5,1.5);
//  analysisManager->CreateH1("h5","",200,-1.5,1.5);

//  analysisManager->CreateNtuple("Event", "Event");
//  analysisManager->CreateNtupleDColumn("Energy");
//  analysisManager->CreateNtupleSColumn("name");
//  analysisManager->CreateNtupleDColumn("X_dir");
//  analysisManager->CreateNtupleDColumn("Y_dir");
//  analysisManager->CreateNtupleDColumn("Z_dir");
//  analysisManager->CreateNtupleDColumn("Phi_dir");
//  analysisManager->CreateNtupleDColumn("Theta_dir");
//  man->CreateNtupleSColumn("Particle_Name");
//  man->CreateNtupleIColumn("Particle_Id");
//  analysisManager->CreateNtupleDColumn("X_pos");
//  analysisManager->CreateNtupleDColumn("Y_pos");
//  analysisManager->CreateNtupleDColumn("Z_pos");
//  analysisManager->CreateNtupleDColumn("Phi_pos");
//  analysisManager->CreateNtupleDColumn("Theta_pos");
//  analysisManager->FinishNtuple(2);

//  analysisManager->CreateNtuple("Energy", "Energy");
//  analysisManager->CreateNtupleDColumn("Energy");
//  analysisManager->CreateNtupleSColumn("name");
//  analysisManager->CreateNtupleDColumn("zpos");
//  analysisManager->CreateNtupleDColumn("Destep");
//  analysisManager->CreateNtupleDColumn("step");
//  analysisManager->FinishNtuple(3);

  analysisManager->CreateNtuple("Dose1", "Dose1");
  analysisManager->CreateNtupleDColumn("zpos");
  analysisManager->CreateNtupleDColumn("dose_gr");
  analysisManager->CreateNtupleDColumn("dose_zi");
//  analysisManager->CreateNtupleDColumn("dose_gr2");
//  analysisManager->CreateNtupleDColumn("dose_zi2");
  analysisManager->FinishNtuple(2);

//  auto tm = dynamic_cast<G4TaskRunManager*>(G4RunManager::GetRunManager());
//  cout<<"!!!!!!!!!!!!!!!!!!!!!!! # of threads "<<tm->GetNumberOfThreads () <<endl;
}

MyRunAction::~MyRunAction()
{}

void  MyRunAction::AddPhantom( G4double d1, G4double d2, G4double z )
{
 if ( z > 0 )
 {
  Dose_Ph1 += d1; 
  Dose_ZPh1 += d2;
 } 
 if ( z < 0 )
 {
  Dose_Ph2 += d1; 
  Dose_ZPh2 += d2;
 } 
}

void MyRunAction::FillPerEvent(G4double dose_mev, G4double dose_gr, G4double dose_zi, G4double d5, G4double d6)
{
  //accumulate statistic
  Dose_MeV += dose_mev;
  Dose_Gr += dose_gr;
  Dose_Zi += dose_zi;
  Dl5 += d5;
  Dl6 += d6;

//  cout<<"!!!!!!!!!!!!!!! run "<<Dose_MeV<<" "<<Dose_Gr<<" "<<Dose_Zi<<endl;
}



void MyRunAction::BeginOfRunAction(const G4Run* aRun)
{

    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
//    analysisManager->SetNtupleMerging(true);
    analysisManager->OpenFile();
//    analysisManager->OpenFile("output.root");
//    analysisManager->CreateH1("h1","tt",300,0.,30.);
//    analysisManager->CreateH1("h2","tt",300,0.,30.);
    G4cout << "Using " << analysisManager->GetType() << G4endl;
   
//    man->CreateNtupleDColumn("dose");
//    man->CreateNtupleDColumn("Z");
//    man->FinishNtuple(0);
//    cout<<"!!!!!!!!!!!!!!!!!! begin RUN "<<endl;
//    man->Write();
//    man->CloseFile();


    // set printing event number per each event
}


void MyRunAction::EndOfRunAction(const G4Run* aRun)
{
//    auto analysisManager = G4AnalysisManager::Instance();
    G4AnalysisManager *analysisManager = G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(2);
    
//    cout<<" Dose_Ph1 Dose_ZPh1 "<<Dose_Ph1<<" "<<Dose_ZPh1<<endl;
//    analysisManager->FillNtupleDColumn(2,0,Dose_Ph1);
//    analysisManager->FillNtupleDColumn(2,1,Dose_ZPh1);
//    analysisManager->FillNtupleDColumn(2,2,Dose_Ph2);
//    analysisManager->FillNtupleDColumn(2,3,Dose_ZPh2);
//    analysisManager->AddNtupleRow(2);
    G4int NbOfEvents = aRun->GetNumberOfEvent();
    cout<<"nevents "<<NbOfEvents<<endl;
//    analysisManager->ScaleH1(0,1./NbOfEvents);
//    analysisManager->ScaleH1(1,1./NbOfEvents);
//    analysisManager->FillNtupleIColumn(2,0,NbOfEvents);
//    analysisManager->FillNtupleDColumn(2,1,Dose_MeV);
//    analysisManager->FillNtupleDColumn(2,2,Dose_Gr);
//    analysisManager->FillNtupleDColumn(2,3,Dose_Zi);
//    analysisManager->AddNtupleRow(2);


    analysisManager->Write();
    analysisManager->CloseFile();

    cout<<"!!!!!!!!!!!!!!!!!! end RUN "<<endl;
}
