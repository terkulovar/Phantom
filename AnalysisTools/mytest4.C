void mytest4()
{
 Double_t pi = acos(0.0)*2.0;
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
// c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
 gStyle->SetOptStat(0);
 auto hh = new TH1F("hh","",30,0,15);
 hh->SetMarkerStyle(20);
 hh->SetMarkerSize(0.8);
 hh->SetMarkerColor(2);
 hh->SetXTitle("distance [cm]");
 hh->SetYTitle("dE [MeV]");
 hh->SetTitle("water, spectrum of protons");
 auto hh1 = new TH1F("hh1","",30,0,15);
 hh1->SetMarkerStyle(20);
 hh1->SetMarkerSize(0.8);
 hh1->SetMarkerColor(4);
 hh1->SetXTitle("distance [cm]");
 hh1->SetYTitle("dE [MeV]");
 cout<<"hh bins width center "<<hh->GetNbinsX()<<" "<<hh->GetBinWidth(1)<<" "<<hh->GetBinCenter(1)<<endl;
 auto f = new TFile("../build/output.root");
 auto ftree = (TTree*)f->Get("Dose");
 ftree->Print();
 Int_t evId;
 Double_t en;
 Double_t edep, zpos, edep1, ziv;
 Double_t mass = 2.*2.*0.5/1000.;
 Double_t spectrum_trapped_protons_max  = 1.01461e+08;
 Double_t spectrum_trapped_protons_min  = 2.73898e+08;
 Double_t spectrum_GCR_H_min  = 3.53073e+06;
 Double_t spenvis_trapped_protons_min  = 2.36313e+08;
 Double_t spenvis_trapped_protons_max  = 9.15764e+07;
 ftree->SetBranchAddress("Event",&evId);
 ftree->SetBranchAddress("En",&en);
 ftree->SetBranchAddress("zpos",&zpos);
 ftree->SetBranchAddress("Dose_MeV",&edep);
 ftree->SetBranchAddress("Dose_Gr",&edep1);
 ftree->SetBranchAddress("Dose_Zi",&ziv);
 int nentries = ftree->GetEntriesFast();
 for ( Int_t i = 0; i < nentries; i++ )
 {
  ftree->GetEntry(i);
  if ( i%1000000 == 0 )
   cout<<"i dose ziv z "<<i<<" "<<edep1<<" "<<ziv<<" "<<zpos<<" "<<evId<<endl;
  hh->Fill(zpos,edep1/1.);
  hh1->Fill(zpos,ziv/1.);
 }
 hh->Draw("e1p");
// TLegend *legend = new TLegend(0.51,0.57,0.60,0.65);
// legend->SetFillColor(0);
// legend->SetBorderSize(0);
// legend->SetLineStyle(1);
// legend->SetLineWidth(1);
// legend->SetTextSize(0.035);
// legend->AddEntry(hh,"no shielding","p");
// legend->AddEntry(hh1,"shielding 1cm","p");
// legend->Draw();
 Double_t d1, d2, d3, d4, d5;
 Double_t z1, z2, z3, z4, z5;
 Double_t sum = 0;
 Double_t days = 1.;
// Double_t square = 9.;
// Double_t square = 4.0*pi*20.1*20.1;
 Double_t square = 9.;
 for ( Int_t i = 0; i < hh->GetNbinsX(); i++ )
 {
  sum += hh->GetBinContent(i);
/*
  if ( i == 1 ) 
  {
   d1 = hh->GetBinContent(i)*spectrum_GCR_H_min*square*days;
   z1 = hh1->GetBinContent(i)*spectrum_GCR_H_min*square*days;
  }
  if ( i == 5 ) 
  {
   d2 = hh->GetBinContent(i)*spectrum_GCR_H_min*square*days;
   z2 = hh1->GetBinContent(i)*spectrum_GCR_H_min*square*days;
  }
  if ( i == 11 ) 
  {
   d3 = hh->GetBinContent(i)*spectrum_GCR_H_min*square*days;
   z3 = hh1->GetBinContent(i)*spectrum_GCR_H_min*square*days;
  }
  if ( i == 15 ) 
  {
   d4 = hh->GetBinContent(i)*spectrum_GCR_H_min*square*days;
   z4 = hh1->GetBinContent(i)*spectrum_GCR_H_min*square*days;
  }
  if ( i == 19 ) 
  {
   d5 = hh->GetBinContent(i)*spectrum_GCR_H_min*square*days;
   z5 = hh1->GetBinContent(i)*spectrum_GCR_H_min*square*days;
  }
*/

  if ( i == 1 ) 
  {
   d1 = hh->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
   z1 = hh1->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
  }
  if ( i == 5 ) 
  {
   d2 = hh->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
   z2 = hh1->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
  }
  if ( i == 11 ) 
  {
   d3 = hh->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
   z3 = hh1->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
  }
  if ( i == 15 ) 
  {
   d4 = hh->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
   z4 = hh1->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
  }
  if ( i == 19 ) 
  {
   d5 = hh->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
   z5 = hh1->GetBinContent(i)*spectrum_trapped_protons_min*square*days;
  }

/*
  if ( i == 1 ) 
  {
   d1 = hh->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
   z1 = hh1->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
  }
  if ( i == 5 ) 
  {
   d2 = hh->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
   z2 = hh1->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
  }
  if ( i == 11 ) 
  {
   d3 = hh->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
   z3 = hh1->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
  }
  if ( i == 15 ) 
  {
   d4 = hh->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
   z4 = hh1->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
  }
  if ( i == 19 ) 
  {
   d5 = hh->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
   z5 = hh1->GetBinContent(i)*spenvis_trapped_protons_min*square*days;
  }
*/
//  if ( hh->GetBinContent(i) > 0 ) cout<<"i bin "<<i<<" "<<hh->GetBinContent(i)*spectrum_GCR_H_min*square*days <<" "<<hh->GetBinCenter(i)<<endl;
//  if ( hh1->GetBinContent(i) > 0 ) cout<<"hh1 i bin "<<i<<" "<<hh1->GetBinContent(i)*spectrum_GCR_H_min*square*days <<" "<<hh1->GetBinCenter(i)<<endl;
  if ( hh->GetBinContent(i) > 0 ) cout<<"i bin "<<i<<" "<<hh->GetBinContent(i)*spectrum_trapped_protons_min*square*days <<" "<<hh->GetBinCenter(i)<<endl;
  if ( hh1->GetBinContent(i) > 0 ) cout<<"hh1 i bin "<<i<<" "<<hh1->GetBinContent(i)*spectrum_trapped_protons_min*square*days <<" "<<hh1->GetBinCenter(i)<<endl;
//  if ( hh->GetBinContent(i) > 0 ) cout<<"hh i bin "<<i<<" "<<hh->GetBinContent(i)*spenvis_trapped_protons_min*square*days <<" "<<hh->GetBinCenter(i)<<endl;
//  if ( hh1->GetBinContent(i) > 0 ) cout<<"hh1 i bin "<<i<<" "<<hh1->GetBinContent(i)*spenvis_trapped_protons_min*square*days <<" "<<hh1->GetBinCenter(i)<<endl;
 }
 cout<<"sum mass "<<sum<<" "<<mass<<endl;
 ofstream *out;
// out = new ofstream("spectrum_GCR_H_min_composite_water.txt", ios::app);
 out = new ofstream("spectrum_trapped_protons_min_composite_water_sphere.txt", ios::app);
// out = new ofstream("spenvis_trapped_protons_min_no_composite_LiF.txt", ios::app);
 *out<<d1<<" "<<z1<<" "<<d2<<" "<<z2<<" "<<d3<<" "<<z3<<" "<<d4<<" "<<z4<<" "<<d5<<" "<<z5<<endl;
 out->close();
 delete out;

}
