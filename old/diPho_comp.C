void diPho_comp(string variable = "pt", bool normalization = true) {                                         

// A program for comparing the old and new samples for a variable, separated in
// EE and EB histograms for fake and prompt.
//
cout << "This program compares the variable " + variable + " for old and new\
 samples" << endl;


const char *vari = variable.c_str();                                            
                                                                                
//TFile *file2040 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/\
src/diPhoton/20-40/output_numEvent40000.root");
TFile *file2040 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/output_GJet_mgg80Inf_pt2040.root");
TTree *fakeEB2040 = (TTree*)file2040->Get("photonViewDumper/trees/fakePhotonsEB");
TTree *fakeEE2040 = (TTree*)file2040->Get("photonViewDumper/trees/fakePhotonsEE");
TTree *promptEB2040 = (TTree*)file2040->Get("photonViewDumper/trees/promptPhotonsEB");
TTree *promptEE2040 = (TTree*)file2040->Get("photonViewDumper/trees/promptPhotonsEE");
                                                                                
//TFile *file4080 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/\
src/diPhoton/40-80/output_numEvent40000.root");
TFile *file4080 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/output_GJet_mgg4080.root");
TTree *fakeEB4080 = (TTree*)file4080->Get("photonViewDumper/trees/fakePhotonsEB");
TTree *fakeEE4080 = (TTree*)file4080->Get("photonViewDumper/trees/fakePhotonsEE");
TTree *promptEB4080 = (TTree*)file4080->Get("photonViewDumper/trees/promptPhotonsEB");
TTree *promptEE4080 = (TTree*)file4080->Get("photonViewDumper/trees/promptPhotonsEE");
                                                                                
//TFile *file40Inf = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/\
src/diPhoton/40-Inf/output_numEvent40000.root");
TFile *file40Inf = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/output_GJet_mgg8OInf_Pt40Inf");
TTree *fakeEB40Inf = (TTree*)file40Inf->Get("photonViewDumper/trees/fakePhotonsEB");
TTree *fakeEE40Inf = (TTree*)file40Inf->Get("photonViewDumper/trees/fakePhotonsEE");
TTree *promptEB40Inf = (TTree*)file40Inf->Get("photonViewDumper/trees/promptPhotonsEB");
TTree *promptEE40Inf = (TTree*)file40Inf->Get("photonViewDumper/trees/promptPhotonsEE");
                                                                                
//----------------------------------------------                                
// Fake photons (EB)                                                                 
//----------------------------------------------                                
                                                                                
//const char *vari = variable.c_str();                                            
title_str = variable + " (fake) in EB";                                               
const char *title = title_str.c_str();                                          
                                                                                
// First                                                                        
static Float_t energy_fEB2040;                                                    
                                                                                
TBranch *b_energy_fEB2040 = fakeEB2040->GetBranch(vari);                            
b_energy_fEB2040->SetAddress(&energy_fEB2040);                                      
                                                                                
// Second                                                                       
static Float_t energy_fEB4080;                                                    
                                                                                
TBranch *b_energy_fEB4080 = fakeEB4080->GetBranch(vari);                            
b_energy_fEB4080->SetAddress(&energy_fEB4080);                                      
                                                                                
// Third                                                                        
static Float_t energy_fEB40Inf;                                                   
                                                                                
TBranch *b_energy_fEB40Inf = fakeEB40Inf->GetBranch(vari);                          
b_energy_fEB40Inf->SetAddress(&energy_fEB40Inf);                                    
                                                                                
                                                                                
// ----- First histo (fake) ----- //                                            
                                                                                
// max and min are redefined (commented) throughout the code for every histo,   
// this is not necessarily useful                                               
                                                                                
Double_t max_EB = fakeEB2040->GetMaximum(vari);                                      
Double_t min_EB = fakeEB2040->GetMinimum(vari);                                      
                                                                                
  //create one histogram                                                        
  TH1F *henergy_fEB2040 = new TH1F("henergy_fEB2040",title,100,min_EB,max_EB);            
  //read only the destep branch for all entries                                 
  Int_t nentries_fEB2040 = (Int_t)fakeEB2040->GetEntries();                         
  for (Int_t i=0;i<nentries_fEB2040;i++) {                                        
    b_energy_fEB2040->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_fEB2040->Fill(energy_fEB2040);                                          
  }                                                                             
                                                                                
// ----- Second histo (fake) ----- //                                           
                                                                                
                                                                                
//max_EB = fakeEB4080->GetMaximum(vari);                                             
//min_EB = fakeEB4080->GetMinimum(vari);                                             
                                                                                
  //create one histogram                                                        
  TH1F *henergy_fEB4080 = new TH1F("henergy_fEB4080",title,100,min_EB,max_EB);            
  //read only the destep branch for all entries                                 
  Int_t nentries_fEB4080 = (Int_t)fakeEB4080->GetEntries();                         
  for (Int_t i=0;i<nentries_fEB4080;i++) {                                        
    b_energy_fEB4080->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_fEB4080->Fill(energy_fEB4080);                                          
  }                                                                             
                                                                                
                                                                                
// ----- Third histo (fake) ----- //                                            
                                                                                
//max_EB = fakeEB40Inf->GetMaximum(vari);                                            
//min_EB = fakeEB40Inf->GetMinimum(vari);                                            
                                                                                
  //create one histogram                                                        
  TH1F *henergy_fEB40Inf = new TH1F("henergy_fEB40Inf",title,100,min_EB,max_EB);          
  //read only the destep branch for all entries                                 
  Int_t nentries_fEB40Inf = (Int_t)fakeEB40Inf->GetEntries();                       
  for (Int_t i=0;i<nentries_fEB40Inf;i++) {                                       
    b_energy_fEB40Inf->GetEntry(i);                                               
    // fill the histogram with the destep entry                                 
    henergy_fEB40Inf->Fill(energy_fEB40Inf);                                        
  }                                                                             
                                                                                
// Add the respective histograms                                                
                                                                                
// Old sample: 2040 + 40Inf                                                     
// New sample: 2040 + 40Inf + 4080                                              
                                                                                
//definitions of old and new, respectively                                      
henergy_fEB2040->Add(henergy_fEB40Inf);                                             
henergy_fEB4080->Add(henergy_fEB2040);                                              
                                                                                
// Set canvas and draw; update                                                  
//TCanvas *c1 = new TCanvas("c1","c1",1000,600);                                  
TCanvas *c1 = new TCanvas("c1","c1",1000,600);                                  
c1->Divide(2,2);                                                                
c1->cd(1);                                                                      

Double_t norm = henergy_fEB2040->GetEntries();

// First plot
if (normalization == true) {
  henergy_fEB2040->Scale(1/norm);
  }
                                                                                

henergy_fEB2040->Draw();                                                          
gStyle->SetOptStat(0);                                                          
                                                                                
c1->Update();                                                                   

// Second plot
if (normalization == true) {
  norm = henergy_fEB4080->GetEntries();                                             
  henergy_fEB4080->Scale(1/norm);                                                   
  }

// Draw, set title (?) and update                                               
henergy_fEB4080->SetLineColor(kRed);                                              
henergy_fEB4080->Draw("same");                                                    
                                                                                
c1->Update();                                                                   

Double_t max_2040 = henergy_fEB2040->GetMaximum();
Double_t max_4080 = henergy_fEB4080->GetMaximum();

Double_t total_max = TMath::Max(max_2040, max_4080);
henergy_fEB2040->SetMaximum(total_max);
henergy_fEB4080->SetMaximum(total_max);


//cout << "This is the Maximum of 2040: " << max_2040 << "." << endl;
                                                                                
// Tried (but failed) to set the x axis title                                   
//henergy_fEB40Inf->GetXaxis()->SetTitle("SCRawE");                               
                                                                                
// Legend                                                                       
leg1 = new TLegend(0.6,0.7,0.9,0.9);                                           
leg1->SetHeader("GJet bin");                                                    
leg1->AddEntry(henergy_fEB2040,"pt20-40 + pt40-Inf","l");              
leg1->AddEntry(henergy_fEB4080,"40-80 + pt20-40 + pt40-Inf","l");           
leg1->Draw();                                                                   




//----------------------------------------------                                
// Fake photons (EE)                                                                 
//----------------------------------------------                                
                                                                                
title_str = variable + " (fake) in EE";                                               
title = title_str.c_str();                                          
                                                                                
// First                                                                        
static Float_t energy_fEE2040;                                                    
                                                                                
TBranch *b_energy_fEE2040 = fakeEE2040->GetBranch(vari);                            
b_energy_fEE2040->SetAddress(&energy_fEE2040);                                      
                                                                                
// Second                                                                       
static Float_t energy_fEE4080;                                                    
                                                                                
TBranch *b_energy_fEE4080 = fakeEE4080->GetBranch(vari);                            
b_energy_fEE4080->SetAddress(&energy_fEE4080);                                      
                                                                                
// Third                                                                        
static Float_t energy_fEE40Inf;                                                   
                                                                                
TBranch *b_energy_fEE40Inf = fakeEE40Inf->GetBranch(vari);                          
b_energy_fEE40Inf->SetAddress(&energy_fEE40Inf);                                    
                                                                                
                                                                                
// ----- First histo (fake) ----- //                                            
                                                                                
// max_EE and min_EE are redefined (commented) throughout the code for every histo,   
// this is not necessarily useful                                               
                                                                                
Double_t max_EE = fakeEE2040->GetMaximum(vari);                                      
Double_t min_EE = fakeEE2040->GetMinimum(vari);                                      
                                                                                
  //create one histogram                                                        
  TH1F *henergy_fEE2040 = new TH1F("henergy_fEE2040",title,100,min_EE,max_EE);            
  //read only the destep branch for all entries                                 
  Int_t nentries_fEE2040 = (Int_t)fakeEE2040->GetEntries();                         
  for (Int_t i=0;i<nentries_fEE2040;i++) {                                        
    b_energy_fEE2040->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_fEE2040->Fill(energy_fEE2040);                                          
  }                                                                             
                                                                                
// ----- Second histo (fake) ----- //                                           
                                                                                
                                                                                
//max_EE = fakeEE4080->GetMaximum(vari);                                             
//min_EE = fakeEE4080->GetMinimum(vari);                                             
                                                                                
  //create one histogram                                                        
  TH1F *henergy_fEE4080 = new TH1F("henergy_fEE4080",title,100,min_EE,max_EE);            
  //read only the destep branch for all entries                                 
  Int_t nentries_fEE4080 = (Int_t)fakeEE4080->GetEntries();                         
  for (Int_t i=0;i<nentries_fEE4080;i++) {                                        
    b_energy_fEE4080->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_fEE4080->Fill(energy_fEE4080);                                          
  }                                                                             
                                                                                
                                                                                
// ----- Third histo (fake) ----- //                                            
                                                                                
//max_EE = fakeEE40Inf->GetMaximum(vari);                                            
//min_EE = fakeEE40Inf->GetMinimum(vari);                                            
                                                                                
  //create one histogram                                                        
  TH1F *henergy_fEE40Inf = new TH1F("henergy_fEE40Inf",title,100,min_EE,max_EE);          
  //read only the destep branch for all entries                                 
  Int_t nentries_fEE40Inf = (Int_t)fakeEE40Inf->GetEntries();                       
  for (Int_t i=0;i<nentries_fEE40Inf;i++) {                                       
    b_energy_fEE40Inf->GetEntry(i);                                               
    // fill the histogram with the destep entry                                 
    henergy_fEE40Inf->Fill(energy_fEE40Inf);                                        
  }                                                                             
                                                                                
// Add the respective histograms                                                
                                                                                
// Old sample: 2040 + 40Inf                                                     
// New sample: 2040 + 40Inf + 4080                                              
                                                                                
//definitions of old and new, respectively                                      
henergy_fEE2040->Add(henergy_fEE40Inf);                                             
henergy_fEE4080->Add(henergy_fEE2040);                                              
                                                                                
if (normalization == true) {
  norm = henergy_fEE2040->GetEntries();                                    
  henergy_fEE2040->Scale(1/norm);                                                   
  }

// Set canvas and draw; update                                                  
c1->cd(2);                                                                      
henergy_fEE2040->Draw();                                                          
gStyle->SetOptStat(0);                                                          
                                                                                
c1->Update();                                                                   
                                                                                
if (normalization == true) {
  norm = henergy_fEE4080->GetEntries();                                             
  henergy_fEE4080->Scale(1/norm);                                                   
  }

// Draw, set title (?) and update                                               
henergy_fEE4080->SetLineColor(kRed);                                              
henergy_fEE4080->SetTitle("box1;x;y");                                            
henergy_fEE4080->Draw("same");                                                    
                                                                                
c1->Update();                                                                   
                                                                                
// Tried (but failed) to set the x axis title                                   
//henergy_fEE40Inf->GetXaxis()->SetTitle("SCRawE");                               


max_2040 = henergy_fEE2040->GetMaximum();
max_4080 = henergy_fEE4080->GetMaximum();

total_max = TMath::Max(max_2040, max_4080);
henergy_fEE2040->SetMaximum(total_max);
henergy_fEE4080->SetMaximum(total_max);


// Legend                                                                       
leg2 = new TLegend(0.6,0.7,0.9,0.9);                                           
leg2->SetHeader("GJet bin");                                                    
leg2->AddEntry(henergy_fEE2040,"pt20-40 + pt40-Inf","l");              
leg2->AddEntry(henergy_fEE4080,"40-80 + pt20-40 + pt40-Inf","l");           
leg2->Draw();                                                                   









                                                                                
//----------------------------------------------                                
// Prompt photons in EB                                                              
//----------------------------------------------                                
                                                                                
                                                                                
c1->cd(3);                                                                      
                                                                                
title_str = variable + " (prompt) in EB";                                             
title = title_str.c_str();                                                      
                                                                                
                                                                                
                                                                                
// First                                                                        
static Float_t energy_pEB2040;                                                    
                                                                                
TBranch *b_energy_pEB2040 = promptEB2040->GetBranch(vari);                          
b_energy_pEB2040->SetAddress(&energy_pEB2040);                                      
                                                                                
// Second                                                                       
static Float_t energy_pEB4080;                                                    
                                                                                
TBranch *b_energy_pEB4080 = promptEB4080->GetBranch(vari);                          
b_energy_pEB4080->SetAddress(&energy_pEB4080);                                      
                                                                                
// Third                                                                        
static Float_t energy_pEB40Inf;                                                   
                                                                                
TBranch *b_energy_pEB40Inf = promptEB40Inf->GetBranch(vari);                        
b_energy_pEB40Inf->SetAddress(&energy_pEB40Inf);                                    

// ----- First histo (prompt) ----- //                                          
                                                                                
// Comment this for the histograms to have the same size. Convenient for        
// visualization.                                                               
// max_EB = promptEB2040->GetMaximum(vari);                                          
// min_EB = promptEB2040->GetMinimum(vari);                                          
                                                                                
  //create one histogram                                                        
  TH1F *henergy_pEB2040 = new TH1F("henergy_pEB2040",title,100,min_EB,max_EB);            
  //read only the destep branch for all entries                                 
  Int_t nentries_pEB2040 = (Int_t)promptEB2040->GetEntries();                       
  for (Int_t i=0;i<nentries_pEB2040;i++) {                                        
    b_energy_pEB2040->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_pEB2040->Fill(energy_pEB2040);                                          
  }                                                                             
                                                                                
// ----- Second histo (prompt) ----- //                                         
                                                                                
//max_EB = promptEB4080->GetMaximum(vari);                                           
//min_EB = promptEB4080->GetMinimum(vari);                                           
                                                                                
  //create one histogram                                                        
  TH1F *henergy_pEB4080 = new TH1F("henergy_pEB4080",title,100,min_EB,max_EB);            
  //read only the destep branch for all entries                                 
  Int_t nentries_pEB4080 = (Int_t)promptEB4080->GetEntries();                       
  for (Int_t i=0;i<nentries_pEB4080;i++) {                                        
    b_energy_pEB4080->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_pEB4080->Fill(energy_pEB4080);                                          
  }                                                                             
                                                                                
// ----- Third histo (prompt) ----- //                                          
                                                                                
//max_EB = promptEB40Inf->GetMaximum(vari);                                          
//min_EB = promptEB40Inf->GetMinimum(vari);                                          
                                                                                
  //create one histogram                                                        
  TH1F *henergy_pEB40Inf = new TH1F("henergy_pEB40Inf",title,100,min_EB,max_EB);          
  //read only the destep branch for all entries                                 
  Int_t nentries_pEB40Inf = (Int_t)promptEB40Inf->GetEntries();                     
  for (Int_t i=0;i<nentries_pEB40Inf;i++) {                                       
    b_energy_pEB40Inf->GetEntry(i);                                               
    // fill the histogram                                                       
    henergy_pEB40Inf->Fill(energy_pEB40Inf);                                        
  }                                                                             
                                                                                
// Add the respective histograms                                                
                                                                                
// Old sample: 2040 + 40Inf                                                     
// New sample: 2040 + 40Inf + 4080                                              
                                                                                
//definitions of old and new, respectively                                      
henergy_pEB2040->Add(henergy_pEB40Inf);                                             
henergy_pEB4080->Add(henergy_pEB2040);                                              
                                                                                
if (normalization == true) {
  norm = henergy_pEB2040->GetEntries();                                             
  henergy_pEB2040->Scale(1/norm);                                                   
  }

// Set canvas and draw; update                                                  
henergy_pEB2040->Draw();                                                          
gStyle->SetOptStat(0);                                                          
                                                                                
c1->Update();                                                                   
                                                                                
if (normalization == true) {
  norm = henergy_pEB4080->GetEntries();                                             
  henergy_pEB4080->Scale(1/norm);                                                   
  }

// Draw, set title (?) and update                                               
henergy_pEB4080->SetLineColor(kRed);                                              
henergy_pEB4080->SetTitle("box1;x;y");                                            
henergy_pEB4080->Draw("same");                                                    
                                                                                
c1->Update();                                                                   
                                                                                
// Tried (but failed) to set the x axis title                                   
//henergy_fEB40Inf->GetXaxis()->SetTitle("SCRawE");                               
                                                                                
max_2040 = henergy_pEB2040->GetMaximum();
max_4080 = henergy_pEB4080->GetMaximum();

total_max = TMath::Max(max_2040, max_4080);
henergy_pEB2040->SetMaximum(total_max);
henergy_pEB4080->SetMaximum(total_max);

// Legend                                                                       
leg3 = new TLegend(0.6,0.7,0.9,0.9);                                           
leg3->SetHeader("GJet bin");                                                    
leg3->AddEntry(henergy_pEB2040,"pt20-40 + pt40-Inf","l");              
leg3->AddEntry(henergy_pEB4080,"40-80 + pt20-40 + pt40-Inf","l");           
leg3->Draw();                                                                   
                                                                                

//----------------------------------------------                                
// Prompt photons in EE                                                              
//----------------------------------------------                                
                                                                                
                                                                                
c1->cd(4);                                                                      
                                                                                
title_str = variable + " (prompt) in EE";                                             
title = title_str.c_str();                                                      
                                                                                
                                                                                
                                                                                
// First                                                                        
static Float_t energy_pEE2040;                                                    
                                                                                
TBranch *b_energy_pEE2040 = promptEE2040->GetBranch(vari);                          
b_energy_pEE2040->SetAddress(&energy_pEE2040);                                      
                                                                                
// Second                                                                       
static Float_t energy_pEE4080;                                                    
                                                                                
TBranch *b_energy_pEE4080 = promptEE4080->GetBranch(vari);                          
b_energy_pEE4080->SetAddress(&energy_pEE4080);                                      
                                                                                
// Third                                                                        
static Float_t energy_pEE40Inf;                                                   
                                                                                
TBranch *b_energy_pEE40Inf = promptEE40Inf->GetBranch(vari);                        
b_energy_pEE40Inf->SetAddress(&energy_pEE40Inf);                                    

// ----- First histo (prompt) ----- //                                          
                                                                                
// Comment this for the histograms to have the same size. Convenient for        
// visualization.                                                               
// max_EE = promptEE2040->GetMaximum(vari);                                          
// min_EE = promptEE2040->GetMinimum(vari);                                          
                                                                                
  //create one histogram                                                        
  TH1F *henergy_pEE2040 = new TH1F("henergy_pEE2040",title,100,min_EE,max_EE);            
  //read only the destep branch for all entries                                 
  Int_t nentries_pEE2040 = (Int_t)promptEE2040->GetEntries();                       
  for (Int_t i=0;i<nentries_pEE2040;i++) {                                        
    b_energy_pEE2040->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_pEE2040->Fill(energy_pEE2040);                                          
  }                                                                             
                                                                                
// ----- Second histo (prompt) ----- //                                         
                                                                                
//max_EE = promptEE4080->GetMaximum(vari);                                           
//min_EE = promptEE4080->GetMinimum(vari);                                           
                                                                                
  //create one histogram                                                        
  TH1F *henergy_pEE4080 = new TH1F("henergy_pEE4080",title,100,min_EE,max_EE);            
  //read only the destep branch for all entries                                 
  Int_t nentries_pEE4080 = (Int_t)promptEE4080->GetEntries();                       
  for (Int_t i=0;i<nentries_pEE4080;i++) {                                        
    b_energy_pEE4080->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_pEE4080->Fill(energy_pEE4080);                                          
  }                                                                             
                                                                                
// ----- Third histo (prompt) ----- //                                          
                                                                                
//max_EE = promptEE40Inf->GetMaximum(vari);                                          
//min_EE = promptEE40Inf->GetMinimum(vari);                                          
                                                                                
  //create one histogram                                                        
  TH1F *henergy_pEE40Inf = new TH1F("henergy_pEE40Inf",title,100,min_EE,max_EE);          
  //read only the destep branch for all entries                                 
  Int_t nentries_pEE40Inf = (Int_t)promptEE40Inf->GetEntries();                     
  for (Int_t i=0;i<nentries_pEE40Inf;i++) {                                       
    b_energy_pEE40Inf->GetEntry(i);                                               
    // fill the histogram                                                       
    henergy_pEE40Inf->Fill(energy_pEE40Inf);                                        
  }                                                                             
                                                                                
// Add the respective histograms                                                
                                                                                
// Old sample: 2040 + 40Inf                                                     
// New sample: 2040 + 40Inf + 4080                                              
                                                                                
//definitions of old and new, respectively                                      
henergy_pEE2040->Add(henergy_pEE40Inf);                                             
henergy_pEE4080->Add(henergy_pEE2040);                                              
                                                                                
if (normalization == true) {
  norm = henergy_pEE2040->GetEntries();                                             
  henergy_pEE2040->Scale(1/norm);                                                   
  }                                                                              

// Set canvas and draw; update                                                  
henergy_pEE2040->Draw();                                                          
gStyle->SetOptStat(0);                                                          
                                                                                
c1->Update();                                                                   
                                                                                
if (normalization == true) {
  norm = henergy_pEE4080->GetEntries();                                             
  henergy_pEE4080->Scale(1/norm);                                                   
  }

// Draw, set title (?) and update                                               
henergy_pEE4080->SetLineColor(kRed);                                              
henergy_pEE4080->SetTitle("box1;x;y");                                            
henergy_pEE4080->Draw("same");                                                    
                                                                                
c1->Update();                                                                   
                                                                                
// Tried (but failed) to set the x axis title                                   
//henergy_fEB40Inf->GetXaxis()->SetTitle("SCRawE");                               
                                                                                

max_2040 = henergy_pEE2040->GetMaximum();
max_4080 = henergy_pEE4080->GetMaximum();

total_max = TMath::Max(max_2040, max_4080);
henergy_pEE2040->SetMaximum(total_max);
henergy_pEE4080->SetMaximum(total_max);

// Legend                                                                       
leg4 = new TLegend(0.6,0.7,0.9,0.9);                                           
leg4->SetHeader("GJet bin");                                                    
leg4->AddEntry(henergy_pEE2040,"pt20-40 + pt40-Inf","l");              
leg4->AddEntry(henergy_pEE4080,"40-80 + pt20-40 + pt40-Inf","l");           
leg4->Draw();                                                                   

string output_str;
//if (normalization == false) output_str = "1MevtsWeighted_" + variable + "_Comparison.root";
//else output_str = "1MevtsWeighted_" + variable + "_NormComparison.root";

//if (normalization == false) output_str = "1MevtsWeighted_" + variable + "_Comparison.png";
if (!normalization) output_str = "1MevtsWeighted_" + variable + "_Comparison.png";
else output_str = "1MevtsWeighted_" + variable + "_NormComparison.png";


const char *output = output_str.c_str();

c1->SaveAs(output);

//hfile = new TFile(output,"RECREATE","ROOT file");
//hfile->Append(c1);

//hfile->Write();

if (gROOT->IsBatch()) return;                                                   
}                                                                               
