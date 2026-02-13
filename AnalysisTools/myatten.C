void myatten()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
 c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
// gPad->SetLogy();
 gStyle->SetOptStat(0);
// auto gTrap_proton = new TGraph();
 auto gTrap_proton = new TGraphErrors();
 gTrap_proton->SetName("gTrapped");
 gTrap_proton->SetMarkerColor(2);
 gTrap_proton->SetMarkerStyle(21);
 gTrap_proton->SetMarkerSize(1.3);
// gTrap_proton->SetLineColor(2);
// gTrap_proton->SetLineWidth(3);
// auto gTrap_proton1 = new TGraph();
 auto gTrap_proton1 = new TGraphErrors();
 gTrap_proton1->SetName("gTrapped1");
 gTrap_proton1->SetMarkerColor(4);
 gTrap_proton1->SetMarkerStyle(20);
 gTrap_proton1->SetMarkerSize(1.3);
// gTrap_proton1->SetLineColor(4);
// gTrap_proton1->SetLineWidth(3);
// auto gTrap_proton2 = new TGraph();
 auto gTrap_proton2 = new TGraphErrors();
 gTrap_proton2->SetName("gTrapped2");
 gTrap_proton2->SetMarkerColor(2);
 gTrap_proton2->SetMarkerStyle(21);
 gTrap_proton2->SetMarkerSize(1.2);
// gTrap_proton2->SetLineColor(3);
// gTrap_proton2->SetLineWidth(3);
// auto gTrap_proton3 = new TGraph();
 auto gTrap_proton3 = new TGraphErrors();
 gTrap_proton3->SetName("gTrapped3");
 gTrap_proton3->SetMarkerColor(4);
 gTrap_proton3->SetMarkerStyle(20);
 gTrap_proton3->SetMarkerSize(1.2);
 auto gTrap_proton4 = new TGraphErrors();
 gTrap_proton4->SetName("gTrapped4");
 gTrap_proton4->SetMarkerColor(2);
 gTrap_proton4->SetMarkerStyle(21);
 gTrap_proton4->SetMarkerSize(1.3);
 auto gTrap_proton5 = new TGraphErrors();
 gTrap_proton5->SetName("gTrapped5");
 gTrap_proton5->SetMarkerColor(4);
 gTrap_proton5->SetMarkerStyle(20);
 gTrap_proton5->SetMarkerSize(1.3);
 auto gTrap_proton6 = new TGraphErrors();
 gTrap_proton6->SetName("gTrapped6");
 gTrap_proton6->SetMarkerColor(2);
 gTrap_proton6->SetMarkerStyle(25);
 gTrap_proton6->SetMarkerSize(1.3);
 auto gTrap_proton7 = new TGraphErrors();
 gTrap_proton7->SetName("gTrapped7");
 gTrap_proton7->SetMarkerColor(4);
 gTrap_proton7->SetMarkerStyle(24);
 gTrap_proton7->SetMarkerSize(1.3);
 auto gTrap_proton8 = new TGraphErrors();
 gTrap_proton8->SetName("gTrapped8");
 gTrap_proton8->SetMarkerColor(2);
 gTrap_proton8->SetMarkerStyle(25);
 gTrap_proton8->SetMarkerSize(1.3);
 auto gTrap_proton9 = new TGraphErrors();
 gTrap_proton9->SetName("gTrapped9");
 gTrap_proton9->SetMarkerColor(4);
 gTrap_proton9->SetMarkerStyle(24);
 gTrap_proton9->SetMarkerSize(1.3);

 auto gTrap_proton10 = new TGraphErrors();
 gTrap_proton10->SetName("gTrapped10");
 gTrap_proton10->SetMarkerColor(2);
 gTrap_proton10->SetMarkerStyle(21);
 gTrap_proton10->SetMarkerSize(1.1);

 auto gTrap_proton11 = new TGraphErrors();
 gTrap_proton11->SetName("gTrapped11");
 gTrap_proton11->SetMarkerColor(4);
 gTrap_proton11->SetMarkerStyle(20);
 gTrap_proton11->SetMarkerSize(1.1);

// gTrap_proton3->SetLineColor(6);
// gTrap_proton3->SetLineWidth(3);
 const Int_t nbins = 5;
 double xbins[nbins] = {0.0, 1.0, 2.0, 3.0, 4.0};
// double ybins[nbins] = {0.000404832, 0.000285294, 0.000242715, 0.00019748, 0.000184989};
// double ybins[nbins] = {0.000372583, 0.000310731, 0.000264365, 0.000231062, 0.000219894};
// double ybins[nbins] = {0.000377975, 0.000329255, 0.000268062, 0.000245607, 0.000229154};
 double ybins[nbins] = {0.000434197, 0.000384446, 0.000342292, 0.000307164, 0.00029618};
//// double ybins[nbins] = {0.000434197, 0.000364446, 0.000342292, 0.000307164, 0.00029618};
// double eybins[nbins] = {1.06939e-05, 9.49951e-06, 8.41217e-06, 6.66756e-06, 5.66862e-06};
// double eybins[nbins] = {9.03634e-06, 7.49793e-06, 7.14218e-06, 9.90469e-06, 5.84081e-06};
// double eybins[nbins] = {8.65703e-06, 7.43046e-06, 6.48787e-06, 9.72189e-06, 5.78851e-06};
 double eybins[nbins] = {1.22815e-05, 1.44915e-05, 1.18791e-05, 8.0343e-06, 7.87476e-06};
// double ybins1[nbins] = {0.000998495, 0.000618058, 0.000450062, 0.000355, 0.000299802};
// double ybins1[nbins] = {0.000628761, 0.000492352, 0.000422641, 0.000350079, 0.000323088};
// double ybins1[nbins] = {0.000621116, 0.000491314, 0.000402028, 0.000347118, 0.000312234};
//// double ybins1[nbins] = {0.000887031, 0.000719675, 0.000555255, 0.000472568, 0.000399162};
 double ybins1[nbins] = {0.000887031, 0.000679675, 0.000555255, 0.000472568, 0.000399162};
// double eybins1[nbins] = {1.71956e-05, 1.27614e-05, 1.13956e-05, 1.02226e-05, 8.72759e-06};
// double eybins1[nbins] = {1.28265e-05, 8.75459e-06, 7.86913e-06, 8.62829e-06, 8.55391e-06};
// double eybins1[nbins] = {1.17505e-05, 9.4842e-06, 8.38237e-06, 7.27312e-06, 7.26919e-06};
 double eybins1[nbins] = {1.84977e-05, 1.41613e-05, 1.54538e-05, 1.12984e-05, 1.00076e-05};

// double ybins2[nbins] = {0.00101077, 0.000756571, 0.000690005, 0.000591331, 0.000540414};
// double ybins2[nbins] = {0.001534, 0.00125295, 0.00107188, 0.000952373, 0.000918491};
// double ybins2[nbins] = {0.000668424, 0.000587304, 0.000527947, 0.000499275, 0.00047656};
 double ybins2[nbins] = {0.000593425, 0.000552499, 0.000493145, 0.00045178, 0.000428216};
// double eybins2[nbins] = {2.89196e-05, 3.07227e-05, 3.03362e-05, 2.39076e-05, 2.18219e-05};
// double eybins2[nbins] = {5.53553e-05, 3.27786e-05, 3.03356e-05, 3.77968e-05, 2.63645e-05};
 double eybins2[nbins] = {2.15257e-05, 2.00495e-05, 2.15879e-05, 0.0000240109, 1.94341e-05};
// double eybins2[nbins] = {2.41027e-05, 3.15002e-05, 2.23379e-05, 2.72742e-05, 1.99688e-05};
// double ybins3[nbins] = {0.00223485, 0.00141645, 0.00100384, 0.000858866, 0.000703837};
// double ybins3[nbins] = {0.00259183, 0.0019745, 0.00170821, 0.00150956, 0.00132953};
// double ybins3[nbins] = {0.00115323, 0.000883202, 0.000737592, 0.000642176, 0.000594246};
//// double ybins3[nbins] = {0.00122804, 0.000961303, 0.00080844, 0.000696074, 0.00059368};
 double ybins3[nbins] = {0.00122804, 0.000981303, 0.00080844, 0.000696074, 0.00059368};
// double eybins3[nbins] = {4.77473e-05, 3.84609e-05, 3.45203e-05, 3.43702e-05, 2.19189e-05};
// double eybins3[nbins] = {0.0000504787, 3.61921e-05, 3.56398e-05, 3.87758e-05, 3.80586e-05};
 double eybins3[nbins] = {4.44438e-05, 3.63982e-05, 3.07236e-05, 2.11702e-05, 1.88683e-05};

// double ybins4[nbins] = {0.000117322, 0.000136954, 0.000153823, 0.000170561, 0.000182232};
// double ybins4[nbins] = {6.94877e-05, 8.00484e-05, 8.60298e-05, 9.64972e-05, 0.000102249};
// double ybins4[nbins] = {6.94877e-05, 8.00484e-05, 8.60298e-05, 9.64972e-05, 0.000102249};
 double ybins4[nbins] = {0.000110834, 0.000132879, 0.000150181, 0.000171433, 0.000189954};
// double eybins4[nbins] = {2.98984e-06, 3.08737e-06, 3.135e-06, 2.27194e-06, 1.93739e-06};
// double eybins4[nbins] = {1.44698e-06, 1.99115e-06, 1.41481e-06, 1.65526e-06, 1.83902e-06};
 double eybins4[nbins] = {1.73896e-06, 2.21655e-06, 2.13797e-06, 1.8696e-06, 1.94336e-06};

// double ybins5[nbins] = {7.40308e-05, 8.67456e-05, 9.404e-05, 0.000103484, 0.000112257};
// double ybins5[nbins] = {6.25659e-05, 7.75483e-05, 9.09348e-05, 9.89127e-05, 0.000105137};
 double ybins5[nbins] = {0.000124306, 0.000149256, 0.000175829, 0.000199188, 0.000220969};
// double eybins5[nbins] = {2.19501e-06, 2.90604e-06, 2.1696e-06, 2.55731e-06, 1.67779e-06};
 double eybins5[nbins] = {1.44682e-06, 2.11634e-06, 2.12436e-06, 2.4617e-06, 2.08316e-06};
// double eybins5[nbins] = {4.10087e-06, 2.95474e-06, 3.27032e-06, 3.26585e-06, 1.84251e-06};

// double ybins6[nbins] = {0.000363733, 0.00041119, 0.000455503, 0.000483473, 0.000524112};
// double ybins6[nbins] = {0.000236543, 0.000260777, 0.000276414, 0.000288285, 0.000309768};
 double ybins6[nbins] = {0.000209747, 0.000244046, 0.00028792, 0.000314112, 0.000347264};
// double eybins6[nbins] = {3.97564e-05, 3.42083e-05, 3.28438e-05, 2.23112e-05, 2.24633e-05};
 double eybins6[nbins] = {2.06603e-05, 2.17661e-05, 2.12389e-05, 2.19494e-05, 2.41751e-05};
// double eybins6[nbins] = {6.84718e-06, 5.43967e-06, 4.56463e-05, 4.93265e-06, 4.44408e-06};

// double ybins7[nbins] = {0.000230452, 0.000262297, 0.000292312, 0.000310221, 0.000327571};
// double ybins7[nbins] = {0.000215381, 0.000249965, 0.000285354, 0.000298541, 0.000320952};
 double ybins7[nbins] = {0.000247605, 0.000287109, 0.000326216, 0.000345718, 0.000364029};
// double eybins7[nbins] = {2.08922e-05, 2.54185e-05, 2.09419e-05, 2.65827e-05, 2.20022e-05};
// double eybins7[nbins] = {8.67308e-06, 1.16567e-05, 1.11518e-05, 1.57872e-05, 1.12345e-05};
 double eybins7[nbins] = {2.67024e-05, 3.78836e-05, 4.29729e-05, 4.57757e-05, 3.31745e-05};


// double ybins3[nbins] = {0.00107161, 0.000624608, 0.000418246, 0.000289378, 0.00023602};
// double ybins4[nbins] = {0.00103144, 0.000697704, 0.000438577, 0.000379965, 0.000304416};
// double ybins5[nbins] = {0.000983266, 0.000636135, 0.000513282, 0.000367924, 0.000288322};
 for ( int i = 0; i < nbins; i++ )
 {
//  ybins[i] = 0.0010115/ybins[i];      // rho=15g/cm^2 iso trapped protons 
  if ( i == 0 )
   ybins[i] = 0.7*ybins[i]*1.e6;      // rho=15g/cm^2 iso trapped protons GCR protons He C O dose
  if ( i == 1 )
   ybins[i] = 0.7*ybins[i]*1.e6/1.07;      // rho=15g/cm^2 iso trapped protons GCR protons He C O dose
  if ( i == 2 )
   ybins[i] = 0.7*ybins[i]*1.e6/1.06;      // rho=15g/cm^2 iso trapped protons GCR protons He C O dose
  if ( i == 3 )
   ybins[i] = 0.7*ybins[i]*1.e6/1.055;      // rho=15g/cm^2 iso trapped protons GCR protons He C O dose
  if ( i == 4 )
   ybins[i] = 0.7*ybins[i]*1.e6/1.05;      // rho=15g/cm^2 iso trapped protons GCR protons He C O dose

  eybins[i] = eybins[i]*1.e6;      // rho=15g/cm^2 iso trapped protons GCR protons He C O

  if ( i == 0 )
   ybins1[i] = 0.7*ybins1[i]*1.e6;      // rho=1.5g/cm^2 iso trapped protons GCR protons He C O dose
  else
   ybins1[i] = 0.7*ybins1[i]*1.e6/1.05;      // rho=1.5g/cm^2 iso trapped protons GCR protons He C O dose

  eybins1[i] = eybins1[i]*1.e6;      // rho=1.5g/cm^2 iso trapped protons GCR protons He C O

  if ( i == 0 )
   ybins4[i] = 0.7*ybins4[i]*1.e6;      // rho=15g/cm^2 is GCR protons He C O Fe dose
  else
   ybins4[i] = 0.7*ybins4[i]*1.e6*1.03;      // rho=15g/cm^2 is GCR protons He C O Fe dose
  eybins4[i] = eybins4[i]*1.e6;      // rho=15g/cm^2 iso GCR protons He C O Fe
  if ( i == 0 )
   ybins5[i] = 0.7*ybins5[i]*1.e6;      // rho=1.5g/cm^2 iso GCR protons He C O Fe dose
  else
   ybins5[i] = 0.7*ybins5[i]*1.e6*1.03;      // rho=1.5g/cm^2 iso GCR protons He C O Fe dose
  eybins5[i] = eybins5[i]*1.e6;      // rho=1.5g/cm^2 iso GCR protons He C O Fe

  if ( i == 0 )
   ybins2[i] = 0.7*ybins2[i]*1.e6;   // rho=15g/cm^2 trapped protons GCR protons He C O equivalent dose
  if ( i == 1 )
   ybins2[i] = 0.7*ybins2[i]*1.e6/1.07;   // rho=15g/cm^2 trapped protons GCR protons He C O equivalent dose
  if ( i == 2 )
   ybins2[i] = 0.7*ybins2[i]*1.e6/1.06;   // rho=15g/cm^2 trapped protons GCR protons He C O equivalent dose
  if ( i == 3 )
   ybins2[i] = 0.7*ybins2[i]*1.e6/1.055;   // rho=15g/cm^2 trapped protons GCR protons He C O equivalent dose
  if ( i == 4 )
   ybins2[i] = 0.7*ybins2[i]*1.e6/1.05;   // rho=15g/cm^2 trapped protons GCR protons He C O equivalent dose
  eybins2[i] = eybins2[i]*1.e6;   // rho=15g/cm^2 trapped protons GCR protons He C O equivalent dose

  if ( i == 0 )
   ybins3[i] = 0.7*ybins3[i]*1.e6;   // rho=1.5g/cm^2 trapped protons GCR protons He C O equivalent dose
  if ( i == 1 )
   ybins3[i] = 0.7*ybins3[i]*1.e6/1.07;   // rho=1.5g/cm^2 trapped protons GCR protons He C O equivalent dose
  if ( i == 2 )
   ybins3[i] = 0.7*ybins3[i]*1.e6/1.06;   // rho=1.5g/cm^2 trapped protons GCR protons He C O equivalent dose
  if ( i == 3 )
   ybins3[i] = 0.7*ybins3[i]*1.e6/1.055;   // rho=1.5g/cm^2 trapped protons GCR protons He C O equivalent dose
  if ( i == 4 )
   ybins3[i] = 0.7*ybins3[i]*1.e6/1.05;   // rho=1.5g/cm^2 trapped protons GCR protons He C O equivalent dose
  eybins3[i] = eybins3[i]*1.e6;   // rho=1.5g/cm^2 trapped protons GCR protons He C O equivalent dose

  if ( i == 0 )
   ybins6[i] = 0.7*ybins6[i]*1.e6;   // rho=15g/cm^2 GCR protons He C O equivalent dose
  if ( i == 1 )
   ybins6[i] = 0.7*ybins6[i]*1.e6*1.03;   // rho=15g/cm^2 GCR protons He C O equivalent dose
  if ( i == 2 )
   ybins6[i]= 0.7*ybins6[i]*1.e6*1.03;   // rho=15g/cm^2 GCR protons He C O equivalent dose
  if ( i == 3 )
   ybins6[i] = 0.7*ybins6[i]*1.e6*1.03;   // rho=15g/cm^2 GCR protons He C O equivalent dose
  if ( i == 4 )
   ybins6[i] = 0.7*ybins6[i]*1.e6*1.02;   // rho=15g/cm^2 GCR protons He C O equivalent dose
  eybins6[i] = eybins6[i]*1.e6;   // rho=15g/cm^2 GCR protons He C O equivalent dose
  if ( i == 0 )
   ybins7[i] = 0.7*ybins7[i]*1.e6;   // rho=1.5g/cm^2 GCR protons He C O equivalent dose
  else
   ybins7[i] = 0.7*ybins7[i]*1.e6*1.03;   // rho=1.5g/cm^2 GCR protons He C O equivalent dose
  eybins7[i] = eybins7[i]*1.e6;   // rho=1.5g/cm^2 GCR protons He C O equivalent dose

//  ybins3[i] = 0.00107161/ybins3[i];   // rho=1.5g/cm^2 iso trapped protons
//  ybins4[i] = 0.00103144/ybins4[i];   // rho=1.5g/cm^2 iso all
//  ybins5[i] = 0.000983266/ybins5[i];   // rho=10.g/cm^2 iso all
  cout<<"i ybins ybins1 ybins2 ybins3 "<<i<<" "<<ybins[i]<<" "<<ybins1[i]<<" "<<ybins2[i]<<" "<<ybins3[i]<<endl;
  cout<<"i k "<<i<<" "<<ybins2[i]/ybins[i]<<" "<<ybins3[i]/ybins1[i]<<" "<<ybins6[i]/ybins4[i]<<" "<<ybins7[i]/ybins5[i]<<endl;
//      <<" "<<ybins4[i]<<" "<<ybins5[i]<<" "<<ybins6[i]<<" "<<ybins7[i]<<endl;
//  cout<<"!!!!!! i a1 a2 "<<ybins6[i]/ybins4[i]<<" "<<ybins7[i]/ybins5[i]<<endl;
  gTrap_proton->SetPoint(i, xbins[i], ybins[i]);
  gTrap_proton->SetPointError(i, 0, 2.*eybins[i]);
  gTrap_proton1->SetPoint(i, xbins[i], ybins1[i]);
  gTrap_proton1->SetPointError(i, 0, 2.*eybins1[i]);

  gTrap_proton2->SetPoint(i, xbins[i], ybins2[i]);
  gTrap_proton2->SetPointError(i, 0, 1.*eybins2[i]);

  gTrap_proton3->SetPoint(i, xbins[i], ybins3[i]);
  gTrap_proton3->SetPointError(i, 0, 1.*eybins3[i]);
  double err = sqrt(eybins2[i]*eybins2[i]/ybins[i]/ybins[i] + 
                    ybins2[i]*ybins2[2]*eybins[i]*eybins[i]/ybins[i]/ybins[i]/ybins[i]/ybins[i]);
  gTrap_proton4->SetPoint(i, xbins[i], ybins2[i]/ybins[i]);
  if ( i == 0 || i == 3  )
   gTrap_proton4->SetPointError(i, 0, 0.5*err);
  else
   gTrap_proton4->SetPointError(i, 0, 0.5*err);
  
  err = sqrt(eybins3[i]*eybins3[i]/ybins1[i]/ybins1[i] + ybins3[i]*ybins3[2]*eybins1[i]*eybins1[i]/ybins1[i]/ybins1[i]/ybins1[i]/ybins1[i]);
  gTrap_proton5->SetPoint(i, xbins[i], ybins3[i]/ybins1[i]);
  cout<<"K blue i rat "<<i<<" "<<ybins3[i]/ybins1[i]<<endl;
  gTrap_proton5->SetPointError(i, 0, 0.5*err);

  gTrap_proton6->SetPoint(i, xbins[i], ybins4[i]);
  gTrap_proton6->SetPointError(i, 0, 1.0*eybins4[i]);
  gTrap_proton7->SetPoint(i, xbins[i], ybins5[i]);
  gTrap_proton7->SetPointError(i, 0, 1.*eybins5[i]);

  gTrap_proton8->SetPoint(i, xbins[i], ybins6[i]);
  gTrap_proton8->SetPointError(i, 0, 0.5*eybins6[i]);
  gTrap_proton9->SetPoint(i, xbins[i], ybins7[i]);
  gTrap_proton9->SetPointError(i, 0, 0.5*eybins7[i]);

  err = sqrt(eybins6[i]*eybins6[i]/ybins4[i]/ybins4[i] + 
                    ybins6[i]*ybins6[i]*eybins4[i]*eybins4[i]/ybins4[i]/ybins4[i]/ybins4[i]/ybins4[i]);
  gTrap_proton10->SetPoint(i, xbins[i], ybins6[i]/ybins4[i]);
//  if ( i == 0 || i == 3  )
//   gTrap_proton4->SetPointError(i, 0, 0.5*err);
//  else
  gTrap_proton10->SetPointError(i, 0, 1.0*err);

  err = sqrt(eybins7[i]*eybins7[i]/ybins5[i]/ybins5[i] + 
                    ybins7[i]*ybins7[i]*eybins5[i]*eybins5[i]/ybins5[i]/ybins5[i]/ybins5[i]/ybins5[i]);
  gTrap_proton11->SetPoint(i, xbins[i], ybins7[i]/ybins5[i]);
//  if ( i == 0 || i == 3  )
//   gTrap_proton4->SetPointError(i, 0, 0.5*err);
//  else
  gTrap_proton11->SetPointError(i, 0, 1.0*err);


 }
 auto mg = new TMultiGraph();
// mg->Add(gTrap_proton); //dose trap + GCR
// mg->Add(gTrap_proton1); //dose trap + GCR
 mg->Add(gTrap_proton2); //eq dose trap + GCR
 mg->Add(gTrap_proton3); // eq dose trap + GCR
// mg->Add(gTrap_proton4);   // k trap + GCR
// mg->Add(gTrap_proton5);   // k trap + GCR
// mg->Add(gTrap_proton6);  //dose GCR
// mg->Add(gTrap_proton7);  // dose GCR
 mg->Add(gTrap_proton8); //eq dose GCR
 mg->Add(gTrap_proton9); // eq dose GCR
// mg->Add(gTrap_proton10);
// mg->Add(gTrap_proton11);
 mg->Draw("AP");
// mg->GetXaxis()->SetRangeUser(0.03, 1.02e5);
 mg->GetYaxis()->SetLabelSize(0.04);
 mg->GetXaxis()->SetLabelSize(0.04);
 mg->GetYaxis()->SetTitleSize(0.04);
 mg->GetYaxis()->SetTitleOffset(1.45);
 mg->GetXaxis()->SetTitleSize(0.04);
// mg->GetHistogram()->SetXTitle("h (cm)");
 mg->GetHistogram()->SetXTitle("h_{c} (cm)");
// mg->GetHistogram()->SetYTitle("K (#muSv #muGy^{-1})");
// mg->GetHistogram()->SetYTitle("K");
// mg->GetYaxis()->SetRangeUser(2.5, 4.);
// mg->GetYaxis()->SetRangeUser(1.2, 1.8);
// mg->GetHistogram()->SetYTitle("D (#muGy day^{-1})");
// mg->GetYaxis()->SetRangeUser(0., 900.);
 mg->GetYaxis()->SetRangeUser(0., 1200.);
 mg->GetHistogram()->SetYTitle("D_{eq} (#muSv day^{-1})");
// mg->GetHistogram()->SetYTitle("equivalent dose[#muSv]");
 auto axis1 = mg->GetXaxis();
 double xmin = axis1->GetXmin();
 double xmax = axis1->GetXmax();
 TGaxis *axis2 = new TGaxis(gPad->GetUxmin(),gPad->GetUymax(),
         gPad->GetUxmax(), gPad->GetUymax(),xmin*2.7,xmax*2.7,510,"-");
 axis2->SetLabelSize(0.035);
 axis2->SetTitleSize(0.035);
 axis2->SetLabelFont(42);
// axis2->SetTitle("#frac{g}{cm^{2}}");
 axis2->SetTitle("g/cm^{2}");
 axis2->SetTitleFont(42);
 axis2->SetNdivisions(512);
 axis2->SetTitleOffset(1.2);
// double ypos = c1->GetFrame()->GetY2();
// auto axis2 = TGaxis(xmin,ypos,xmax,ypos,xmin*2.7,xmax*2.7,510,"-");
// axis2->Draw();
// cout<<"bins "<<mg->GetHistogram()->GetNbinsX()<<endl;
// mg->Draw("AP");

// TLegend *legend = new TLegend(0.51,0.57,0.83,0.76);
 TLegend *legend = new TLegend(0.45,0.57,0.97,0.94);
 legend->SetFillColor(0);
// legend->SetBorderSize(0);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetTextSize(0.045);
// legend->AddEntry(gTrap_proton,"density 10 #frac{g}{cm^{2}}","p");
// legend->AddEntry(gTrap_proton1,"density 1.5 #frac{g}{cm^{2}}","p");
// legend->AddEntry(gTrap_proton4,"h_{ht}^{min} = 10#frac{g}{cm^{2}} ","p");
// legend->AddEntry(gTrap_proton5,"h_{ht}^{min} = 1.5#frac{g}{cm^{2}}","p");
 legend->AddEntry(gTrap_proton2,"h_{ht}^{min} = 10#frac{g}{cm^{2}} RPZ + GCR","p");
 legend->AddEntry(gTrap_proton3,"h_{ht}^{min} = 1.5#frac{g}{cm^{2}} GCR","p");
 legend->AddEntry(gTrap_proton8,"h_{ht}^{min} = 10#frac{g}{cm^{2}} RPZ + GCR","p");
 legend->AddEntry(gTrap_proton9,"h_{ht}^{min} = 1.5#frac{g}{cm^{2}} GCR","p");
// legend->AddEntry(hh1,"water+alu+polyprop","p");
// legend->AddEntry("","water+alu+polyprop","");
// legend->AddEntry(hh2,"water+alu+polyprop+shielding(1cm) ","p");
 legend->Draw();

}
