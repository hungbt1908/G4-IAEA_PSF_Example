#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH2D.h"

void readIAEAphsp() 
{
    const char* fileName = "myPhSp_2000";
    TFile* file = TFile::Open(fileName);
    TTree* tree = (TTree*)file->Get("IAEAphsp");

    Int_t particleType;
    Double_t energy, x, y, z, u, v, w, weight;

    tree->SetBranchAddress("ParticleType", &particleType);
    tree->SetBranchAddress("Energy", &energy);
    tree->SetBranchAddress("X", &x);
    tree->SetBranchAddress("Y", &y);
    tree->SetBranchAddress("Z", &z);
    tree->SetBranchAddress("U", &u);
    tree->SetBranchAddress("V", &v);
    tree->SetBranchAddress("W", &w);
    tree->SetBranchAddress("Weight", &weight);

    Long64_t nEntries = tree->GetEntries();

    // Create a 2D histogram to plot the phase space
    TH2D* hist = new TH2D("hist", "Phase Space", 100, -1, 1, 100, -1, 1);

    for (Long64_t i = 0; i < nEntries; i++) {
        tree->GetEntry(i);

        // Fill the histogram with the x and y coordinates of each event
        hist->Fill(x, y);
    }

    // Create a canvas to draw the histogram
    TCanvas* canvas = new TCanvas("canvas", "Canvas", 800, 600);

    // Draw the histogram on the canvas
    hist->Draw("colz");

    // Save the canvas as a PNG image
    canvas->SaveAs("phase_space.png");

    file->Close();
}
