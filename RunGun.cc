//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//


#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"
#include "MyRunAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

//#ifdef G4MULTITHREADED
//#include "G4MTRunManager.hh"
//#else
//#include "G4RunManager.hh"
//#endif


#include "G4RunManagerFactory.hh"
#include "G4SteppingVerbose.hh"
#include "G4UImanager.hh"
#include "PhysicsList.hh"
//#include "QBBC.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4RadioactiveDecayPhysics.hh"

#include "Randomize.hh"

using namespace std;


int main(int argc,char** argv)
{

  // Detect interactive mode (if no arguments) and define UI session
  //
  //******************* new random engine and random seed***************
//  CLHEP::HepRandom::setTheEngine(new CLHEP::MTwistEngine);
//  CLHEP::HepRandom::setTheSeed((unsigned)clock());
  //******************************************************

  G4bool   isAF(false);
  G4UIExecutive* ui = nullptr;
  if ( argc == 1 ) { ui = new G4UIExecutive(argc, argv); }

//  if (argc==1)   // Define UI session for interactive mode.
//    {
      // G4UIterminal is a (dumb) terminal
      //
//#if defined(G4UI_USE_XM)
//      ui = new G4UIXm(argc,argv);
//#elif defined(G4UI_USE_WIN32)
//      ui = new G4UIWin32();
//#elif defined(G4UI_USE_TCSH)
//      ui = new G4UIterminal(new G4UItcsh);
//#else
//      ui = new G4UIterminal();
//#endif
//    }

//#ifdef G4VIS_USE
  // Visualization manager
  //
//  G4VisManager* visManager = new G4VisExecutive;
//  visManager->Initialize();
//#endif


  // Optionally: choose a different Random engine...
  // G4Random::setTheEngine(new CLHEP::MTwistEngine);

  //use G4SteppingVerboseWithUnits
  G4int precision = 4;
  G4SteppingVerbose::UseBestUnit(precision);

  // Construct the default run manager
  // Construct the default run manager
  //
//#ifdef G4MULTITHREADED
//  G4MTRunManager * runManager = new G4MTRunManager;
//#else
//  G4RunManager * runManager = new G4RunManager;
//#endif


  auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

  // Detector construction
  auto* tetData = new TETModelImport(isAF, ui);
  DetectorConstruction* detector = new DetectorConstruction(tetData);
//  DetectorConstruction* detector = new DetectorConstruction();
  cout<<"!!!!!!!!!!!!!!!!!!!!!! Detector initialized "<<endl;
  // Set mandatory initialization classes
  runManager->SetUserInitialization(detector);
//  runManager->SetUserInitialization();

  // Physics list
  //G4VModularPhysicsList* physicsList = new QBBC;
  //physicsList->SetVerboseLevel(1); // ?
  //physicsList->RegisterPhysics(new G4StepLimiterPhysics()); //!!!!!!!!!!!!!!!
  //physicsList->RegisterPhysics(new G4RadioactiveDecayPhysics);
  //runManager->SetUserInitialization(physicsList);
 // new implimentation of physics physicsList
 PhysicsList* phys = new PhysicsList;
 runManager->SetUserInitialization(phys);



  // User action initialization
  runManager->SetUserInitialization(new MyActionInitialization(detector,tetData));
  // Set user action classes
  //
//  G4VUserPrimaryGeneratorAction* gen_action = new PrimaryGeneratorAction(detector);
//  PrimaryGeneratorAction* gen_action = new PrimaryGeneratorAction(detector);
//  runManager->SetUserAction(gen_action);
  //
//  MyRunAction* run_action = new MyRunAction(detector);
//  MyRunAction* run_action = new MyRunAction();
//  runManager->SetUserAction(run_action);
  //

//  EventAction* event_action = new EventAction(run_action,gen_action);
//  runManager->SetUserAction(event_action);
  //
//  G4UserSteppingAction* stepping_action =
//  MySteppingAction* stepping_action =
//    new MySteppingAction(detector, event_action);
//    new SteppingAction(event_action);
//  runManager->SetUserAction(stepping_action);

  // Initialize G4 kernel
  //
//  runManager->Initialize();


  // Initialize visualization
  //
  G4VisManager* visManager = new G4VisExecutive;
  // G4VisExecutive can take a verbosity argument - see /vis/verbose guidance.
  // G4VisManager* visManager = new G4VisExecutive("Quiet");
  visManager->Initialize();



  // Get the pointer to the User Interface manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  // Process macro or start UI session
  //
  if ( ! ui ) {
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command+fileName);
  }
  else {
    // interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
//    UImanager->ApplyCommand("/control/execute vis.mac");
//    UImanager->ApplyCommand("/control/execute run11.in");
    ui->SessionStart();
    delete ui;
  }

  // Job termination
  // Free the store: user actions, physics_list and detector_description are
  // owned and deleted by the run manager, so they should not be deleted
  // in the main() program !

  delete visManager;
  delete runManager;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

