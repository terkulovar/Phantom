void shield()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
 c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
// gPad->SetLogy();
 gStyle->SetOptStat(0);

 double xbins[29] = {1.5, 1.68, 1.9, 2.14, 2.39, 2.57, 3.31, 3.73, 4.048, 4.82, 6.83, 8.03, 9.9, 12.22, 14.59, 15.5, 
                     17.26, 18.92, 19.94, 20.96, 22.48, 24.4, 25.2, 26.1, 27.55, 28.92, 30.69, 32.24, 34.95};
 double w[29] = {0.333, 0.25, 0.2, 0.15, 0.122, 0.102, 0.066, 0.057, 0.062, 0.056, 0.034, 0.024, 0.016, 0.013, 0.024,
                 0.014, 0.0094, 0.013, 0.023, 0.025, 0.018, 0.028, 0.015, 0.012, 0.007, 0.0052, 0.0052, 0.0052, 0.003 };
 auto hh2 = new TH1F("hh2", "", 1000, 1., 36.);
 double z;
 double tot = 0;
 for ( int i = 0; i < 29; i++ )
 {
  hh2->Fill(xbins[i], w[i]);
  z = xbins[i]*10./2.699;
  tot += w[i];
  cout<<z<<" "<<w[i]<<endl;
 }
 double mean = 0;
 for ( int i = 0; i < 29; i++ )
 {
//  mean += xbins[i]*10.*w[i]/2.699/tot;
  mean += xbins[i]*w[i]/tot;
  cout<<"i mean "<<i<<" "<<mean<<endl;
 }
 hh2->SetMarkerStyle(20);
 hh2->SetMarkerSize(0.8);
// cout<<"mean "<<hh2->GetMean()<<endl;
// auto hh2 = new TH1F("hh2", "", 100000, 0.09, 410.);

}
