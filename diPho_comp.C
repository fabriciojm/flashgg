void diPho_comp(string variable = "pt") {                                         
                                                                                
const char *vari = variable.c_str();                                            
                                                                                
TFile *file2040 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/diPhoton/20-40/output_numEvent10000.root");
TTree *fakeEB2040 = (TTree*)file2040->Get("photonViewDumper/trees/fakePhotonsEB");
TTree *fakeEE2040 = (TTree*)file2040->Get("photonViewDumper/trees/fakePhotonsEE");
TTree *promptEB2040 = (TTree*)file2040->Get("photonViewDumper/trees/promptPhotonsEB");
TTree *promptEE2040 = (TTree*)file2040->Get("photonViewDumper/trees/promptPhotonsEE");
                                                                                
TFile *file4080 = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/diPhoton/40-80/output_numEvent10000.root");
TTree *fakeEB4080 = (TTree*)file4080->Get("photonViewDumper/trees/fakePhotonsEB");
TTree *fakeEE4080 = (TTree*)file4080->Get("photonViewDumper/trees/fakePhotonsEE");
TTree *promptEB4080 = (TTree*)file4080->Get("photonViewDumper/trees/promptPhotonsEB");
TTree *promptEE4080 = (TTree*)file4080->Get("photonViewDumper/trees/promptPhotonsEE");
                                                                                
TFile *file40Inf = new TFile("/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/diPhoton/40-Inf/output_numEvent10000.root");
TTree *fakeEB40Inf = (TTree*)file40Inf->Get("photonViewDumper/trees/fakePhotonsEB");
TTree *fakeEE40Inf = (TTree*)file40Inf->Get("photonViewDumper/trees/fakePhotonsEE");
TTree *promptEB40Inf = (TTree*)file40Inf->Get("photonViewDumper/trees/promptPhotonsEB");
TTree *promptEE40Inf = (TTree*)file40Inf->Get("photonViewDumper/trees/promptPhotonsEE");
                                                                                
//----------------------------------------------                                
// Fake photons (EB)                                                                 
//----------------------------------------------                                
                                                                                
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
                                                                                
Double_t max = fakeEB2040->GetMaximum(vari);                                      
Double_t min = fakeEB2040->GetMinimum(vari);                                      
                                                                                
  //create one histogram                                                        
  TH1F *henergy_fEB2040 = new TH1F("henergy_fEB2040",title,100,min,max);            
  //read only the destep branch for all entries                                 
  Int_t nentries_fEB2040 = (Int_t)fakeEB2040->GetEntries();                         
  for (Int_t i=0;i<nentries_fEB2040;i++) {                                        
    b_energy_fEB2040->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_fEB2040->Fill(energy_fEB2040);                                          
  }                                                                             
                                                                                
// ----- Second histo (fake) ----- //                                           
                                                                                
                                                                                
//max = fakeEB4080->GetMaximum(vari);                                             
//min = fakeEB4080->GetMinimum(vari);                                             
                                                                                
  //create one histogram                                                        
  TH1F *henergy_fEB4080 = new TH1F("henergy_fEB4080",title,100,min,max);            
  //read only the destep branch for all entries                                 
  Int_t nentries_fEB4080 = (Int_t)fakeEB4080->GetEntries();                         
  for (Int_t i=0;i<nentries_fEB4080;i++) {                                        
    b_energy_fEB4080->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_fEB4080->Fill(energy_fEB4080);                                          
  }                                                                             
                                                                                
                                                                                
// ----- Third histo (fake) ----- //                                            
                                                                                
//max = fakeEB40Inf->GetMaximum(vari);                                            
//min = fakeEB40Inf->GetMinimum(vari);                                            
                                                                                
  //create one histogram                                                        
  TH1F *henergy_fEB40Inf = new TH1F("henergy_fEB40Inf",title,100,min,max);          
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
                                                                                
Double_t norm = henergy_fEB2040->GetEntries();                                    
henergy_fEB2040->Scale(1/norm);                                                   
                                                                                
// Set canvas and draw; update                                                  
TCanvas *c1 = new TCanvas("c1","c1",1000,600);                                  
c1->Divide(2,1);                                                                
c1->cd(1);                                                                      
henergy_fEB2040->Draw();                                                          
gStyle->SetOptStat(0);                                                          
                                                                                
c1->Update();                                                                   
                                                                                
norm = henergy_fEB4080->GetEntries();                                             
henergy_fEB4080->Scale(1/norm);                                                   
                                                                                
// Draw, set title (?) and update                                               
henergy_fEB4080->SetLineColor(kRed);                                              
henergy_fEB4080->SetTitle("box1;x;y");                                            
henergy_fEB4080->Draw("same");                                                    
                                                                                
c1->Update();                                                                   
                                                                                
// Tried (but failed) to set the x axis title                                   
//henergy_fEB40Inf->GetXaxis()->SetTitle("SCRawE");                               
                                                                                
// Legend                                                                       
leg1 = new TLegend(0.6,0.7,0.9,0.9);                                           
leg1->SetHeader("GJet bin");                                                    
leg1->AddEntry(henergy_fEB4080,"pt20-40 + pt40-Inf","l");              
leg1->AddEntry(henergy_fEB2040,"40-80 + pt20-40 + pt40-Inf","l");           
leg1->Draw();                                                                   




                                                                                
//----------------------------------------------                                
// Prompt photons in EB                                                              
//----------------------------------------------                                
                                                                                
                                                                                
c1->cd(2);                                                                      
                                                                                
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
// max = promptEB2040->GetMaximum(vari);                                          
// min = promptEB2040->GetMinimum(vari);                                          
                                                                                
  //create one histogram                                                        
  TH1F *henergy_pEB2040 = new TH1F("henergy_pEB2040",title,100,min,max);            
  //read only the destep branch for all entries                                 
  Int_t nentries_pEB2040 = (Int_t)promptEB2040->GetEntries();                       
  for (Int_t i=0;i<nentries_pEB2040;i++) {                                        
    b_energy_pEB2040->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_pEB2040->Fill(energy_pEB2040);                                          
  }                                                                             
                                                                                
// ----- Second histo (prompt) ----- //                                         
                                                                                
//max = promptEB4080->GetMaximum(vari);                                           
//min = promptEB4080->GetMinimum(vari);                                           
                                                                                
  //create one histogram                                                        
  TH1F *henergy_pEB4080 = new TH1F("henergy_pEB4080",title,100,min,max);            
  //read only the destep branch for all entries                                 
  Int_t nentries_pEB4080 = (Int_t)promptEB4080->GetEntries();                       
  for (Int_t i=0;i<nentries_pEB4080;i++) {                                        
    b_energy_pEB4080->GetEntry(i);                                                
    // fill the histogram with the destep entry                                 
    henergy_pEB4080->Fill(energy_pEB4080);                                          
  }                                                                             
                                                                                
// ----- Third histo (prompt) ----- //                                          
                                                                                
//max = promptEB40Inf->GetMaximum(vari);                                          
//min = promptEB40Inf->GetMinimum(vari);                                          
                                                                                
  //create one histogram                                                        
  TH1F *henergy_pEB40Inf = new TH1F("henergy_pEB40Inf",title,100,min,max);          
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
                                                                                
norm = henergy_pEB2040->GetEntries();                                             
henergy_pEB2040->Scale(1/norm);                                                   
                                                                                
// Set canvas and draw; update                                                  
henergy_pEB2040->Draw();                                                          
gStyle->SetOptStat(0);                                                          
                                                                                
c1->Update();                                                                   
                                                                                
norm = henergy_pEB4080->GetEntries();                                             
henergy_pEB4080->Scale(1/norm);                                                   
                                                                                
// Draw, set title (?) and update                                               
henergy_pEB4080->SetLineColor(kRed);                                              
henergy_pEB4080->SetTitle("box1;x;y");                                            
henergy_pEB4080->Draw("same");                                                    
                                                                                
c1->Update();                                                                   
                                                                                
// Tried (but failed) to set the x axis title                                   
//henergy_fEB40Inf->GetXaxis()->SetTitle("SCRawE");                               
                                                                                
// Legend                                                                       
leg2 = new TLegend(0.6,0.7,0.9,0.9);                                           
leg2->SetHeader("GJet bin");                                                    
leg2->AddEntry(henergy_pEB4080,"pt20-40 + pt40-Inf","l");              
leg2->AddEntry(henergy_pEB2040,"40-80 + pt20-40 + pt40-Inf","l");           
leg2->Draw();                                                                   
                                                                                
                                                                                
if (gROOT->IsBatch()) return;                                                   
}                                                                               
