void myrec1()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
 c1->SetGrid();
 c1->SetLogy();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
 TDirectory *top = new TDirectory("top","top");

// auto f = new TFile("myrec_372km_96.8_LET_trapped_H.root");

 auto f = new TFile("myrec_372km_96.8_LET_trapped_H.root");
 auto h0 = (TH1*)f->Get("hh1");
 h0->SetName("h0");
 Double_t  n0 = h0->GetEntries();
 Int_t  nb0 = h0->GetNbinsX();
 cout<<"h0 entries bins "<<n0<<" "<<h0->GetNbinsX()<<endl;
 h0->Rebin(8);
 cout<<"h0 entries bins rebin "<<h0->GetEntries()<<" "<<h0->GetNbinsX()<<endl;
 h0->Scale(1./n0);
 h0->SetLineColor(1);
 h0->SetLineWidth(2);
 h0->GetXaxis()->SetTitleOffset(1.2);
 h0->GetXaxis()->SetTitle("LET [#frac{keV}{#mum}]");
 h0->Draw("hist");
 h0->GetXaxis()->SetRange(0, 400);
 h0->SetDirectory(top);


 auto f1 = new TFile("myrec_372km_96.8_LET_gcr_H.root");
 auto h1 = (TH1*)f1->Get("hh1");
 h1->SetName("h1");
 Double_t  n1 = h1->GetEntries();
 cout<<"h1 entries "<<n1<<endl;
 h1->Rebin(8);
 cout<<"h1 entries bins rebin "<<h1->GetEntries()<<" "<<h1->GetNbinsX()<<endl;
 h1->Scale(1./n1);
 h1->SetLineColor(2);
 h1->SetLineWidth(2);
 h1->GetXaxis()->SetTitleOffset(1.2);
 h1->Draw("histsame");
// h1->Draw("hist");
 h1->GetXaxis()->SetTitle("LET [#frac{keV}{#mum}]");
// h1->GetXaxis()->SetRange(0, 400);
// TDirectory *top = new TDirectory("top","top");
 h1->SetDirectory(top);


 auto f2 = new TFile("myrec_372km_96.8_LET_gcr_He.root");
 auto h2 = (TH1*)f2->Get("hh1");
// auto h1 = (TH1*)f->Get("hh1");
 h2->SetName("h2");
 Double_t  n2 = h2->GetEntries();
 cout<<"h2 entries "<<n2<<endl;
 h2->Rebin(8);
 cout<<"h2 entries bins rebin "<<h2->GetEntries()<<" "<<h2->GetNbinsX()<<endl;
 h2->Scale(1./n2);
 h2->SetLineColor(4);
 h2->SetLineWidth(2);
 h2->Draw("histsame");
// h2->Draw("hist");
 h2->SetDirectory(top);


 auto f3 = new TFile("myrec_372km_96.8_LET_gcr_C.root");
 auto h3 = (TH1*)f3->Get("hh1");
 h3->SetName("h3");
 Double_t  n3 = h3->GetEntries();
 cout<<"h3 entries "<<n3<<endl;
 h3->Rebin(8);
 cout<<"h3 entries bins rebin "<<h3->GetEntries()<<" "<<h3->GetNbinsX()<<endl;
 h3->Scale(1./n3);
 h3->SetLineColor(3);
 h3->SetLineWidth(2);
 h3->Draw("histsame");
 h3->SetDirectory(top);

 auto f4 = new TFile("myrec_372km_96.8_LET_gcr_O.root");
 auto h4 = (TH1*)f4->Get("hh1");
 h4->SetName("h4");
 Double_t  n4 = h4->GetEntries();
 cout<<"h4 entries "<<n4<<endl;
 h4->Rebin(8);
 cout<<"h4 entries bins rebin "<<h4->GetEntries()<<" "<<h4->GetNbinsX()<<endl;
 h4->Scale(1./n4);
 h4->SetLineColor(6);
 h4->SetLineWidth(2);
 h4->Draw("histsame");
 h4->SetDirectory(top);

 auto f5 = new TFile("myrec_372km_96.8_LET_gcr_Fe.root");
 auto h5 = (TH1*)f5->Get("hh1");
 h5->SetName("h5");
 Double_t  n5 = h5->GetEntries();
 cout<<"h5 entries "<<n5<<endl;
 h5->Rebin(8);
 cout<<"h5 entries bins rebin "<<h5->GetEntries()<<" "<<h5->GetNbinsX()<<endl;
 h5->Scale(1./n5);
 h5->SetLineColor(7);
 h5->SetLineWidth(2);
 h5->Draw("histsame");
 h5->SetDirectory(top);

 top->cd();
 TLegend *legend = new TLegend(0.45,0.57,0.67,0.94);
 legend->SetFillColor(0);
// legend->SetBorderSize(0);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetTextSize(0.045);
 legend->AddEntry(h0,"H TRP","l");
 legend->AddEntry(h1,"H GCR","l");
 legend->AddEntry(h2,"He GCR","l");
 legend->AddEntry(h3,"C GCR","l");
 legend->AddEntry(h4,"O GCR","l");
 legend->AddEntry(h5,"Fe GCR","l");
 legend->Draw();

 gDirectory->ls();
}

