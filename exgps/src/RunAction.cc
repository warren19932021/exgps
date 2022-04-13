//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file eventgenerator/exgps/src/RunAction.cc
/// \brief Implementation of the RunAction class
//
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "RunAction.hh"
//#include "HistoManager.hh"

//#include "G4VAnalysisManager.hh"
//#include "g4root_defs.hh"


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction()
  : fFileName("exgps")
// : G4UserRunAction(), fHistoManager(0)
// : G4UserRunAction()
{
  G4AnalysisManager* analysis = G4AnalysisManager::Instance();

  analysis->SetFileName(fFileName);


  // Default values (to be reset via /analysis/h1/set command)               
  G4int nbins = 100;
  G4double vmin = 0.;
  G4double vmax = 100.;

  // Create all histograms as inactivated 
  // as we have not yet set nbins, vmin, vmax
  //
  analysis->SetHistoDirectoryName("histo");  
  analysis->SetFirstHistoId(1);
    
  G4int id = analysis->CreateH1("h1.1","kinetic energy", nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);
    
  id = analysis->CreateH1("h1.2","vertex dist dN/dv = f(r)", nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);

  id = analysis->CreateH1("h1.3","direction: cos(theta)", nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);

  id = analysis->CreateH1("h1.4","direction: phi", nbins, vmin, vmax);
  analysis->SetH1Activation(id, false);  

  // histos 2D
  //
  id = analysis->CreateH2("h2.1","vertex: XY",nbins,vmin,vmax, nbins,vmin,vmax);
  analysis->SetH2Activation(id, false);

  id = analysis->CreateH2("h2.2","vertex: YZ",nbins,vmin,vmax, nbins,vmin,vmax);
  analysis->SetH2Activation(id, false);

  id = analysis->CreateH2("h2.3","vertex: ZX",nbins,vmin,vmax, nbins,vmin,vmax);
  analysis->SetH2Activation(id, false);

  id = analysis->CreateH2("h2.4","direction: phi-cos(theta)",
                                          nbins,vmin,vmax, nbins,vmin,vmax);
  analysis->SetH2Activation(id, false);

  id = analysis->CreateH2("h2.5","direction: phi-theta",
                                          nbins,vmin,vmax, nbins,vmin,vmax);
  analysis->SetH2Activation(id, false);















     G4cout<<"test output in RunAction::RunAction   111111111"<<G4endl;

  //G4AnalysisManager* analysis = G4AnalysisManager::Instance();
     G4cout<<"test output in RunAction::RunAction   222222222"<<G4endl;
  analysis->CreateNtuple("test", "test");
     G4cout<<"test output in RunAction::RunAction   333333333"<<G4endl;
  //analysis->CreateNtuple("101", "Primary Particle Tuple");
     G4cout<<"test output in RunAction::RunAction   444444444"<<G4endl;
  analysis->CreateNtupleIColumn("particleID");    //column 0
     G4cout<<"test output in RunAction::RunAction   555555555"<<G4endl;
  analysis->CreateNtupleDColumn("Ekin");          //column 1
  analysis->CreateNtupleDColumn("posX");          //column 2
  analysis->CreateNtupleDColumn("posY");          //column 3
  analysis->CreateNtupleDColumn("posZ");          //column 4
  analysis->CreateNtupleDColumn("dirTheta");      //column 5
  analysis->CreateNtupleDColumn("dirPhi");        //column 6
  analysis->CreateNtupleDColumn("weight");        //column 7
  //analysis->FinishNtuple();
  analysis->FinishNtuple(0);
	
	
	// fHistoManager = new HistoManager(); 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::~RunAction()
{
//  delete fHistoManager;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run*)
{
  //histograms
  //
     G4cout<<"test output in RunAction::BeginOfRunAction   111111111"<<G4endl;
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
     G4cout<<"test output in RunAction::BeginOfRunAction   222222222"<<G4endl;
//  if ( analysisManager->IsActive() ) {
     G4cout<<"test output in RunAction::BeginOfRunAction   333333333"<<G4endl;
     analysisManager->OpenFile();
     //analysisManager->OpenFile("testest.root");
//  }  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* )
{
  //save histograms
  //      
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
//  if ( analysisManager->IsActive() ) {
     G4cout<<"test output in RunAction::EndOfRunAction"<<G4endl;
    analysisManager->Write();
    analysisManager->CloseFile();
//  }  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
