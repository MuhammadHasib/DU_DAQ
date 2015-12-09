Counts()
{
  gStyle->SetOptStat(1111);
  TCanvas *c1= new TCanvas("c1"," ");
//c1->Divide(1,3);
  ifstream in;
  in.open("data.txt");
  double a[103],b[103],c[103],d[103],e[103],f[103],effsg[103];
  TH1F *h1 = new TH1F("h1","Efficiency @ 10.8 kV",50,86,100);
/*TH1F *h2 = new TH1F("h2","Lower Paddle",30,800,1200);
TH1F *h3 = new TH1F("h3","Upper Paddle",30,900,1200);*/
 h1->GetXaxis()->SetTitle("Efficiency (%)");
 h1->GetYaxis()->SetTitle("Frequency");
 /*h2->GetXaxis()->SetTitle("No.of Counts");
 h2->GetYaxis()->SetTitle("Frequency");
 h3->GetXaxis()->SetTitle("No.of Counts");
 h3->GetYaxis()->SetTitle("Frequency");*/

 TF1 *f1 = new TF1("f1","gaus",80,100);
/* TF1 *f2 = new TF1("f2","gaus",860,1050);
 TF1 *f3 = new TF1("f3","gaus",900,1200);*/
  for(int i=0;i<103;i++)
    {
      in>>a[i]>>b[i]>>c[i]>>d[i]>>e[i]>>f[i];
       //cout<<a[i]<<endl;
      effsg[i]=(f[i]/d[i])*100;
	h1->Fill(effsg[i]);
	//h2->Fill(b[i]);
	//h3->Fill(c[i]);

	}
  h1->Fit(f1,"R");
  //h2->Fit(f2,"R");
  // h3->Fit(f3,"R");

  c1->cd(1);
   h1->Draw();
   //  c1->cd(2);
   // h2->Draw();
   //  c1->cd(3);
   // h3->Draw();
}
