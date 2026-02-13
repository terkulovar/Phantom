void tt()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
// c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
 gStyle->SetOptStat(0);
 auto f = new TFile("../build/output.root");
// auto f = new TFile("../build/proton_62Mev_in_water.root");
 auto ftree = (TTree*)f->Get("Event");
 Double_t X, Y, Z;
// ftree->SetBranchAddress("X_pos",&X);
 ftree->Draw("X_dir>>hh1");
 ftree->Draw("Y_dir>>hh2");
 ftree->Draw("Z_dir>>hh3");
 TH1F *hh1 = (TH1F*)gROOT->FindObject("hh1");
 if ( hh1 )
 {
  cout<<"found hh1 "<<endl;
  hh1->SetTitle("particle direction uniformly distributed from Geant4");
//    h1->SetTitleSize(0.5);
  hh1->SetLineColor(2);
  hh1->SetLineWidth(2);
 }
 TH1F *hh2 = (TH1F*)gROOT->FindObject("hh2");
 if ( hh2 )
 {
  cout<<"found hh2 "<<endl;
  hh2->SetTitle("particle direction uniformly distributed from Geant4");
//    h1->SetTitleSize(0.5);
  hh2->SetLineColor(4);
  hh2->SetLineWidth(2);
 }
 TH1F *hh3 = (TH1F*)gROOT->FindObject("hh3");
 if ( hh3 )
 {
  cout<<"found hh3 "<<endl;
  hh3->SetTitle("particle direction uniformly distributed from Geant4");
//    h1->SetTitleSize(0.5);
  hh3->SetLineColor(6);
  hh3->SetLineWidth(2);
 }
 hh3->Draw("hist");
 hh2->Draw("histsame");
 hh1->Draw("histsame");
 TLegend *legend = new TLegend(0.2,0.2,0.3,0.4);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetTextSize(0.045);
 legend->AddEntry(hh1,"x component distribution","l");
 legend->AddEntry(hh2,"y component distribution","l");
 legend->AddEntry(hh3,"z component distribution","l");
 legend->Draw();
}
