void mytest3()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
// c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
// gStyle->SetOptStat(0);
 TString fileName;
 fileName = "../build/output.root";
//  if ( j == 0) fileName = "../build/proton_100MeV_water_only_2000_events.root";
//  if ( j == 1) fileName = "../build/proton_100MeV_water_alu_polyprop_2000_events.root";
//  if ( j == 2) fileName = "../build/proton_100MeV_water_alu_polyprop_comp_2000_events.root";
 cout<<"file "<<fileName<<endl;
 auto hh1 = new TH1F("hh1","",300, 0., 300.);
 auto f = new TFile(fileName);
 auto ftree = (TTree*)f->Get("Energy");
 ftree->Print();
 Double_t en;
 Double_t edep, zpos, step;
 double sum = 0;
 ftree->SetBranchAddress("Energy",&en);
 ftree->SetBranchAddress("zpos",&zpos);
 ftree->SetBranchAddress("Destep",&edep);
 ftree->SetBranchAddress("step",&step);
 int nentries = ftree->GetEntriesFast();
 for ( Int_t i = 0; i < nentries; i++ )
// for ( Int_t i = 0; i < 200000; i++ )
 {
  ftree->GetEntry(i);
  sum += edep; 
  if ( step > 1.e-12 )
   hh1->Fill(zpos,step);
  if ( i%1000000 == 0 )
   cout<<"i edep z step dedx sum "<<i<<" "<<edep<<" "<<zpos<<" "<<step<<" "<<edep/step<<" "<<sum<<endl;
 }
 hh1->Print();
 hh1->Draw("hist");
 TLegend *legend = new TLegend(0.51,0.57,0.60,0.65);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetTextSize(0.035);
// legend->AddEntry(hh,"water only","p");
// legend->AddEntry(hh1,"water+alu+polyprop","p");
// legend->AddEntry("","water+alu+polyprop","");
// legend->AddEntry(hh2,"water+alu+polyprop+shielding(1cm) ","p");
// legend->Draw();
}
