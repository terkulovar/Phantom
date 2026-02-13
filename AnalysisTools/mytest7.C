#include <stdio.h>
#include <iostream>
//#include <string>
//#include <cstring>
void mytest7(double w, double prob)
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
 auto f = new TFile("../build/output.root");
 auto ftree = (TTree*)f->Get("Dose");
 auto ftree1 = (TTree*)f->Get("Event");
 auto ftree2 = (TTree*)f->Get("Dose1");
 ftree->Print();
 Int_t evId;
 Double_t en;
 Double_t energy;
 Double_t edep, zpos, dose, ziv;
 Double_t dose1, ziv1;
 char name[20];
// char* name;
// std::string name;
 char name1[20];
 char name2[20];
// char* name1;
// char* name2;
 Double_t mass = 2.*2.*0.5/1000.;
 Double_t d1, d2, d3, d4, d5, d6;
 Double_t ed1, ed2, ed3, ed4, ed5, ed6;
 Double_t z1, z2, z3, z4, z5, z6;
 Double_t enav = 0;
 Double_t days = 1.;
 d1=0; d2=0; d3=0; d4=0; d5=0; d6=0;
 ed1=0; ed2=0; ed3=0; ed4=0; ed5=0; ed6=0;
 z1=0; z2=0; z3=0; z4=0; z5=0; z6=0;
 Double_t d11 = 0, z11 = 0;
// Double_t square = 9.;
// Double_t square = 4.0*pi*100.0*100.0;
// Double_t square = 4.0*pi*150.*150.*2.;
// Double_t square = 500.*500.*1.;
 Double_t square = 5.*5.*1.;
 Double_t spectrum_trapped_protons_max  = 2.27e+07;
 Double_t spectrum_trapped_protons_min  = 5.11e+07;
 Double_t spenvis_trapped_protons_2010_min  = 789696;
 Double_t spenvis_trapped_protons_2010_368km_min  = 22982400;
 Double_t spenvis_trapped_protons_2010_368km_min_new  = 22302432;
 Double_t spenvis_trapped_protons_2010_368km_min_1Mev  = 4464288.;
 Double_t spenvis_trapped_protons_2010_368km_52degree_min_1Mev  = 4.03237e+06;
// Double_t spenvis_trapped_protons_2010_368km_52degree_min_1Mev  = 3.03237e+06;
 Double_t spenvis_trapped_protons_2010_min_1Mev  = 151099;
 Double_t spectrum_trapped_protons_min_1Mev  = 9.95E+06;
 Double_t spectrum_trapped_protons_min_10Mev  = 1.87E+06;
 Double_t spectrum_GCR_H_min  = 4.89E+04;
 Double_t spectrum_GCR_He_min  = 7.01E+03;
 Double_t spectrum_GCR_Li_min  = 3.03E+01;
 Double_t spenvis_trapped_protons_min  = 2.36313e+08;
 Double_t spenvis_trapped_protons_max  = 9.15764e+07;
 Double_t spenvis_GCR_min_368km_H = 47536.5;
 Double_t spenvis_GCR_min_368km_He = 6878.22;
 Double_t norm = spectrum_GCR_He_min;
// Double_t norm = spectrum_trapped_protons_min_10Mev;
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
 int nentries = ftree->GetEntriesFast();
 int nentries1 = ftree1->GetEntriesFast();
 int nentries2 = ftree2->GetEntriesFast();
 cout<<"entries2 "<<nentries2<<endl;
 Int_t iold = -1;
 Int_t iold1 = -1;
 Int_t itot = 0;
 Int_t i1 = 0;
 Int_t nevents = 0;
 Int_t nevents1 = 0;

 for ( Int_t i = 0; i < nentries1; i++ )
 {
  ftree1->GetEntry(i);
  enav += energy/nentries1;
//  cout<<"energy "<<energy<<" "<<name1<<endl;
 }
 for ( Int_t i = 0; i < nentries2; i++ )
 {
  ftree2->GetEntry(i);
  d11 += dose1;
  z11 += ziv1;
 }
 cout<<"d11 z11  "<<d11*norm*square*days<<" "<<z11*norm*square*days<<endl;



 for ( Int_t i = 0; i < nentries; i++ )
 {
  ftree->GetEntry(i);
  if ( i%10000 == 0 )
   cout<<"i dose ziv z "<<i<<" "<<dose<<" "<<edep<<" "<<ziv<<" "<<zpos<<" "<<evId<<" "<<name<<" "<<name2<<endl;
  if ( strcmp(name,"LiF" ) == 0 ) { d6 += dose; ed6 += edep; z6 += ziv; }
  if ( strcmp(name,"Eye" ) == 0 ) { d1 += dose; ed1 += edep; z1 += ziv; }
  if ( strcmp(name,"Testis" ) == 0 ) { d2 += dose; ed2 += edep; z2 += ziv; }
  if ( strcmp(name,"Spleen" ) == 0 ) { d3 += dose; ed3 += edep; z3 += ziv; }
  if ( strcmp(name,"Brain" ) == 0 ) { d4 += dose; ed4 += edep; z4 += ziv; }
  if ( strcmp(name,"Stomach" ) == 0 ) { d5 += dose; ed5 += edep; z5 += ziv; }
//  if ( name == "Eye" ) { d1 += dose; ed1 += edep; z1 += ziv; }
//  if ( name == "Testis" ) { d2 += dose; ed2 += edep; z2 += ziv; }
//  if ( name.compare("Spleen") == 0 ) { d3 += dose; ed3 += edep; z3 += ziv; }
//  if ( name.compare("Brain") == 0 ) { d4 += dose; ed4 += edep; z4 += ziv; }
//  if ( name.compare("Stomach") == 0 ) { d5 += dose; ed5 += edep; z5 += ziv; }

  if ( evId != iold && strcmp(name,"Eye" ) == 0 )
//  if ( evId != iold && strcmp(name,"LiF" ) == 0 )
  {
   cout<<"new event "<<evId<<endl;
   nevents++;
//   if ( i1 == 0 ) { hh->Fill(
   iold = evId;
  }
  if ( evId != iold1 && strcmp(name,"Stomach" ) == 0 )
  {
   nevents1++;
   iold1 = evId;
  }
//  enav += en;
//  hh->Fill(zpos,dose/1.);
//  hh1->Fill(zpos,ziv/1.);
 }
 cout<<"events "<<nevents<<endl;
 d1 = d1*norm*square*days;
 d2 = d2*norm*square*days;
 d3 = d3*norm*square*days;
 d4 = d4*norm*square*days;
 d5 = d5*norm*square*days;
 d6 = d6*norm*square*days;
 z1 = z1*norm*square*days;
 z2 = z2*norm*square*days;
 z3 = z3*norm*square*days;
 z4 = z4*norm*square*days;
 z5 = z5*norm*square*days;
 z6 = z6*norm*square*days;
// ed1 = ed1*norm*square*days;
// ed2 = ed2*norm*square*days;
// ed3 = ed3*norm*square*days;
// ed4 = ed4*norm*square*days;
// ed5 = ed5*norm*square*days;
 cout<<"average energy Mev "<<enav<<endl;
 cout<<"doses Gr "<<d1<<" "<<z1<<" "<<d2<<" "<<z2<<" "<<d3<<" "<<z3<<" "<<d4<<" "<<z4<<" "<<d5<<" "<<z5<<" "<<d6<<" "<<z6<<endl;
 cout<<"edep Mev "<<ed1<<" "<<ed2<<" "<<ed3<<" "<<ed4<<" "<<ed5<<" "<<ed6<<endl;
 ofstream *out;
 out = new ofstream("spectrum_GCR_He_min_no_composite_linear.txt", ios::app);
 *out<<d1<<" "<<z1<<" "<<ed1<<" "<<d2<<" "<<z2<<" "<<ed2<<" "<<d3<<" "<<z3<<" "<<ed3<<" "<<d4<<" "<<z4
 <<" "<<ed4<<" "<<d5<<" "<<z5<<" "<<ed5<<" "<<d6<<" "<<z6<<" "<<ed6<<" "<<nevents<<" "<<nevents1<<" "<<w<<" "<<prob<<endl;
 out->close();
 delete out;
 cout<<"w prob "<<w<<" "<<prob<<endl;
}
