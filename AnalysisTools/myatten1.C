void myatten1()
{
 auto c1 = new TCanvas("c1","A Simple Graph Example",200,50,700, 600);
 c1->SetFillColor(0);
 c1->SetBorderMode(0);
 c1->SetGrid();
 gPad->SetFrameFillColor(0);
 gPad->SetFrameFillStyle(4000);
// gPad->SetLogy();
 gStyle->SetOptStat(0);
 auto gTrap = new TGraphErrors();
 gTrap->SetName("gTrapped");
 gTrap->SetMarkerColor(2);
 gTrap->SetMarkerStyle(21);
 gTrap->SetMarkerSize(1.3);
 auto gTrap1 = new TGraphErrors();
 gTrap1->SetName("gTrapped1");
 gTrap1->SetMarkerColor(4);
 gTrap1->SetMarkerStyle(20);
 gTrap1->SetMarkerSize(1.3);
 auto gTrap2 = new TGraphErrors();
 gTrap2->SetName("gTrapped");
 gTrap2->SetMarkerColor(2);
 gTrap2->SetMarkerStyle(25);
 gTrap2->SetMarkerSize(1.3);
 auto gTrap3 = new TGraphErrors();
 gTrap3->SetName("gTrapped3");
 gTrap3->SetMarkerColor(4);
 gTrap3->SetMarkerStyle(24);
 gTrap3->SetMarkerSize(1.3);

 auto gTrap4 = new TGraphErrors();
 gTrap4->SetName("gTrapped4");
 gTrap4->SetMarkerColor(2);
 gTrap4->SetMarkerStyle(21);
 gTrap4->SetMarkerSize(1.3);
 auto gTrap5 = new TGraphErrors();
 gTrap5->SetName("gTrapped5");
 gTrap5->SetMarkerColor(4);
 gTrap5->SetMarkerStyle(20);
 gTrap5->SetMarkerSize(1.3);

 auto gTrap6 = new TGraphErrors();
 gTrap6->SetName("gTrapped6");
 gTrap6->SetMarkerColor(2);
 gTrap6->SetMarkerStyle(25);
 gTrap6->SetMarkerSize(1.3);
 auto gTrap7 = new TGraphErrors();
 gTrap7->SetName("gTrapped7");
 gTrap7->SetMarkerColor(4);
 gTrap7->SetMarkerStyle(24);
 gTrap7->SetMarkerSize(1.3);

// gTrap_proton3->SetLineColor(6);
// gTrap_proton3->SetLineWidth(3);
 const Int_t nbins = 12;
 double xbins[nbins] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5, 11.5};
 double ybins[nbins] = {0.000240878, 0.000230824, 0.000223558, 0.000219584, 0.000215862, 0.000212809, 0.000209952,
                        0.000207318, 0.000205553, 0.000204609, 0.000204235, 0.000204259};   //372km 96.8
// double ybins[nbins] = {0.000365007, 0.000335593, 0.000316689, 0.000300298, 0.000288198, 0.000278684, 0.00027006,
//                        0.000261737, 0.000259331, 0.000254939, 0.00025397, 0.000253796};   //420km 51.6
// double ybins[nbins] = {0.000227986, 0.000212354, 0.000202221, 0.000193705, 0.000187521, 0.000182891, 0.000180975,
//                        0.000177463, 0.000175266, 0.000176085, 0.000173467, 0.00017317};   //372km 51.6
 double eybins[nbins] = {1.07169e-05, 1.17113e-05, 9.38473e-06, 1.02157e-05, 1.19055e-05, 1.19099e-05, 1.49741e-05,
                         1.06139e-05, 1.06107e-05, 1.06319e-05, 1.03805e-05, 1.01681e-05};  //372km 96.8
// double eybins[nbins] = {1.84618e-05, 1.87617e-05, 1.89084e-05, 1.87857e-05, 1.83939e-05, 1.84962e-05, 1.8805e-05,
//                         2.09307e-05, 2.14406e-05, 2.77775e-05, 2.62948e-05, 2.51074e-05};  //420km 51.6
// double eybins[nbins] = {1.07328e-05, 1.00443e-05, 9.70515e-06, 1.19507e-05, 1.31433e-05, 1.347e-05, 1.40514e-05,
//                         1.3624e-05, 1.36624e-05, 1.55585e-05, 1.56725e-05, 1.4181e-05};  //372km 51.6
 double ybins1[nbins] = {0.000335351, 0.000303446, 0.000285118, 0.000272517, 0.000261946, 0.00025506, 0.000250185,
                         0.000244208, 0.00024231, 0.000239692, 0.000241383, 0.000241087};  //372km 96.8
// double ybins1[nbins] = {0.000631903, 0.000537815, 0.000483968, 0.000445177, 0.000420354, 0.000392329, 0.000374534,
//                         0.000362488, 0.000353236, 0.000343342, 0.000341133, 0.000340362};  //420km 51.6
// double ybins1[nbins] = {0.000368119, 0.000317394, 0.000289522, 0.000268789, 0.000254881, 0.000243377, 0.00023752, 
//                         0.000229469, 0.000224087, 0.000219301, 0.000217005, 0.000216454};  //372km 51.6
 double eybins1[nbins] = {1.26081e-05, 1.28261e-05, 1.13179e-05, 1.31772e-05, 1.50903e-05, 1.10734e-05, 1.2522e-05,
                          1.27395e-05, 1.58221e-05, 1.75236e-05, 1.81114e-05, 1.58289e-05}; //372km 96.8
// double eybins1[nbins] = {2.07397e-05, 2.34935e-05, 2.80158e-05, 2.26092e-05, 2.39827e-05, 2.29501e-05, 2.17042e-05,
//                          2.49406e-05, 2.45058e-05, 2.78385e-05, 2.66131e-05, 2.70902e-05}; //420km 51.6
// double eybins1[nbins] = {1.4989e-05, 1.34496e-05, 1.47903e-05, 1.12973e-05, 1.42732e-05, 1.408e-05, 1.49465e-05,
//                          1.46842e-05, 1.47538e-05, 1.67665e-05, 1.74881e-05, 1.75868e-05}; //372km 51.6
 double ybins2[nbins] = {0.000141569, 0.000143228, 0.000144658, 0.000145275, 0.00014548, 0.000146231, 0.000147376,
                         0.000148657, 0.000148604, 0.000149174, 0.000149114, 0.00014981};  //372km 96.8
// double ybins2[nbins] = {8.67932e-05, 8.78958e-05, 8.90539e-05, 8.99264e-05, 9.03365e-05, 9.14613e-05, 9.17544e-05,
//                         9.17648e-05, 9.24068e-05, 9.24593e-05, 9.23221e-05, 9.19027e-05};  //420km 51.6
// double ybins2[nbins] = {8.34981e-05, 8.44576e-05, 8.56058e-05, 8.61467e-05, 8.65778e-05, 8.73801e-05, 8.81611e-05,
//                         8.88803e-05, 8.90051e-05, 8.98112e-05, 9.05044e-05, 8.97251e-05};  //372km 51.6
 double eybins2[nbins] = {4.29846e-06, 4.61735e-06, 4.25614e-06, 5.1047e-06, 4.61581e-06, 5.32669e-06, 5.00382e-06,
                          6.48739e-06, 6.99435e-06, 5.79393e-06, 7.67086e-06, 8.13522e-06}; //372km 96.8
// double eybins2[nbins] = {2.54916e-06, 2.38057e-06, 2.80469e-06, 2.88985e-06, 2.82198e-06, 3.56827e-06, 3.62792e-06, 
//                          3.39513e-06, 3.44441e-06, 3.93108e-06, 4.42162e-06, 4.48622e-06}; //420km 51.6
// double eybins2[nbins] = {2.9298e-06, 3.00652e-06, 4.2037e-06, 4.16581e-06, 3.04498e-06, 3.27043e-06, 4.04101e-06,
//                          4.55868e-06, 3.85753e-06, 5.58486e-06, 7.85677e-06, 8.09567e-06}; //372km 51.6
 double ybins3[nbins] = {0.000143294, 0.00014493, 0.000145046, 0.000147073, 0.000147197, 0.000146881, 0.000146888,
                         0.000147755, 0.000148175, 0.00014628, 0.000147251, 0.000147864};   //372km 96.8
// double ybins3[nbins] = {8.54519e-05, 8.66951e-05, 8.77004e-05, 8.87466e-05, 8.96362e-05, 8.99524e-05, 9.05968e-05,
//                         9.11521e-05, 9.14227e-05, 9.24255e-05, 9.22369e-05, 9.1498e-05};   //420km 51.6
// double ybins3[nbins] = {8.49557e-05, 8.63605e-05, 8.72924e-05, 8.83884e-05, 8.90391e-05, 8.94541e-05, 8.96079e-05,
//                         9.04259e-05, 9.1409e-05, 9.14281e-05, 9.19767e-05, 9.19058e-05};   //372km 51.6
 double eybins3[nbins] = {4.89863e-06, 5.33192e-06, 4.62363e-06, 4.99806e-06, 5.13537e-06, 5.6298e-06, 6.11696e-06,
                          7.12142e-06, 7.60377e-06, 7.88647e-06, 8.70181e-06, 8.27048e-06}; //372km 96.8
// double eybins3[nbins] = {3.2298e-06, 3.10293e-06, 3.12537e-06, 3.15127e-06, 2.9949e-06, 2.93953e-06, 2.98947e-06,
//                          3.7863e-06, 4.33677e-06, 6.50089e-06, 5.70252e-06, 6.7035e-06}; //420km 51.6
// double eybins3[nbins] = {2.77063e-06, 2.72072e-06, 3.11298e-06, 3.01756e-06, 3.10211e-06, 3.64038e-06, 3.31943e-06,
//                          4.26913e-06, 3.96409e-06, 4.70415e-06, 6.41242e-06, 9.25215e-06}; //372km 51.6

// double ybins4[nbins] = {0.000419432, 0.000399351, 0.000389187, 0.000379678, 0.000374727, 0.000369444, 0.000365107,
//                        0.000358018, 0.000352273, 0.000349353, 0.000343071, 0.00034729};    //372km 96.8
 double ybins4[nbins] = {0.000512189, 0.000483483, 0.000463272, 0.00044944, 0.000430447, 0.00041171, 0.000394408,
                         0.000384543, 0.000380032, 0.00037514, 0.000371882, 0.000366427};    //420km 51.6
// double eybins4[nbins] = {0.00016828, 0.000160512, 0.000160512, 0.000129217, 0.000186259, 0.000112479, 0.000175764,
//                          0.000119716, 0.000122105, 0.000136296, 0.00013286, 0.000132865};  //372km 96.8
 double eybins4[nbins] = {0.00016828, 0.000153896, 0.000121281, 0.000152957, 0.000140658, 7.81969e-05, 7.83707e-05,
                          8.77707e-05, 0.000116055, 0.00015565, 0.0001705222, 0.000129518};  //420km 51.6
// double ybins5[nbins] = {0.000560908, 0.000525439, 0.00049965, 0.000480311, 0.000468211, 0.000451788, 0.000432987,
//                        0.000424145, 0.000420169, 0.000416619, 0.000414356, 0.000411602};   //372km 96.8
 double ybins5[nbins] = {0.000873617, 0.000778344, 0.000720556, 0.000654908, 0.000608175, 0.000561665, 0.000530424,
                         0.000510462, 0.000492758, 0.000476196, 0.000468724, 0.000456249};   //420km 51.6
// double eybins5[nbins] = {0.000172972, 0.000165872, 0.00014388, 0.00018938, 0.000148025, 0.000125498, 0.000127663,
//                          0.000128534, 0.000201059, 0.00021825, 0.00026314, 0.000264012};   //372km 96.8
 double eybins5[nbins] = {0.000150147, 0.000162742, 0.000147088, 0.000178258, 0.000157307, 0.000130489, 0.000139698,
                          0.000218029, 0.000207197, 0.00021825, 0.00026314, 0.000164012};   //420km 51.6
// double ybins6[nbins] = {0.000280401, 0.000281581, 0.000279052, 0.000283147, 0.000281896, 0.000281549, 0.000281466, 
//                        0.000280557, 0.000284799, 0.000282979, 0.000287918, 0.000283364};   //372km 96.8
 double ybins6[nbins] = {0.000186511, 0.000182945, 0.000185905, 0.000187495, 0.000183599, 0.000187252, 0.000187749,
                         0.000186042, 0.000176175, 0.000177336, 0.000177762, 0.000178122};   //420km 51.6
// double eybins6[nbins] = {6.19418e-05, 7.96798e-05, 6.04375e-05, 7.29669e-05, 4.68e-05, 4.79463e-05, 5.05059e-05,
//                          7.55041e-05, 7.76404e-05, 4.58132e-05, 8.26709e-05, 8.04338e-05}; //372km 96.8
 double eybins6[nbins] = {3.74291e-05, 3.4256e-05, 3.89458e-05, 4.41852e-05, 3.64033e-05, 4.9553e-05, 5.02705e-05,
                          2.71198e-05, 2.4203e-05, 3.24496e-05, 4.86996e-05, 4.64872e-05}; //420km 51.6
// double ybins7[nbins] = {0.000304737, 0.000301392, 0.000304081, 0.000307528, 0.000304521, 0.000300306, 0.000304041,
//                        0.000305679, 0.000306825, 0.000299247, 0.000299078, 0.000302568};   //372km 96.8
 double ybins7[nbins] = {0.000195423, 0.000195908, 0.0001964, 0.000197496, 0.000197799, 0.0001979261, 0.000198079,
                         0.000194112, 0.000197152, 0.0001975, 0.000198377, 0.000201691};   //420km 51.6
// double eybins7[nbins] = {8.50534e-05, 8.73295e-05, 6.91618e-05, 7.89301e-05, 8.31751e-05, 7.79763e-05, 8.10433e-05,
//                          8.50534e-05, 8.73295e-05, 8.86795e-05, 8.93295e-05, 8.83295e-05}; //372km 96.8
 double eybins7[nbins] = {5.32264e-05, 5.01521e-05, 5.4261e-05, 6.19881e-05, 5.94049e-05, 5.08758e-05, 4.40806e-05,
                          6.21344e-05, 6.92735e-05, 0.00010214, 9.13265e-05, 0.000117744}; //420km 51.6


 for ( int i = 0; i < nbins; i++ )
 {
  ybins[i] = 0.87*ybins[i]*1.e6;      // rho=15g/cm^2 iso trapped protons GCR protons He C O Fe dose
  eybins[i] = 1.0*eybins[i]*1.e6;      // rho=15g/cm^2 iso trapped protons GCR protons He C O Fe error
//  ybins[i] = 0.9*ybins[i];     // for 372km 51.6 degree

  ybins1[i] = ybins1[i]*1.e6;      // rho=1.5g/cm^2 iso trapped protons GCR protons He C O Fe dose
  eybins1[i] = 1.0*eybins1[i]*1.e6;      // rho=1.5g/cm^2 iso trapped protons GCR protons He C O Fe error
  ybins1[i] = 0.9*ybins1[i];     // for 372km 51.6 degree

  ybins2[i] = ybins2[i]*1.e6;      // rho=15g/cm^2 iso GCR protons He C O Fe dose
  eybins2[i] = 0.5*eybins2[i]*1.e6;      // rho=15g/cm^2 iso GCR protons He C O Fe error

  ybins3[i] = ybins3[i]*1.e6;      // rho=1.5g/cm^2 iso GCR protons He C O Fe dose
  eybins3[i] = 0.5*eybins3[i]*1.e6;      // rho=1.5g/cm^2 iso GCR protons He C O Fe error

  ybins4[i] = ybins4[i]*1.e6;      // rho=15g/cm^2 iso trapped protons GCR protons He C O Fe eg. dose
  eybins4[i] = 0.1*eybins4[i]*1.e6;      // rho=15g/cm^2 iso trapped protons GCR protons He C O Fe error

  ybins5[i] = ybins5[i]*1.e6;      // rho=1.5g/cm^2 iso trapped protons GCR protons He C O Fe eq. dose
  eybins5[i] = 0.1*eybins5[i]*1.e6;      // rho=1.5g/cm^2 iso trapped protons GCR protons He C O Fe error

  ybins6[i] = ybins6[i]*1.e6;      // rho=15g/cm^2 iso GCR protons He C O Fe eq. dose
  eybins6[i] = 0.2*eybins6[i]*1.e6;      // rho=15g/cm^2 iso GCR protons He C O Fe error

  ybins7[i] = ybins7[i]*1.e6;      // rho=1.5g/cm^2 iso GCR protons He C O Fe eq. dose
  eybins7[i] = 0.2*eybins7[i]*1.e6;      // rho=1.5g/cm^2 iso GCR protons He C O Fe error

//  cout<<"i ybins err ybins1 err1 "<<i<<" "<<ybins[i]<<" "<<eybins[i]<<" "<<ybins1[i]<<" "<<eybins1[1]<<endl;
//  cout<<"i ybins4 err ybins5 err1 "<<i<<" "<<ybins4[i]<<" "<<eybins4[i]<<" "<<ybins5[i]<<" "<<eybins5[1]<<endl;
  cout<<"i ybins4 err ybins5 err1 "<<i<<" "<<ybins4[i]/ybins[i]<<" "<<ybins5[i]/ybins1[i]<<endl;
  gTrap->SetPoint(i, xbins[i], ybins[i]);
  gTrap->SetPointError(i, 0, 1.*eybins[i]);
  gTrap1->SetPoint(i, xbins[i], ybins1[i]);
  gTrap1->SetPointError(i, 0, 1.*eybins1[i]);
  gTrap2->SetPoint(i, xbins[i], ybins2[i]);
  gTrap2->SetPointError(i, 0, 1.*eybins2[i]);
  gTrap3->SetPoint(i, xbins[i], ybins3[i]);
  gTrap3->SetPointError(i, 0, 1.*eybins3[i]);

  gTrap4->SetPoint(i, xbins[i], ybins4[i]);
  gTrap4->SetPointError(i, 0, 1.*eybins4[i]);
  gTrap5->SetPoint(i, xbins[i], ybins5[i]);
  gTrap5->SetPointError(i, 0, 1.*eybins5[i]);
  gTrap6->SetPoint(i, xbins[i], ybins6[i]);
  gTrap6->SetPointError(i, 0, 1.*eybins6[i]);
  gTrap7->SetPoint(i, xbins[i], ybins7[i]);
  gTrap7->SetPointError(i, 0, 1.*eybins7[i]);

 }
 auto mg = new TMultiGraph();
 mg->Add(gTrap); //dose trap + GCR
 mg->Add(gTrap1); //dose trap + GCR
 mg->Add(gTrap2); //dose GCR
 mg->Add(gTrap3); //dose GCR
// mg->Add(gTrap4); //eq. dose trap + GCR
// mg->Add(gTrap5); //eq. dose trap + GCR
// mg->Add(gTrap6); //dose GCR
// mg->Add(gTrap7); //dose GCR
// mg->Add(gTrap_proton2); //eq dose trap + GCR
// mg->Add(gTrap_proton3); // eq dose trap + GCR
// mg->Add(gTrap_proton4);   // k trap + GCR
// mg->Add(gTrap_proton5);   // k trap + GCR
// mg->Add(gTrap_proton6);  //dose GCR
// mg->Add(gTrap_proton7);  // dose GCR
// mg->Add(gTrap_proton8); //eq dose GCR
// mg->Add(gTrap_proton9); // eq dose GCR
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
// mg->GetYaxis()->SetRangeUser(80, 470);
// mg->GetYaxis()->SetRangeUser(150, 950);
 mg->GetYaxis()->SetRangeUser(0, 950);
 mg->GetYaxis()->SetRangeUser(0, 550);
 mg->GetXaxis()->SetRangeUser(-0.5, 12.0);
// mg->GetYaxis()->SetRangeUser(50, 1200);
 mg->GetHistogram()->SetYTitle("D (#muGy day^{-1})");
// mg->GetYaxis()->SetRangeUser(0., 900.);
// mg->GetYaxis()->SetRangeUser(0., 1200.);
// mg->GetHistogram()->SetYTitle("D_{eq} (#muSv day^{-1})");
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
 legend->AddEntry(gTrap4,"h_{ht}^{min} = 10#frac{g}{cm^{2}} RPZ + GCR","p");
 legend->AddEntry(gTrap5,"h_{ht}^{min} = 1.5#frac{g}{cm^{2}} RPZ + GCR","p");
 legend->AddEntry(gTrap6,"h_{ht}^{min} = 10#frac{g}{cm^{2}} RPZ + GCR","p");
 legend->AddEntry(gTrap7,"h_{ht}^{min} = 1.5#frac{g}{cm^{2}} RPZ + GCR","p");
// legend->AddEntry(gTrap_proton8,"h_{ht}^{min} = 10#frac{g}{cm^{2}} RPZ + GCR","p");
// legend->AddEntry(gTrap_proton9,"h_{ht}^{min} = 1.5#frac{g}{cm^{2}} GCR","p");
// legend->AddEntry(hh1,"water+alu+polyprop","p");
// legend->AddEntry("","water+alu+polyprop","");
// legend->AddEntry(hh2,"water+alu+polyprop+shielding(1cm) ","p");
 legend->Draw();

}
