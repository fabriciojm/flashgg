#!/usr/bin/env cmsRun

import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils

process = cms.Process("Analysis")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.source = cms.Source("PoolSource",
                            fileNames=cms.untracked.vstring(
#        "file:/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/myMicroAODOutputFile_GJet40-80.root"        
#        "file:/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/myMicroAODOutputFile_GJet80-Inf_Pt20-40.root" #Only 46000 evnts!
#        "file:/afs/cern.ch/user/f/fabricio/CMSSW_7_6_3_patch2/src/myMicroAODOutputFile_GJet80-Inf_Pt40-Inf.root"
        )
)
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000000) )
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("test.root")
)

from flashgg.Taggers.flashggPreselectedDiPhotons_cfi import flashggPreselectedDiPhotons
process.kinPreselDiPhotons = flashggPreselectedDiPhotons.clone(
cut=cms.string(
        " leadingPhoton.pt > 18 && subLeadingPhoton.pt > 18"
        " && mass > 55" ##### Change mass cut if needed
        " && abs(leadingPhoton.superCluster.eta)<2.5 && abs(subLeadingPhoton.superCluster.eta)<2.5 "
#        " && ( abs(leadingPhoton.superCluster.eta)<1.4442 || abs(leadingPhoton.superCluster.eta)>1.566)"
#        " && ( abs(subLeadingPhoton.superCluster.eta)<1.4442 || abs(subLeadingPhoton.superCluster.eta)>1.566)"
        " && (leadingPhoton.full5x5_r9>0.8||leadingPhoton.egChargedHadronIso<20||leadingPhoton.egChargedHadronIso/leadingPhoton.pt<0.3)"
        " && (subLeadingPhoton.full5x5_r9>0.8||subLeadingPhoton.egChargedHadronIso<20||subLeadingPhoton.egChargedHadronIso/subLeadingPhoton.pt<0.3)"
        # E-veto
#        " && leadingPhoton.passElectronVeto && subLeadingPhoton.passElectronVeto"
        #PS veto
        " && (!leadingPhoton.hasPixelSeed) && (!subLeadingPhoton.hasPixelSeed)"
                 
        " && leadingPhoton.hadTowOverEm<0.008 && subLeadingPhoton.hadTowOverEm<0.008"
        " && (  (     (    abs(leadingPhoton.superCluster.eta)<1.4442\
                        && abs(subLeadingPhoton.superCluster.eta)<1.4442 )\
                   && (    (   leadingPhoton.full5x5_r9>0.85)\
                        || (   leadingPhoton.full5x5_r9<=0.85 && leadingPhoton.full5x5_r9>0.5\
                            && leadingPhoton.full5x5_sigmaIetaIeta<0.015\
                            && leadingPhoton.pfPhoIso03<4.0\
                            && leadingPhoton.trkSumPtHollowConeDR03<6.0) )\
                   && (    (   subLeadingPhoton.full5x5_r9>0.85)\
                        || (   subLeadingPhoton.full5x5_r9<=0.85 && subLeadingPhoton.full5x5_r9>0.5\
                            && subLeadingPhoton.full5x5_sigmaIetaIeta<0.015\
                            && subLeadingPhoton.pfPhoIso03<4.0\
                            && subLeadingPhoton.trkSumPtHollowConeDR03<6.0) )  )\
              || (    (    abs(leadingPhoton.superCluster.eta)<1.4442\
                        && abs(subLeadingPhoton.superCluster.eta)>1.566 )\
                   && (    leadingPhoton.full5x5_r9>0.85\
                        && leadingPhoton.full5x5_sigmaIetaIeta<0.015\
                        && leadingPhoton.pfPhoIso03<4.0\
                        && leadingPhoton.trkSumPtHollowConeDR03<6.0)\
                   && (    subLeadingPhoton.full5x5_r9>0.90\
                        && subLeadingPhoton.full5x5_sigmaIetaIeta<0.035\
                        && subLeadingPhoton.pfPhoIso03<4.0\
                        && subLeadingPhoton.trkSumPtHollowConeDR03<6.0)  )\
              || (   (     abs(subLeadingPhoton.superCluster.eta)<1.4442\
                        && abs(leadingPhoton.superCluster.eta)>1.566 )\
                   && (    subLeadingPhoton.full5x5_r9>0.85\
                        && subLeadingPhoton.full5x5_sigmaIetaIeta<0.015\
                        && subLeadingPhoton.pfPhoIso03<4.0\
                        && subLeadingPhoton.trkSumPtHollowConeDR03<6.0)\
                   && (    leadingPhoton.full5x5_r9>0.90\
                        && leadingPhoton.full5x5_sigmaIetaIeta<0.035\
                        && leadingPhoton.pfPhoIso03<4.0\
                        && leadingPhoton.trkSumPtHollowConeDR03<6.0)  )\
              || (   (     abs(subLeadingPhoton.superCluster.eta)>1.566\
                        && abs(leadingPhoton.superCluster.eta)>1.566)\
                   && (    subLeadingPhoton.full5x5_r9>0.90\
                        && subLeadingPhoton.full5x5_sigmaIetaIeta<0.035\
                        && subLeadingPhoton.pfPhoIso03<4.0\
                        && subLeadingPhoton.trkSumPtHollowConeDR03<6.0)\
                   && (    leadingPhoton.full5x5_r9>0.90\
                        && leadingPhoton.full5x5_sigmaIetaIeta<0.035\
                        && leadingPhoton.pfPhoIso03<4.0\
                        && leadingPhoton.trkSumPtHollowConeDR03<6.0)\
                        )  )"

        ## " && leadingPhoton.genMatchType != subLeadingPhoton.genMatchType " ## selects only prompt-fake pairs
        )
                                                              )

## Trying

## EB

#isBarrelLeading = True if abs(leadingPhoton.superCluster.eta)<1.4442 else False
#isBarrelSubleading = True if abs(subLeadingPhoton.superCluster.eta)<1.4442 else False




process.flashggSinglePhotonViews = cms.EDProducer("FlashggSinglePhotonViewProducer",
 					  DiPhotonTag=cms.InputTag('kinPreselDiPhotons'),
                                          maxCandidates = cms.int32(1)
                                          )

process.load("flashgg.Taggers.photonViewDumper_cfi") ##  import diphotonDumper 
import flashgg.Taggers.dumperConfigTools as cfgTools

process.photonViewDumper.src = "flashggSinglePhotonViews"
process.photonViewDumper.dumpTrees = True
process.photonViewDumper.dumpWorkspace = False
process.photonViewDumper.quietRooFit = True

## list of variables to be dumped in trees/datasets. Same variables for all categories
variables=["pt := photon.pt",
	   "energy := photon.energy",
           "eta := photon.eta","phi := photon.phi",
           "scEta:=photon.superCluster.eta",
           "scRawE := photon.superCluster.rawEnergy",
           "etaWidth := photon.superCluster.etaWidth",
           "phiWidth := photon.superCluster.phiWidth",
           "chgIsoWrtWorstVtx := photon.pfChgIsoWrtWorstVtx03",
           "chgIsoWrtChosenVtx := pfChIso03WrtChosenVtx",
	   "neuIso03:=photon.pfNeutIso03",
           "r9 := photon.r9",
           "sigmaIetaIeta := photon.sigmaIetaIeta",
           "covIEtaIPhi := photon.sieip",
           "esEffSigmaRR := photon.esEffSigmaRR",
           "s4 := photon.s4",
           #"hadTowOverEm := photon.hadTowOverEm",
           #"trkSumPtHollowConeDR03 := photon.trkSumPtHollowConeDR03",
           #"covIphiIphi := photon.sipip",
           #"hcalTowerSumEtConeDR03 := photon.hcalTowerSumEtConeDR03",
           "idMVA := phoIdMvaWrtChosenVtx",
           #"genIso := photon.userFloat('genIso')", 
           #"eTrue := ? photon.hasMatchedGenPhoton ? photon.matchedGenPhoton.energy : 0",
           #"phoIso03 := photon.pfPhoIso03",
           ]

## list of histograms to be plotted
histograms=[#"r9>>r9(110,0,1.1)",
            #"scEta>>scEta(100,-2.5,2.5)"
            ]

## define categories and associated objects to dump
#cfgTools.addCategory(process.photonViewDumper,
#                     "Reject",
#                     "abs(photon.superCluster.eta)>=1.4442&&abs(photon.superCluster.eta)<=1.566||abs(photon.superCluster.eta)>=2.5",
#                     -1 ## if nSubcat is -1 do not store anythings
#                     )

# interestng categories 
cfgTools.addCategories(process.photonViewDumper,
                       ## categories definition
                       ## cuts are applied in cascade. Events getting to these categories have already failed the "Reject" selection
                       [("promptPhotonsEB","abs(photon.superCluster.eta)<1.5 && photon.genMatchType == 1",0),
                        ("fakePhotonsEB",  "abs(photon.superCluster.eta)<1.5 && photon.genMatchType != 1",0),
                        ],
                       ## variables to be dumped in trees/datasets. Same variables for all categories
                       ## if different variables wanted for different categories, can add categorie one by one with cfgTools.addCategory
                       variables=variables,
                       ## histograms to be plotted. 
                       ## the variables need to be defined first
                       histograms=histograms
                       )


cfgTools.addCategories(process.photonViewDumper,
                       ## categories definition
                       ## cuts are applied in cascade. Events getting to these categories have already failed the "Reject" selection
                       [("promptPhotonsEE","abs(photon.superCluster.eta)>=1.5 && photon.genMatchType == 1",0),
                        ("fakePhotonsEE",  "abs(photon.superCluster.eta)>=1.5 && photon.genMatchType != 1",0),
                        ],
                       ## variables to be dumped in trees/datasets. Same variables for all categories
                       ## if different variables wanted for different categories, can add categorie one by one with cfgTools.addCategory
                       variables=variables,
                       ## histograms to be plotted. 
                       ## the variables need to be defined first
                       histograms=histograms
                       ## compute MVA on the fly. More then one MVA can be tested at once
                       )


process.p1 = cms.Path(
    process.kinPreselDiPhotons*process.flashggSinglePhotonViews*process.photonViewDumper
    )



from flashgg.MetaData.JobConfig import customize
customize.setDefault("maxEvents",-1)
customize(process)

