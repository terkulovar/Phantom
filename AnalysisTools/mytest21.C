void mytest21()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
 c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
// gPad->SetLogy();
 gStyle->SetOptStat(0);

 auto gGCRHmin52 = new TGraph();
 gGCRHmin52->SetName("gGCRH52");
 gGCRHmin52->SetLineColor(2);
 gGCRHmin52->SetLineWidth(3);
 auto gGCRHmin98 = new TGraph();
 gGCRHmin98->SetName("gGCRH98");
 gGCRHmin98->SetLineColor(4);
 gGCRHmin98->SetLineWidth(3);

 auto gGCRHemin52 = new TGraph();
 gGCRHemin52->SetName("gGCRHe52");
 gGCRHemin52->SetLineColor(2);
 gGCRHemin52->SetLineWidth(3);
 auto gGCRHemin98 = new TGraph();
 gGCRHemin98->SetName("gGCRHe98");
 gGCRHemin98->SetLineColor(4);
 gGCRHemin98->SetLineWidth(3);

 auto gGCRCmin52 = new TGraph();
 gGCRCmin52->SetName("gGCRC52");
 gGCRCmin52->SetLineColor(2);
 gGCRCmin52->SetLineWidth(3);
 auto gGCRCmin98 = new TGraph();
 gGCRCmin98->SetName("gGCRC98");
 gGCRCmin98->SetLineColor(4);
 gGCRCmin98->SetLineWidth(3);

 auto gGCROmin52 = new TGraph();
 gGCROmin52->SetName("gGCRO52");
 gGCROmin52->SetLineColor(2);
 gGCROmin52->SetLineWidth(3);
 auto gGCROmin98 = new TGraph();
 gGCROmin98->SetName("gGCRO98");
 gGCROmin98->SetLineColor(4);
 gGCROmin98->SetLineWidth(3);

 auto gGCRFemin52 = new TGraph();
 gGCRFemin52->SetName("gGCRO52");
 gGCRFemin52->SetLineColor(2);
 gGCRFemin52->SetLineWidth(3);
 auto gGCRFemin98 = new TGraph();
 gGCRFemin98->SetName("gGCRO98");
 gGCRFemin98->SetLineColor(4);
 gGCRFemin98->SetLineWidth(3);

 auto gTRAP_ptoton52_min = new TGraph();
 gTRAP_ptoton52_min->SetName("gTRAP_ptoton_min");
 gTRAP_ptoton52_min->SetLineColor(4);
 gTRAP_ptoton52_min->SetLineWidth(3);

 auto gTRAP_proton98_min = new TGraph();
 gTRAP_proton98_min->SetName("gTRAP_electron_min");
 gTRAP_proton98_min->SetLineColor(2);
 gTRAP_proton98_min->SetLineWidth(3);

 ifstream *in;
 int ii = 0;
 double en, vHmin52, vHmin98, vHemin52, vHemin98, vCmin52, vCmin98,  vOmin52, vOmin98, vFemin52, vFemin98;
 double vTrap_p, vTrap_p1;
 double vHmax, vHemax, vLimax;
 double shift = 1.44E+04;

 in = new ifstream("../data/spenvis_trapped_protons_2010_350km_51.6degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vTrap_p;
  cout<<"trapped protons 51.6 min "<<en<<" "<<vTrap_p<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vTrap_p > 0 )
   gTRAP_ptoton52_min->SetPoint(ii, en, vTrap_p);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spenvis_trapped_protons_2010_350km_98degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vTrap_p1;
  cout<<"trapped protons 98 min "<<en<<" "<<vTrap_p1<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vTrap_p1 > 0 )
   gTRAP_proton98_min->SetPoint(ii, en, vTrap_p1);
  ii++;
 }
 in->close();
 delete in;

 ii = 0;
 in = new ifstream("../data/spenvis_GCR_H_2010_350km_51.6degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vHmin52;
  cout<<"H 52 min "<<en<<" "<<vHmin52<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vHmin52 > 0 )
   gGCRHmin52->SetPoint(ii, en, vHmin52);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spenvis_GCR_H_2010_350km_98degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vHmin98;
  cout<<"H 98 min "<<en<<" "<<vHmin98<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vHmin98 > 0 )
   gGCRHmin98->SetPoint(ii, en, vHmin98);
  ii++;
 }
 in->close();
 delete in;

 ii = 0;
 in = new ifstream("../data/spenvis_GCR_He_2010_350km_51.6degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vHemin52;
  cout<<"He 52 min "<<en<<" "<<vHemin52<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vHemin52 > 0 )
   gGCRHemin52->SetPoint(ii, en, vHemin52);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spenvis_GCR_He_2010_350km_98degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vHemin98;
  cout<<"He 98 min "<<en<<" "<<vHemin98<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vHemin98 > 0 )
   gGCRHemin98->SetPoint(ii, en, vHemin98);
  ii++;
 }
 in->close();
 delete in;

 ii = 0;
 in = new ifstream("../data/spenvis_GCR_C_2010_350km_51.6degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vCmin52;
  cout<<"C 52 min "<<en<<" "<<vCmin52<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vCmin52 > 0 )
   gGCRCmin52->SetPoint(ii, en, vCmin52);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spenvis_GCR_C_2010_350km_98degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vCmin98;
  cout<<"C 98 min "<<en<<" "<<vCmin98<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vCmin98 > 0 )
   gGCRCmin98->SetPoint(ii, en, vCmin98);
  ii++;
 }
 in->close();
 delete in;

 ii = 0;
 in = new ifstream("../data/spenvis_GCR_O_2010_350km_51.6degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vOmin52;
  cout<<"O 52 min "<<en<<" "<<vOmin52<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vOmin52 > 0 )
   gGCROmin52->SetPoint(ii, en, vOmin52);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spenvis_GCR_O_2010_350km_98degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vOmin98;
  cout<<"O 98 min "<<en<<" "<<vOmin98<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vOmin98 > 0 )
   gGCROmin98->SetPoint(ii, en, vOmin98);
  ii++;
 }
 in->close();
 delete in;

 ii = 0;
 in = new ifstream("../data/spenvis_GCR_Fe_2010_350km_51.6degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vFemin52;
  cout<<"Fe 52 min "<<en<<" "<<vFemin52<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vFemin52 > 0 )
   gGCRFemin52->SetPoint(ii, en, vFemin52);
  ii++;
 }
 in->close();
 delete in;
 ii = 0;
 in = new ifstream("../data/spenvis_GCR_Fe_2010_350km_98degree_min_diff.txt", ios::in);
 while (1)
 {
  *in >> en >> vFemin98;
  cout<<"Fe 98 min "<<en<<" "<<vFemin98<<endl;
  if (!in->good() || in->eof() ) {
   break;
  }
  if ( vFemin98 > 0 )
   gGCRFemin98->SetPoint(ii, en, vFemin98);
  ii++;
 }
 in->close();
 delete in;


 auto mg = new TMultiGraph();
// mg->Add(gGCRHmin52);
// mg->Add(gGCRHmin98);
// mg->Add(gGCRHemin52);
// mg->Add(gGCRHemin98);
// mg->Add(gGCRCmin52);
// mg->Add(gGCRCmin98);
// mg->Add(gGCROmin52);
// mg->Add(gGCROmin98);
 mg->Add(gGCRFemin52);
 mg->Add(gGCRFemin98);
// mg->Add(gGCRHemin);
// mg->Add(gGCRCmin);
// mg->Add(gGCROmin);
// mg->Add(gGCRFemin);
// mg->Add(gTRAP_ptoton52_min);
// mg->Add(gTRAP_proton98_min);
// mg->Add(gTRAP_electron_min);
// mg->Add(gGCRHmax);
// mg->Add(gGCRLi);
// hh1->Draw("HIST SAME");
// mg->Draw("AL");
 mg->Draw("APL");
// hh2->Draw("LP");
// mg->GetHistogram()->Draw("histsame");
 mg->GetXaxis()->SetTitleOffset(1.2);
 mg->GetYaxis()->SetTitleOffset(1.5);
// mg->GetXaxis()->SetRangeUser(0.03, 1.02e5);
// cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<endl;
// mg->GetHistogram()->SetBins(10000000, 0.03, 1.1e5);
 mg->GetHistogram()->SetBins(10000000, 0.07, 1.1e5);
// cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<" "<<mg->GetHistogram()->GetNbinsY()<<endl;
// mg->GetYaxis()->SetRangeUser(1.e-6, 4.1e10);
 mg->GetYaxis()->SetRangeUser(1.e-13, 1.e-7);
// mg->GetYaxis()->SetRangeUser(1., 4.1e9);
 mg->GetYaxis()->SetLabelSize(0.035);
 mg->GetXaxis()->SetLabelSize(0.035);
 mg->GetYaxis()->SetTitleSize(0.035);
 mg->GetXaxis()->SetTitleSize(0.035);
 mg->GetHistogram()->SetXTitle("#frac{E}{n} (MeV)");
// mg->GetHistogram()->SetXTitle("E (MeV)");
// mg->GetHistogram()->SetYTitle("integral flux[cm^{-2}day^{-1}]");
// mg->GetHistogram()->SetYTitle("differential flux (cm^{-2}MeV^{-1}day^{-1})");
 mg->GetHistogram()->SetYTitle("#frac{d#Phi}{dEdt} (cm^{-2}MeV^{-1}s^{-1})");
// mg->GetHistogram()->SetTitle("minimum sun activity");
 cout<<"mg entries "<<mg->GetHistogram()->GetEntries()<<endl;
 TLegend *legend = new TLegend(0.5,0.5,0.85,0.76);
 legend->SetFillColor(0);
// legend->SetBorderSize(0);
 legend->SetLineStyle(1);
 legend->SetLineWidth(0);
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
 legend->AddEntry(gGCRHmin52,"GCR Fe h=350km 51.6^{0}","l");
 legend->AddEntry((TObject*)0,"Integral=5.46611e-05","");
 legend->AddEntry(gGCRHmin98,"GCR Fe h=350km 98^{0} ","l");
 legend->AddEntry((TObject*)0,"Integral=8.77806e-05","");
// legend->AddEntry(gTRAP_electron_min,"","l");
// legend->AddEntry(gGCRHmin,"","l");
// legend->AddEntry(gGCRHemin,"","l");
// legend->AddEntry(gGCRCmin,"","l");
// legend->AddEntry(gGCROmin,"","l");
// legend->AddEntry(gGCRFemin,"","l");
 legend->Draw();

}
