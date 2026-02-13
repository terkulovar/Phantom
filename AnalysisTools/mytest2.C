void mytest2()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
// c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
// gPad->SetLogy();
 gStyle->SetOptStat(0);
 auto gGCRHmin = new TGraph();
 gGCRHmin->SetName("gGCRH");
 gGCRHmin->SetLineColor(2);
 gGCRHmin->SetLineWidth(2);
 auto gGCRHemin = new TGraph();
 gGCRHemin->SetName("gGCRHe");
 gGCRHemin->SetLineColor(1);
 gGCRHemin->SetLineWidth(2);
 auto gGCRLimin = new TGraph();
 gGCRLimin->SetName("gGCRHe");
 gGCRLimin->SetLineColor(7);
 gGCRLimin->SetLineWidth(2);
 auto gGCRHmax = new TGraph();
 gGCRHmax->SetName("gGCRH");
 gGCRHmax->SetLineColor(4);
 gGCRHmax->SetLineWidth(2);
 auto gTRAP_ptoton_min = new TGraph();
 gTRAP_ptoton_min->SetName("gTRAP_ptoton_min");
 gTRAP_ptoton_min->SetLineColor(3);
 gTRAP_ptoton_min->SetLineWidth(2);
 auto gTRAP_electron_min = new TGraph();
 gTRAP_electron_min->SetName("gTRAP_electron_min");
 gTRAP_electron_min->SetLineColor(6);
 gTRAP_electron_min->SetLineWidth(2);
 ifstream *in;
 int ii = 0;
 double en, vHmin, vHemin, vLimin;
 double vTrap_p, vTrap_e;
 double vHmax, vHemax, vLimax;
 in = new ifstream("../data/spectrum_GCR_minimum_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vHmin >> vHemin >> vLimin;
  cout<<"GCR min "<<en<<" "<<vHmin<<" "<<vHemin<<" "<<vLimin<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
//  if ( vHmin > 0)
  gGCRHmin->SetPoint(ii, en, vHmin);
  gGCRHemin->SetPoint(ii, en, vHemin);
  gGCRLimin->SetPoint(ii, en, vLimin);
  ii++;
 }
 in->close();
 delete in;

// ii = 0;
// in = new ifstream("../data/spectrum_GCR_maximum_diff.txt", ios::in);
// while (1)
// {
//  *in >> en >> vHmax >> vHemax >> vLimax;
//  cout<<"GCR minimum "<<en<<" "<<vHmax<<endl;
//  if (!in->good() || in->eof() ) {
//   break;
//  }
//  gGCRHmax->SetPoint(ii, en, vHmax);
//  ii++;
// }
// in->close();
// delete in;

 ii = 0;
// double* xbins;
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
//  xbins[ii]=en;
 }
 in->close();
 delete in;

 ii = 0;
 in = new ifstream("../data/spectrum_trapped_electrons_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vTrap_e;
  cout<<"trapped electrons min "<<en<<" "<<vTrap_e<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vTrap_e > 0)
  gTRAP_electron_min->SetPoint(ii, en, vTrap_e);
   ii++;
 }
 in->close();
 delete in;

// double xbins[29] = {0.1,0.15,0.2,0.3,0.4,0.5,0.6,0.7,1.0,1.5,2.,3.,4.,5.,6.,7.,10.,15.,20.,30.,40.,50.,60.,70., 100.,150.,200.,300.,400.};
// auto hh1 = new TH1F("hh1", "", 29, xbins);
// auto hh1 = new TH1F("hh1", "", 100000, 0.05, 410.);
// cout<<"hh1 bins "<<hh1->GetNbinsX()<<endl;
// auto f = new TFile("../build/output.root");
// auto ftree = (TTree*)f->Get("Event");
// Double_t energy;
// ftree->SetBranchAddress("Energy",&energy);
// int nentries = ftree->GetEntriesFast();
// cout<<"entries "<<nentries<<endl;
// for ( Int_t i = 0; i < nentries; i++ )
// {
//  ftree->GetEntry(i);
//  hh1->Fill(energy);
// }
// hh1->Draw("hist");

 auto mg = new TMultiGraph();
 mg->Add(gGCRHmin);
 mg->Add(gGCRHemin);
 mg->Add(gGCRLimin);
 mg->Add(gTRAP_ptoton_min);
 mg->Add(gTRAP_electron_min);
// mg->Add(gGCRHmax);
// mg->Add(gGCRLi);
 mg->Draw("AL");
 mg->GetXaxis()->SetTitleOffset(1.2);
// mg->GetYaxis()->SetTitleOffset(1.4);
// mg->GetXaxis()->SetRangeUser(0.3, 10e5);
 cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<endl;
 mg->GetHistogram()->SetBins(10000000, 0.04, 1.5e5);
 cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<" "<<mg->GetHistogram()->GetNbinsY()<<endl;
// mg->GetYaxis()->SetRangeUser(1., 6.1e7);
 mg->GetYaxis()->SetRangeUser(1.e-7, 4.5e10);
 mg->GetYaxis()->SetLabelSize(0.035);
 mg->GetXaxis()->SetLabelSize(0.035);
 mg->GetYaxis()->SetTitleSize(0.035);
 mg->GetXaxis()->SetTitleSize(0.035);
 mg->GetHistogram()->SetXTitle("E[MeV]");
 mg->GetHistogram()->SetYTitle("differential flux[cm^{-2}(MeV/nucleon)^{-1}day^{-1}]");
 mg->GetHistogram()->SetTitle("minimum sun activity");
 TLegend *legend = new TLegend(0.6,0.5,0.9,0.7);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetTextSize(0.035);
//   legend->AddEntry(gr18,"ieta=18","p");
 legend->AddEntry(gGCRHmin,"GCR protons ","l");
 legend->AddEntry(gGCRHemin,"GCR He ions ","l");
 legend->AddEntry(gGCRLimin,"GCR Li ions ","l");
// legend->AddEntry(gGCRHmax,"GCR protons maximum sun activity","l");
 legend->AddEntry(gTRAP_ptoton_min,"trapped protons ","l");
 legend->AddEntry(gTRAP_electron_min,"trapped electrons","l");
 legend->Draw();

}
