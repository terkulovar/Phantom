void mytest1()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
 c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
 gStyle->SetOptStat(0);
 auto gGCRH = new TGraph();
 gGCRH->SetName("gGCRH");
 gGCRH->SetLineColor(2);
 gGCRH->SetLineWidth(2);
 auto gGCRHe = new TGraph();
 gGCRHe->SetName("gGCRHe");
 gGCRHe->SetLineColor(4);
 gGCRHe->SetLineWidth(2);
 auto gGCRLi = new TGraph();
 gGCRLi->SetName("gGCRHe");
 gGCRLi->SetLineColor(6);
 gGCRLi->SetLineWidth(2);
 ifstream *in;
 int ii = 0;
 double en, vH, vHe, vLi;
 in = new ifstream("../data/spectrum_GCR_minimum.txt", ios::in);
 while (1)
 {
  *in >> en >> vH >> vHe >> vLi;
  cout<<en<<" "<<vH<<" "<<vHe<<" "<<vLi<<endl;
  if (!in->good() || in->eof() ) {
   break;
 }
 gGCRH->SetPoint(ii, en, vH);
 gGCRHe->SetPoint(ii, en, vHe);
 gGCRLi->SetPoint(ii, en, vLi);
 ii++;
 }
 in->close();
 delete in;
 auto mg = new TMultiGraph();
 mg->Add(gGCRH);
 mg->Add(gGCRHe);
 mg->Add(gGCRLi);
 mg->Draw("AL");
 mg->GetHistogram()->SetBins(1000000, 0.1, 2e5);
 cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<" "<<mg->GetHistogram()->GetNbinsY()<<endl;
 mg->GetYaxis()->SetRangeUser(0.001, 70000.);
 mg->GetXaxis()->SetTitleOffset(1.2);
 mg->GetYaxis()->SetLabelSize(0.035);
 mg->GetXaxis()->SetLabelSize(0.035);
 mg->GetYaxis()->SetTitleSize(0.035);
 mg->GetXaxis()->SetTitleSize(0.035);
 mg->GetHistogram()->SetXTitle("E[MeV]");
 mg->GetHistogram()->SetYTitle("integral flux[cm^{-2}day^{-1}");
 TLegend *legend = new TLegend(0.6,0.5,0.9,0.65);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetTextSize(0.035);
//   legend->AddEntry(gr18,"ieta=18","p");
 legend->AddEntry(gGCRH,"GCR protons minimum sun activity","l");
 legend->AddEntry(gGCRHe,"GCR He minimum sun activity","l");
 legend->AddEntry(gGCRLi,"GCR Li minimum sun activity","l");
 legend->Draw();

}
