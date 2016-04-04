void comparison(string variable = "pt") {

//----------------------------------------------
// Fake photons
//----------------------------------------------

const char *vari = variable.c_str();
title_str = variable + " (fake)";
const char *title = title_str.c_str();

// ----- First histo (fake) ----- // 

TFile *file2040 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/firstTests/20-40/output_numEvent10000.root");
TTree *fake2040 = (TTree*)file2040->Get("photonDumper/trees/_13TeV_fakePhotons");

static Float_t energy_f2040;

TBranch *b_energy_f2040 = fake2040->GetBranch(vari);
b_energy_f2040->SetAddress(&energy_f2040);

// max and min are redefined (commented) throughout the code for every histo,
// but this is not necessarily useful

Double_t max = fake2040->GetMaximum(vari);
Double_t min = fake2040->GetMinimum(vari);

  //create one histogram
  TH1F *henergy_f2040 = new TH1F("henergy_f2040",title,100,min,max);
  //read only the destep branch for all entries
  Int_t nentries_f2040 = (Int_t)fake2040->GetEntries();
  for (Int_t i=0;i<nentries_f2040;i++) {
    b_energy_f2040->GetEntry(i);
    // fill the histogram with the destep entry 
    henergy_f2040->Fill(energy_f2040);
  }

// Set canvas and draw; update
TCanvas *c1 = new TCanvas("c1","c1",1000,600);
c1->Divide(2,1);
c1->cd(1);
henergy_f2040->Draw();
gStyle->SetOptStat(0);

c1->Update();

// ----- Second histo (fake) ----- //


TFile *file4080 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/firstTests/40-80/output_numEvent10000.root");
TTree *fake4080 = (TTree*)file4080->Get("photonDumper/trees/_13TeV_fakePhotons");

static Float_t energy_f4080;

TBranch *b_energy_f4080 = fake4080->GetBranch(vari);
b_energy_f4080->SetAddress(&energy_f4080);


//max = fake4080->GetMaximum(vari);
//min = fake4080->GetMinimum(vari);

  //create one histogram
  TH1F *henergy_f4080 = new TH1F("henergy_f4080",title,100,min,max);
  //read only the destep branch for all entries
  Int_t nentries_f4080 = (Int_t)fake4080->GetEntries();
  for (Int_t i=0;i<nentries_f4080;i++) {
    b_energy_f4080->GetEntry(i);
    // fill the histogram with the destep entry 
    henergy_f4080->Fill(energy_f4080);
  }

// Draw and update
henergy_f4080->SetLineColor(kRed);
henergy_f4080->Draw("same");

c1->Update();

// ----- Third histo (fake) ----- // 


TFile *file40Inf = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/firstTests/40-Inf/output_numEvent10000.root");
TTree *fake40Inf = (TTree*)file40Inf->Get("photonDumper/trees/_13TeV_fakePhotons");

static Float_t energy_f40Inf;

TBranch *b_energy_f40Inf = fake40Inf->GetBranch(vari);
b_energy_f40Inf->SetAddress(&energy_f40Inf);

//max = fake40Inf->GetMaximum(vari);
//min = fake40Inf->GetMinimum(vari);

  //create one histogram
  TH1F *henergy_f40Inf = new TH1F("henergy_f40Inf",title,100,min,max);
  //read only the destep branch for all entries
  Int_t nentries_f40Inf = (Int_t)fake40Inf->GetEntries();
  for (Int_t i=0;i<nentries_f40Inf;i++) {
    b_energy_f40Inf->GetEntry(i);
    // fill the histogram with the destep entry 
    henergy_f40Inf->Fill(energy_f40Inf);
  }

// Draw, set title (?) and update
henergy_f40Inf->SetLineColor(kGreen);
henergy_f40Inf->SetTitle("box1;x;y");
henergy_f40Inf->Draw("same");

c1->Update();

// Tried (but failed) to set the x axis title
//henergy_f40Inf->GetXaxis()->SetTitle("SCRawE");

// Legend
leg1 = new TLegend(0.7,0.7,0.9,0.9);
leg1->SetHeader("GJet bin");
leg1->AddEntry(henergy_f4080,"40-80","l");
leg1->AddEntry(henergy_f2040,"Inf_Pt20-40","l");
leg1->AddEntry(henergy_f40Inf,"Inf_Pt40-Inf","l");
leg1->Draw();


//----------------------------------------------
// Prompt photons
//----------------------------------------------


c1->cd(2);

title_str = variable + " (prompt)";
title = title_str.c_str();

// ----- First histo (prompt) ----- //

TTree *prompt2040 = (TTree*)file2040->Get("photonDumper/trees/_13TeV_promptPhotons");

static Float_t energy_p2040;

TBranch *b_energy_p2040 = prompt2040->GetBranch(vari);
b_energy_p2040->SetAddress(&energy_p2040);

max = prompt2040->GetMaximum(vari);
min = prompt2040->GetMinimum(vari);

  //create one histogram
  TH1F *henergy_p2040 = new TH1F("henergy_p2040",title,100,min,max);
  //read only the destep branch for all entries
  Int_t nentries_p2040 = (Int_t)prompt2040->GetEntries();
  for (Int_t i=0;i<nentries_p2040;i++) {
    b_energy_p2040->GetEntry(i);
    // fill the histogram with the destep entry 
    henergy_p2040->Fill(energy_p2040);
  }

// Draw and update
henergy_p2040->Draw();
c1->Update();

// ----- Second histo (prompt) ----- //

TTree *prompt4080 = (TTree*)file4080->Get("photonDumper/trees/_13TeV_promptPhotons");

static Float_t energy_p4080;

TBranch *b_energy_p4080 = prompt4080->GetBranch(vari);
b_energy_p4080->SetAddress(&energy_p4080);

//max = prompt4080->GetMaximum(vari);
//min = prompt4080->GetMinimum(vari);

  //create one histogram
  TH1F *henergy_p4080 = new TH1F("henergy_p4080",title,100,min,max);
  //read only the destep branch for all entries
  Int_t nentries_p4080 = (Int_t)prompt4080->GetEntries();
  for (Int_t i=0;i<nentries_p4080;i++) {
    b_energy_p4080->GetEntry(i);
    // fill the histogram with the destep entry 
    henergy_p4080->Fill(energy_p4080);
  }

// Draw and update
henergy_p4080->SetLineColor(kRed);
henergy_p4080->Draw("same");

c1->Update();

// ----- Third histo (prompt) ----- //

TTree *prompt40Inf = (TTree*)file40Inf->Get("photonDumper/trees/_13TeV_promptPhotons");
static Float_t energy_p40Inf;
TBranch *b_energy_p40Inf = prompt40Inf->GetBranch(vari);
b_energy_p40Inf->SetAddress(&energy_p40Inf);


//max = prompt40Inf->GetMaximum(vari);
//min = prompt40Inf->GetMinimum(vari);

  //create one histogram
  TH1F *henergy_p40Inf = new TH1F("henergy_p40Inf",title,100,min,max);
  //read only the destep branch for all entries
  Int_t nentries_p40Inf = (Int_t)prompt40Inf->GetEntries();
  for (Int_t i=0;i<nentries_p40Inf;i++) {
    b_energy_p40Inf->GetEntry(i);
    // fill the histogram
    henergy_p40Inf->Fill(energy_p40Inf);
  }

// Draw and update
henergy_p40Inf->SetLineColor(kGreen);
henergy_p40Inf->GetXaxis()->SetTitle("SCRawE");
henergy_p40Inf->Draw("same");

//henergy_p40Inf->GetXaxis()->SetTitle("SCRawE");

c1->Update();

// Legend
leg2 = new TLegend(0.7,0.7,0.9,0.9);
leg2->SetHeader("GJet bin");
leg2->AddEntry(henergy_f4080,"40-80","l");
leg2->AddEntry(henergy_f2040,"Inf_Pt20-40","l");
leg2->AddEntry(henergy_f40Inf,"Inf_Pt40-Inf","l");
//leg2->Draw("same");
leg2->Draw();


if (gROOT->IsBatch()) return;
}
