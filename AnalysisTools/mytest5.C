void mytest5()
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
 auto h1 = (TH1F*)f->Get("h1");
 auto h2 = (TH1F*)f->Get("h2");
 auto h12 = (TH1F*)f->Get("h12");
 auto h8 = (TH1F*)f->Get("h8");
 auto h13 = (TH1F*)f->Get("h13");
 auto ftree = (TTree*)f->Get("Dose");
 ftree->Print();
 Double_t spectrum_trapped_protons_max  = 1.01461e+08;
 Double_t spectrum_trapped_protons_min  = 2.73898e+08;
 Double_t spectrum_GCR_H_min  = 3.53073e+06;
 Double_t spenvis_trapped_protons_min  = 2.36313e+08;
 Double_t spenvis_trapped_protons_max  = 9.15764e+07;
 Int_t evId;
 Double_t en;
 Double_t edep, zpos, edep1, ziv;
 Double_t sum = 0;
 Double_t sum1 = 0;
 Double_t days = 30.;
// Double_t square = 9.;
 Double_t square = 4.*TMath::Pi()*100.01*100.01;
 ftree->SetBranchAddress("Event",&evId);
 ftree->SetBranchAddress("En",&en);
 ftree->SetBranchAddress("zpos",&zpos);
// ftree->SetBranchAddress("Dose_MeV",&edep);
 ftree->SetBranchAddress("Dose_Gr",&edep1);
 ftree->SetBranchAddress("Dose_Zi",&ziv);

 int nentries = ftree->GetEntriesFast();
 Int_t iold = -1;
 Int_t itot = 0;
 for ( Int_t i = 0; i < nentries; i++ )
 {
  ftree->GetEntry(i);
  if ( evId != iold )
  {
   iold = evId;
   itot++;
  }
//  if ( i%1000000 == 0 )
   cout<<"i dose ziv z ev sum ev tot "<<i<<" "<<edep1<<" "<<ziv<<" "<<zpos<<" "<<evId<<" "<<sum<<" "<<evId<<" "<<itot<<endl;
  sum += edep1;
  sum1 += ziv;
 }
 cout<<"square spectr sum dose "<<square<<" "<<" "<<spectrum_trapped_protons_min<<" "
 <<sum*spectrum_trapped_protons_min*square*days<<endl;
 cout<<"square spectr sum ziv "<<square<<" "<<" "<<spectrum_trapped_protons_min<<" "
 <<sum1*spectrum_trapped_protons_min*square*days<<endl;
 Double_t d1 = sum*spectrum_trapped_protons_min*square*days;
 Double_t z1 = sum1*spectrum_trapped_protons_min*square*days;
 ofstream *out;
// out = new ofstream("spectrum_GCR_H_min_composite_water.txt", ios::app);
 out = new ofstream("spectrum_trapped_protons_min_no_composite_LiF_sphere.txt", ios::app);
// out = new ofstream("spenvis_trapped_protons_min_no_composite_LiF.txt", ios::app);
 *out<<d1<<" "<<z1<<" "<<nentries<<endl;
 out->close();
 delete out;
 sum = 0;
 for ( Int_t i = 0; i <= h13->GetNbinsX(); i++ )
 {
  sum += h13->GetBinContent(i);
  cout<<"i cont sum "<<i<<" "<<h13->GetBinContent(i)<<" "<<sum<<" "<<h13->GetEntries()<<endl;;
 }
}
