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
/// \file EventAction.hh
/// \brief Definition of the B1::EventAction class

#ifndef B1EventAction_h
#define B1EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4AnalysisManager.hh"
#include <vector>

/// Event action class
///

class MyRunAction;
class PrimaryGeneratorAction;

class EventAction : public G4UserEventAction
{
  public:
    EventAction(MyRunAction* runAction, PrimaryGeneratorAction* generatorAction);
    ~EventAction() override;

    void BeginOfEventAction(const G4Event* event) override;
    void EndOfEventAction(const G4Event* event) override;

//    void AddEdep(G4double edep, G4int i) { fEdepV.at(i) += edep; };
    void AddEdep(G4double, G4double, G4String, G4double);
    void AddPhantom(G4double d1, G4double d2, G4double z ){ Dose_Ph += d1; Dose_ZPh += d2; zpos = z;  };



  private:
    MyRunAction* fRunAction = nullptr;
    PrimaryGeneratorAction* fGeneratorAction;
    G4double Dose_MeV;
    G4double Dose_Gr;
    G4double Dose_Zi;
    G4double Energy;
    G4double myz;
    G4double Dose_Ph;
    G4double Dose_ZPh;
    G4double zpos;
    G4int f1, f2, f3, f4, f5;
    G4int iLiF;
    G4int evtNb;
    G4double Dl, Dl1, Dl2, Dl3, Dl4, Dl5, Dl6, Dl7, Dl8, Dl9;
    G4String  myname;
    std::vector<G4double> dose;
    std::vector<G4double> edose;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
