#ifndef MyRunAction_HH
#define MyRunAction_HH 1

#include "G4UserRunAction.hh"
//#include "G4Run.hh"
#include "DetectorConstruction.hh"

#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"
//#include "TETModelImport.hh"

class G4Run;
class MyRunAction : public G4UserRunAction
{
public:
    MyRunAction();
    ~MyRunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
    void FillPerEvent(G4double, G4double, G4double, G4double, G4double);
    G4double GetD5() {return Dl5;};
    G4double GetD6() {return Dl6;};
    G4double GetDose() {return Dose_Gr; };
    G4double GetEDose() {return Dose_Zi; };
    void AddPhantom( G4double d1, G4double d2, G4double z );

    const G4double MinZ = 0.*CLHEP::cm;
    const G4double MaxZ = 100*CLHEP::cm;

    const G4double stepfordEdz = 1.* CLHEP::mm;
    const G4double stepforfluence = 1.* CLHEP::mm;

private:
    G4double Dose_MeV;
    G4double Dose_Gr;
    G4double Dose_Zi;
    G4double Dose_Ph1;
    G4double Dose_ZPh1;
    G4double Dose_Ph2;
    G4double Dose_ZPh2;
    G4double zpos;;
    G4double Dl5;
    G4double Dl6;
//    TETModelImport* fTetData;
};

#endif
