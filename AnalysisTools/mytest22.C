void mytest22()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
 c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
// gPad->SetLogy();
 gStyle->SetOptStat(0);

 auto gGCRHmin = new TGraph();
 gGCRHmin->SetName("gGCRH");
 gGCRHmin->SetLineColor(2);
 gGCRHmin->SetLineWidth(3);
 auto gGCRHemin = new TGraph();
 gGCRHemin->SetName("gGCRHe");
 gGCRHemin->SetLineColor(7);
 gGCRHemin->SetLineWidth(3);
 auto gGCRCmin = new TGraph();
 gGCRCmin->SetName("gGCRC");
 gGCRCmin->SetLineColor(1);
 gGCRCmin->SetLineWidth(3);
 auto gGCROmin = new TGraph();
 gGCROmin->SetName("gGCRO");
 gGCROmin->SetLineColor(6);
 gGCROmin->SetLineWidth(3);
 auto gGCRFemin = new TGraph();
 gGCRFemin->SetName("gGCRO");
 gGCRFemin->SetLineColor(8);
 gGCRFemin->SetLineWidth(3);

 auto gTRAP_ptoton_min = new TGraph();
 gTRAP_ptoton_min->SetName("gTRAP_ptoton_min");
 gTRAP_ptoton_min->SetLineColor(4);
 gTRAP_ptoton_min->SetLineWidth(3);
 auto gTRAP_electron_min = new TGraph();
 gTRAP_electron_min->SetName("gTRAP_electron_min");
 gTRAP_electron_min->SetLineColor(8);
 gTRAP_electron_min->SetLineWidth(3);

 ifstream *in;
 int ii = 0;
 double en, vHmin, vHemin, vCmin, vOmin, vFemin;
 double vTrap_p, vTrap_e;
 double vHmax, vHemax, vLimax;
 double shift = 1.44E+04;

 in = new ifstream("../data/spectrum_trapped_electrons_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vTrap_e;
  cout<<"trapped electrons min "<<en<<" "<<vTrap_e<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vTrap_e > 0 )
   gTRAP_electron_min->SetPoint(ii, en, vTrap_e);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spectrum_trapped_protons_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vTrap_p;
  cout<<"trapped protons min "<<en<<" "<<vTrap_p<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vTrap_p > 0 )
   gTRAP_ptoton_min->SetPoint(ii, en, vTrap_p);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spectrum_GCR_minimum_H_diff.txt", ios::in);
 while (1)
 {
//  *in >> en >> vHmin >> vHemin >> vLimin;
  *in >> en >> vHmin;
  cout<<"GCR H min "<<en<<" "<<vHmin<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vHmin > 0 )
   gGCRHmin->SetPoint(ii, en, vHmin);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spectrum_GCR_minimum_He_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vHemin;
  cout<<"GCR He min "<<en<<" "<<vHemin<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vHemin > 0 )
   gGCRHemin->SetPoint(ii, en, vHemin);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spectrum_GCR_minimum_C_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vCmin;
  cout<<"GCR C min "<<en<<" "<<vCmin<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vCmin > 0 )
   gGCRCmin->SetPoint(ii, en, vCmin);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spectrum_GCR_minimum_O_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vOmin;
  cout<<"GCR O max "<<en<<" "<<vOmin<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vOmin > 0 )
   gGCROmin->SetPoint(ii, en, vOmin);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spectrum_GCR_minimum_Fe_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vFemin;
  cout<<"GCR Fe max "<<en<<" "<<vFemin<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vFemin > 0 )
   gGCRFemin->SetPoint(ii, en, vFemin);
  ii++;
 }
 in->close();
 delete in;

// return;
 double xbins[30] = {0.1,0.15,0.2,0.3,0.4,0.5,0.6,0.7,1.0,1.5,2.,3.,4.,5.,6.,7.,10.,15.,20.,30.,40.,50.,60.,70., 100.,150.,200.,300.,400.,410.};
 auto hh2 = new TH1F("hh2", "", 29, xbins);
// auto hh2 = new TH1F("hh2", "", 100000, 0.09, 410.);
 ii = 0;
// double* xbins;
// in = new ifstream("../data/spectrum_trapped_protons_min_diff.txt", ios::in);
// in = new ifstream("../data/spenvis_trapped_protons_2010_368km_52degree_min_integral.txt", ios::in);
// while (1)
// {
//  *in >> en >> vTrap_p;
//  cout<<"trapped protons min "<<en<<" "<<vTrap_p<<endl;
//  if (!in->good() || in->eof() ) {
//   break;
//  }
//  if ( vTrap_p > 0)
//   gTRAP_ptoton_min->SetPoint(ii, en, vTrap_p);
//  hh2->Fill(en,vTrap_p);
//  ii++;
//  xbins[ii]=en;
// }
// in->close();
// delete in;

 ii = 0;
// in = new ifstream("../data/spectrum_trapped_electrons_min_diff.txt", ios::in);
 in = new ifstream("../data/spenvis_trapped_electrons_2010_368km_min_integral.txt", ios::in);
 while (1)
 {
  *in >> en >> vTrap_e;
  cout<<"trapped electrons min "<<en<<" "<<vTrap_e<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vTrap_e > 0 )
   gTRAP_electron_min->SetPoint(ii, en, vTrap_e);
   ii++;
 }
 in->close();
 delete in;

 Double_t spectrum_trapped_protons_min  = 6.6e+06;
 auto hh1 = new TH1F("hh1", "", 100000, 0.09, 410.);
 hh1->SetLineColor(2);
 hh1->SetLineWidth(2);
// hh1->SetTitle("minimum sun activity");
 hh1->SetXTitle("E[MeV]");
// hh1->SetYTitle("differential flux[cm^{-2}MeV^{-1}day^{-1}]");
 hh1->SetYTitle("Sp (cm^{-2}MeV^{-1}day^{-1})");
 cout<<"hh1 bins "<<hh1->GetNbinsX()<<endl;
// auto f = new TFile("../build/output.root");
// auto ftree = (TTree*)f->Get("Event");
// Double_t energy;
// ftree->SetBranchAddress("Energy",&energy);
// int nentries = ftree->GetEntriesFast();
// cout<<"entries "<<nentries<<endl;
// for ( Int_t i = 0; i < nentries; i++ )
// {
//  ftree->GetEntry(i);
//  hh1->Fill(energy,1.);
// }
// hh1->Scale(spectrum_trapped_protons_min/6000./4.);
// hh1->Scale(1.87e8*70./60000000.);
// for ( Int_t i = 1; i <= hh1->GetNbinsX(); i++ )
// {
//  double tt = hh1->GetBinContent(i);
//  shift = 0;
//  hh1->SetBinContent(i,(tt+shift));
// }

// hh1->Draw("hist");

 auto mg = new TMultiGraph();
 mg->Add(gGCRHmin);
 mg->Add(gGCRHemin);
 mg->Add(gGCRCmin);
 mg->Add(gGCROmin);
 mg->Add(gGCRFemin);
 mg->Add(gTRAP_ptoton_min);
// mg->Add(gTRAP_electron_min);
// mg->Add(gGCRHmax);
// mg->Add(gGCRLi);
// hh1->Draw("HIST SAME");
// mg->Draw("AL");
 mg->Draw("APL");
// hh2->Draw("LP");
// mg->GetHistogram()->Draw("histsame");
 mg->GetXaxis()->SetTitleOffset(1.2);
 mg->GetYaxis()->SetTitleOffset(1.4);
// mg->GetXaxis()->SetRangeUser(0.03, 1.02e5);
// cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<endl;
// mg->GetHistogram()->SetBins(10000000, 0.03, 1.1e5);
 mg->GetHistogram()->SetBins(10000000, 0.07, 1.1e5);
// cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<" "<<mg->GetHistogram()->GetNbinsY()<<endl;
// mg->GetYaxis()->SetRangeUser(1.e-6, 4.1e10);
 mg->GetYaxis()->SetRangeUser(1.e-6, 8.e8);
// mg->GetYaxis()->SetRangeUser(1., 4.1e9);
 mg->GetYaxis()->SetLabelSize(0.035);
 mg->GetXaxis()->SetLabelSize(0.035);
 mg->GetYaxis()->SetTitleSize(0.035);
 mg->GetXaxis()->SetTitleSize(0.035);
 mg->GetHistogram()->SetXTitle("#frac{E}{n} (MeV)");
// mg->GetHistogram()->SetXTitle("E");
// mg->GetHistogram()->SetYTitle("integral flux[cm^{-2}day^{-1}]");
// mg->GetHistogram()->SetYTitle("differential flux (cm^{-2}MeV^{-1}day^{-1})");
 mg->GetHistogram()->SetYTitle("#frac{d#Phi}{dEdt} (cm^{-2}MeV^{-1}day^{-1})");
// mg->GetHistogram()->SetTitle("minimum sun activity");
 cout<<"mg entries "<<mg->GetHistogram()->GetEntries()<<endl;
 TLegend *legend = new TLegend(0.5,0.5,0.65,0.76);
 legend->SetFillColor(0);
// legend->SetBorderSize(0);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetTextSize(0.035);
// legend->AddEntry(gr18,"ieta=18","p");
// legend->AddEntry(gGCRHmax,"GCR protons maximum sun activity","l");
// legend->AddEntry(gTRAP_ptoton_min,"trapped protons","l");
// legend->AddEntry(hh1,"trapped protons generated","l");
// legend->AddEntry(gTRAP_electron_min,"trapped electrons","l");
// legend->AddEntry(gGCRHmin,"GCR protons","l");
// legend->AddEntry(gGCRHemin,"GCR He","l");
// legend->AddEntry(gGCRCmin,"GCR C","l");
// legend->AddEntry(gGCROmin,"GCR O","l");
 legend->AddEntry(gTRAP_ptoton_min,"","l");
// legend->AddEntry(gTRAP_electron_min,"","l");
 legend->AddEntry(gGCRHmin,"","l");
 legend->AddEntry(gGCRHemin,"","l");
 legend->AddEntry(gGCRCmin,"","l");
 legend->AddEntry(gGCROmin,"","l");
 legend->AddEntry(gGCRFemin,"","l");
 legend->Draw();

}
