void new_comp(string variable = "pt") {

// A program to compare the two contributions: standard (2 bins) and new
// (3 bins).
cout << "This program compares the " + variable + " variable for old and new.";


TFile *file2040 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/firstTests/20-40/output_numEvent10000.root");
TTree *fake2040 = (TTree*)file2040->Get("photonDumper/trees/_13TeV_fakePhotons");
TTree *prompt2040 = (TTree*)file2040->Get("photonDumper/trees/_13TeV_promptPhotons");

TFile *file4080 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/firstTests/40-80/output_numEvent10000.root");
TTree *fake4080 = (TTree*)file4080->Get("photonDumper/trees/_13TeV_fakePhotons");
TTree *prompt4080 = (TTree*)file4080->Get("photonDumper/trees/_13TeV_promptPhotons");

TFile *file40Inf = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/firstTests/40-Inf/output_numEvent10000.root");
TTree *fake40Inf = (TTree*)file40Inf->Get("photonDumper/trees/_13TeV_fakePhotons");
TTree *prompt40Inf = (TTree*)file40Inf->Get("photonDumper/trees/_13TeV_promptPhotons");

//----------------------------------------------
// Fake photons
//----------------------------------------------

const char *vari = variable.c_str();
title_str = variable + " (fake)";
const char *title = title_str.c_str();

// First 
static Float_t energy_f2040;

TBranch *b_energy_f2040 = fake2040->GetBranch(vari);
b_energy_f2040->SetAddress(&energy_f2040);

// Second
static Float_t energy_f4080;

TBranch *b_energy_f4080 = fake4080->GetBranch(vari);
b_energy_f4080->SetAddress(&energy_f4080);

// Third
static Float_t energy_f40Inf;

TBranch *b_energy_f40Inf = fake40Inf->GetBranch(vari);
b_energy_f40Inf->SetAddress(&energy_f40Inf);


// ----- First histo (fake) ----- // 

// max and min are redefined (commented) throughout the code for every histo,
// this is not necessarily useful

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

// ----- Second histo (fake) ----- //


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


// ----- Third histo (fake) ----- // 

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

// Add the respective histograms

// Old sample: 2040 + 40Inf
// New sample: 2040 + 40Inf + 4080

//definitions of old and new, respectively
henergy_f2040->Add(henergy_f40Inf);
henergy_f4080->Add(henergy_f2040);

// ############# SCALE ############# //

Double_t norm = henergy_f4080->GetEntries();
henergy_f4080->Scale(1/norm);

// ############# END SCALE ############# //

// Draw, set title (?) and update
TCanvas *c1 = new TCanvas("c1","c1",1000,600);
c1->Divide(2,1);
c1->cd(1);
gStyle->SetOptStat(0);
henergy_f4080->SetLineColor(kRed);
henergy_f4080->Draw();

c1->Update();

// ############# SCALE ############# //

norm = henergy_f2040->GetEntries();
henergy_f2040->Scale(1/norm);

// ############# END SCALE ############# //

// Set canvas and draw; update

henergy_f2040->Draw("same");
c1->Update();

// Tried (but failed) to set the x axis title
//henergy_f40Inf->GetXaxis()->SetTitle("SCRawE");

// Legend
leg1 = new TLegend(0.45,0.7,0.9,0.9);
leg1->SetHeader("GJet bin");
leg1->AddEntry(henergy_f2040,"Standard (pt20-40 + pt40-Inf)","l");
leg1->AddEntry(henergy_f4080,"New (40-80 + pt20-40 + pt40-Inf)","l");
leg1->Draw();


//----------------------------------------------
// Prompt photons
//----------------------------------------------


c1->cd(2);

title_str = variable + " (prompt)";
title = title_str.c_str();


// First
static Float_t energy_p2040;

TBranch *b_energy_p2040 = prompt2040->GetBranch(vari);
b_energy_p2040->SetAddress(&energy_p2040);

// Second
static Float_t energy_p4080;

TBranch *b_energy_p4080 = prompt4080->GetBranch(vari);
b_energy_p4080->SetAddress(&energy_p4080);

// Third
static Float_t energy_p40Inf;

TBranch *b_energy_p40Inf = prompt40Inf->GetBranch(vari);
b_energy_p40Inf->SetAddress(&energy_p40Inf);


// ----- First histo (prompt) ----- //

//max = prompt2040->GetMaximum(vari);
//min = prompt2040->GetMinimum(vari);

  //create one histogram
  TH1F *henergy_p2040 = new TH1F("henergy_p2040",title,100,min,max);
  //read only the destep branch for all entries
  Int_t nentries_p2040 = (Int_t)prompt2040->GetEntries();
  for (Int_t i=0;i<nentries_p2040;i++) {
    b_energy_p2040->GetEntry(i);
    // fill the histogram with the destep entry 
    henergy_p2040->Fill(energy_p2040);
  }

// ----- Second histo (prompt) ----- //

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

// ----- Third histo (prompt) ----- //

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

// Add the respective histograms

// Old sample: 2040 + 40Inf
// New sample: 2040 + 40Inf + 4080

//definitions of old and new, respectively
henergy_p2040->Add(henergy_p40Inf);
henergy_p4080->Add(henergy_p2040);

// ############# SCALE ############# //

norm = henergy_p4080->GetEntries();
henergy_p4080->Scale(1/norm);

// ############# END SCALE ############# //


// Draw, set title (?) and update
henergy_p4080->SetLineColor(kRed);
henergy_p4080->Draw();
gStyle->SetOptStat(0);

c1->Update();

// ############# SCALE ############# //

norm = henergy_p2040->GetEntries();
henergy_p2040->Scale(1/norm);

// ############# END SCALE ############# //


// Set canvas and draw; update
henergy_p2040->Draw("same");

c1->Update();

// Tried (but failed) to set the x axis title
//henergy_f40Inf->GetXaxis()->SetTitle("SCRawE");

// Legend
leg2 = new TLegend(0.45,0.7,0.9,0.9);
leg2->SetHeader("GJet bin");
leg2->AddEntry(henergy_p2040,"Standard (pt20-40 + pt40-Inf)","l");
leg2->AddEntry(henergy_p4080,"New (40-80 + pt20-40 + pt40-Inf)","l");
leg2->Draw();


if (gROOT->IsBatch()) return;
}
