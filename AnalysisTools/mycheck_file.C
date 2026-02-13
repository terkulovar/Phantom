#include <stdio.h>
#include <iostream>
//#include <string>
//#include <cstring>
void mycheck_file()
{
 for ( int i = 1; i <= 90; i++)
 {
  TString ss;
//  if ( i==13 || i==14 || i==37 || i==38 || i==43 || i==45 || i==48 || i==54 || i==56 ) continue;
  ss.Form("../build/matreshka_372km_96.8_gcr_%d.root",i);
//  ss.Form("../build/newsetup%d.root",i);
//  ss.Form("../build/oldsetup%d.root",i);
  cout<<"string "<<ss<<endl;
  auto f = new TFile(ss);
 }
}
