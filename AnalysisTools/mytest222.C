void mytest222()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
 c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
// gPad->SetLogy();
 gStyle->SetOptStat(0);
 auto gTRAP_ptoton_old_min = new TGraph();
 gTRAP_ptoton_old_min->SetName("gTRAP_ptoton_old_min");
 gTRAP_ptoton_old_min->SetLineColor(4);
 gTRAP_ptoton_old_min->SetLineWidth(2);
 auto gTRAP_ptoton_new_min = new TGraph();
 gTRAP_ptoton_new_min->SetName("gTRAP_ptoton_new_min");
 gTRAP_ptoton_new_min->SetLineColor(2);
 gTRAP_ptoton_new_min->SetLineWidth(2);
 ifstream *in;
 int ii = 0;
 double en, vHmin, vHemin, vLimin;
 double vTrap_old_p, vTrap_new_p;

 in = new ifstream("../data/spectrum_trapped_protons_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vTrap_old_p;
  cout<<"trapped protons old min "<<en<<" "<<vTrap_old_p<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vTrap_old_p > 0)
   gTRAP_ptoton_old_min->SetPoint(ii, en, vTrap_old_p);
  ii++;
 }
 in->close();
 delete in;
// return;
 ii = 0;
 in = new ifstream("../data/spenvis_trapped_protons_2010_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vTrap_new_p;
  cout<<"trapped protons new  min "<<en<<" "<<vTrap_new_p<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vTrap_new_p > 0 )
   gTRAP_ptoton_new_min->SetPoint(ii, en, vTrap_new_p);
   ii++;
 }
 in->close();
 delete in;


 auto mg = new TMultiGraph();
// mg->Add(gGCRHmin);
 mg->Add(gTRAP_ptoton_old_min);
 mg->Add(gTRAP_ptoton_new_min);
// mg->Add(gGCRHmax);
// mg->Add(gGCRLi);
// hh1->Draw("HIST SAME");
// mg->Draw("AL");
 mg->Draw("APL");
// hh2->Draw("LP");
// mg->GetHistogram()->Draw("histsame");
 mg->GetXaxis()->SetTitleOffset(1.2);
 mg->GetYaxis()->SetTitleOffset(1.4);
// mg->GetXaxis()->SetRangeUser(0.09, 410.);
// cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<endl;
 mg->GetHistogram()->SetBins(10000000, 0.09, 410.);
// cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<" "<<mg->GetHistogram()->GetNbinsY()<<endl;
 mg->GetYaxis()->SetRangeUser(100., 2.2e8);
// mg->GetYaxis()->SetRangeUser(1., 4.1e9);
 mg->GetYaxis()->SetLabelSize(0.035);
 mg->GetXaxis()->SetLabelSize(0.035);
 mg->GetYaxis()->SetTitleSize(0.035);
 mg->GetXaxis()->SetTitleSize(0.035);
 mg->GetHistogram()->SetXTitle("E[MeV]");
 mg->GetHistogram()->SetYTitle("differential flux[cm^{-2}MeV^{-1}day^{-1}]");
// mg->GetHistogram()->SetYTitle("integral flux[cm^{-2}day^{-1}]");
 mg->GetHistogram()->SetTitle("minimum sun activity");
 cout<<"mg entries "<<mg->GetHistogram()->GetEntries()<<endl;
 TLegend *legend = new TLegend(0.5,0.5,0.95,0.6);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetTextSize(0.035);
 legend->AddEntry(gTRAP_ptoton_old_min,"trapped protons from IMBP","l");
// legend->AddEntry(hh1,"trapped protons generated","l");
 legend->AddEntry(gTRAP_ptoton_new_min,"trapped protons spenvis","l");
 legend->Draw();

}
