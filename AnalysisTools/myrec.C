void myrec()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
// c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);

 auto f = new TFile("myrec.root");
 auto hh11 = (TH1*)f->Get("hh1");
 auto hh22 = (TH1*)f->Get("hh2");
 auto hh33 = (TH1*)f->Get("hh3");
 auto hh44 = (TH1*)f->Get("hh4");
 hh11->Print();
 hh22->Print();
 hh33->Print();
 hh44->Print();
 TDirectory *top = new TDirectory("top","top");
 hh11->SetDirectory(top);
 hh22->SetDirectory(top);
 hh33->SetDirectory(top);
 hh44->SetDirectory(top);

 auto f1 = new TFile("myrec_gcr_new_step.root");
 auto hh1 = (TH1*)f1->Get("hh1");
 auto hh2 = (TH1*)f1->Get("hh2");
 auto hh3 = (TH1*)f1->Get("hh3");
 auto hh4 = (TH1*)f1->Get("hh4");
 Double_t  n2 = hh1->GetEntries();
 cout<<"hh1 entries "<<n2<<endl;
 hh1->Scale(1./n2);
 hh1->SetLineColor(2);
 hh1->SetLineWidth(2);


 hh33->SetLineColor(2);
 hh22->SetLineColor(1);
 hh11->SetLineWidth(2);
 hh33->SetLineWidth(2);
 hh11->GetYaxis()->SetLabelSize(0.04);
 hh11->GetXaxis()->SetLabelSize(0.04);
 hh11->GetYaxis()->SetTitleSize(0.04);
 hh11->GetYaxis()->SetTitleOffset(1.45);
 hh11->GetXaxis()->SetTitleSize(0.04);
 hh33->GetXaxis()->SetTitle("(#frac{MeV}{cm})");
 Double_t  n1 = hh11->GetEntries();
 cout<<"hh11 entries "<<n1<<endl;
 Double_t  n3 = hh33->GetEntries();
 cout<<"hh3 entries "<<n3<<endl;
 hh11->Scale(1./n1);
 hh33->Scale(1./n3);
 hh11->Draw("hist");
 hh1->Draw("histsame");
 cout<<"hh1 entries "<<n1<<endl;
 cout<<"hh3 entries "<<n3<<endl;
// hh2->Draw("histsame");
// hh4->Draw("hist");
}

