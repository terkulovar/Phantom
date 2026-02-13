#include <stdio.h>
#include <iostream>
//#include <string>
//#include <cstring>
void mytest10()
{
 Double_t pi = acos(0.0)*2.0;
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
// c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
 gStyle->SetOptStat(0);
 auto hh = new TH1F("hh","",160,0,160);
 hh->SetMarkerStyle(20);
 hh->SetMarkerSize(0.8);
 hh->SetMarkerColor(2);
 hh->SetXTitle("depth in water [mm]");
 hh->SetYTitle("dE [MeV]");
 hh->SetTitle("water, proton 100MeV");
 cout<<"hh bins width center "<<hh->GetNbinsX()<<" "<<hh->GetBinWidth(1)<<" "<<hh->GetBinCenter(1)<<endl;
 auto hh0 = new TH1F("hh1","",1010,0,1010);
 hh0->SetXTitle("(#frac{MeV}{cm})");
 auto hh1 = new TH1F("hh2","",1010,0,1010);
 hh1->SetXTitle("(#frac{MeV}{cm})");
 auto hh2 = new TH1F("hh3","",1010,0,1010);
 auto hh3 = new TH1F("hh4","",1010,0,1010);
 auto hh4 = new TH1F("hh5","",1010,0,1010);
// hh1->GetYaxis()->SetLabelSize(0.035);
// hh1->GetXaxis()->SetLabelSize(0.035);
// hh1->GetYaxis()->SetTitleSize(0.035);
// hh1->GetXaxis()->SetTitleOffset(1.5);
// hh1->GetXaxis()->SetTitleSize(0.035);

 const Int_t nmeas=24;
 Int_t evId;
 Double_t en;
 Double_t energy;
 Double_t edep, zpos, dose, ziv;
 Double_t dose1, ziv1;
 Double_t stepl, L, QF;
 Int_t sindex;
 char name[20];
// char* name;
// std::string name;
 char name1[20];
 char name2[20];
// char* name1;
// char* name2;
 Double_t d[nmeas];
 Double_t ed[nmeas];
 Double_t z[nmeas];
// Double_t square = 9.;
// Double_t square = 4.0*pi*100.0*100.0;
// Double_t square = 4.0*pi*624.*624.; // MKS radius
 Double_t square = 4.0*pi*749.*749.; // MKS radius
// Double_t square = 2.0*pi*150.*(300.0+150.0)/2.0;
// Double_t square = 2.0*pi*300.*(1200.0+300.0)/2.0;
// Double_t square = 2.0*pi*211.5*(1248.0+211.5)/1.0;
// Double_t square = 500.*500.*1.;
 Double_t spectrum_all_min  = 16223328.0+107120.0+12018.0+336.263+315.71+36.1474;
// Double_t spectrum_GCR_min  = 107120.0+12018.0+336.263+315.71+36.1474; //372 km 96.7
 Double_t spectrum_GCR_min  = 4.89E+04+7.01E+03+1.98E+02+1.90E+02+2.26E+01; // 420 km 51.6
 Double_t norm = spectrum_GCR_min;     
 for ( int i = 1; i < 91; i++)
 {
//  if ( i==38 || i==78 || i==89 ) continue;
  Double_t enav = 0;
  Double_t days = 1.;
  Int_t nevents[nmeas];
  Int_t iold[nmeas];
  for ( int j = 0; j < nmeas; j++ )
  {
   d[j]=0;
   ed[j]=0;
   z[j]=0;
   nevents[j]=0;
   iold[j]=0;
  }
  Double_t d11 = 0, z11 = 0;
  TString ss;
//  ss.Form("../build/matreshka_372km_96.8_gcr_%d.root",i);
  ss.Form("../build/matreshka_420km_51.6_gcr_%d.root",i);
  cout<<"string "<<ss<<endl;
//  continue;
//  auto f = new TFile("../build/output.root");
  auto f = new TFile(ss);
  auto ftree = (TTree*)f->Get("Dose");
  auto ftree1 = (TTree*)f->Get("Event");
  auto ftree2 = (TTree*)f->Get("Dose1");
  ftree->Print();
  ftree1->SetBranchAddress("Energy",&energy);

  ftree2->SetBranchAddress("dose",&dose1);
  ftree2->SetBranchAddress("dose_zi",&ziv1);

  ftree->SetBranchAddress("Event",&evId);
  ftree->SetBranchAddress("En",&en);
  ftree->SetBranchAddress("name",&name);
  ftree->SetBranchAddress("particle",&name2);
  ftree->SetBranchAddress("zpos",&zpos);
  ftree->SetBranchAddress("Edep",&edep);
  ftree->SetBranchAddress("Dose_Gr",&dose);
  ftree->SetBranchAddress("Dose_Zi",&ziv);
  ftree->SetBranchAddress("step",&stepl);
  ftree->SetBranchAddress("L",&L);
  ftree->SetBranchAddress("QF",&QF);
  ftree->SetBranchAddress("sindex",&sindex);
  int nentries = ftree->GetEntriesFast();
  int nentries1 = ftree1->GetEntriesFast();
  int nentries2 = ftree2->GetEntriesFast();
  cout<<"entries nentries1 nentries2 "<<nentries<<" "<<nentries1<<" "<<nentries2<<endl;
//  Int_t iold = -1;
//  Int_t iold1 = -1;
//  Int_t iold2 = -1;
//  Int_t iold3 = -1;
//  Int_t iold4 = -1;
//  Int_t iold5 = -1;
//  Int_t iold6 = -1;
//  Int_t iold7 = -1;
//  Int_t iold8 = -1;
//  Int_t iold9 = -1;
//  Int_t itot = 0;
//  Int_t i1 = 0;

  for ( Int_t j = 0; j < nentries1; j++ )
  {
   ftree1->GetEntry(j);
   enav += energy/nentries1;
   cout<<"energy "<<energy<<endl;
  }
  for ( Int_t j = 0; j < nentries2; j++ )
  {
   ftree2->GetEntry(j);
   d11 += dose1;
   z11 += ziv1;
  }
  cout<<"d11 z11  "<<d11*norm*square*days<<" "<<z11*norm*square*days<<endl;



  for ( Int_t j = 0; j < nentries; j++ )
  {
   ftree->GetEntry(j);
   for ( int jj = 0; jj < nmeas; jj++ )
   {
    TString pref="Layer";
    TString temp_str;
    temp_str = pref + std::to_string(jj);
    if ( name == temp_str ) { d[jj] += dose; ed[jj] += edep; z[jj] += ziv; }
    if ( evId != iold[jj] && name == temp_str )
    {
     nevents[jj]++;
     iold[jj]=evId;
    }
   }
  }
  for ( int j = 0; j < nmeas; j++ )
  {
//  cout<<"events "<<nevents<<endl;
   d[j] = d[j]*norm*square*days;
   z[j] = z[j]*norm*square*days;
  }
  cout<<"average energy Mev "<<enav<<endl;
  cout<<"first doses Gr ";
  for ( int j = 0; j < nmeas/2; j++ )
   cout<<d[j]<<" ";
  cout<<endl;
  cout<<"second doses Gr ";
  for ( int j = nmeas/2; j < nmeas; j++ )
   cout<<d[j]<<" ";
  cout<<endl;
  cout<<"first eq doses Zi ";
  for ( int j = 0; j < nmeas/2; j++ )
   cout<<z[j]<<" ";
  cout<<endl;
  cout<<"second eq doses Zi ";
  for ( int j = nmeas/2; j < nmeas; j++ )
   cout<<z[j]<<" ";
  cout<<endl;
  cout<<"first edep MeV ";
  for ( int j = 0; j < nmeas/2; j++ )
   cout<<ed[j]<<" ";
  cout<<endl;
  cout<<"second edep MeV ";
  for ( int j = nmeas/2; j < nmeas; j++ )
   cout<<ed[j]<<" ";
  cout<<endl;
  cout<<"first nevents ";
  for ( int j = 0; j < nmeas/2; j++ )
   cout<<nevents[j]<<" ";
  cout<<endl;
  cout<<"second nevents ";
  for ( int j = nmeas/2; j < nmeas; j++ )
   cout<<nevents[j]<<" ";
  cout<<endl;
  ofstream *out;
//  out = new ofstream("mychecking_gcr_water_old_step_1mm.txt", ios::app);
//  out = new ofstream("mychecking_oldsetup.txt", ios::app);
//  out = new ofstream("spectrum_all_protons_He_C_O_Fe__min_no_yes_composite_iso_cylinder_L_1200cm_0.5-10cm_polyprop.txt", ios::app);
//  out = new ofstream("matreshka_372km_96.8_gcr.txt", ios::app);
  out = new ofstream("matreshka_420km_51.6_gcr.txt", ios::app);
  for ( int j = 0; j < nmeas; j++ )
   *out<<d[j]<<" "<<z[j]<<" "<<ed[j]<<" "<<nevents[j]<<" ";
  *out<<endl;
//  *out<<d0<<" "<<z0<<" "<<ed0<<" "<<d1<<" "<<z1<<" "<<ed1<<" "<<d2<<" "<<z2<<" "<<ed2<<" "<<d3<<" "<<z3<<" "<<ed3<<" "
//  <<d4<<" "<<z4<<" "<<ed4<<" "<<d5<<" "<<z5<<" "<<ed5<<" "<<d6<<" "<<z6<<" "<<ed6<<" "<<d7<<" "<<z7<<" "<<ed7<<" "
//  <<" "<<d8<<" "<<z8<<" "<<ed8<<" "" "<<d9<<" "<<z9<<" "<<ed9<<" "<<
//   nevents<<" "<<nevents1<<" "<<nevents2<<" "<<nevents3<<" "<<nevents4<<" "<<nevents5<<" "<<nevents6<<" "<<nevents7
//   <<" "<<nevents8<<" "<<nevents9<<endl;
  out->close();
  delete out;
  f->Close();
 }
 gDirectory->ls();
// cout<<"entries in h1 "<<hh1->GetEntries()<<endl;
// TDirectory *top = new TDirectory("top","top");
// TFile *f1 = new TFile("myrec_gcr_water_old_step.root","recreate");
// hh0->SetDirectory(top);
// hh0->Write();
// hh1->SetDirectory(top);
// hh1->Write();
// hh2->SetDirectory(top);
// hh2->Write();
// hh3->SetDirectory(top);
// hh3->Write();
// hh4->SetDirectory(top);
// hh4->Write();
// f1->Close();
 gApplication->Terminate();
}
