#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"

#include "G4MultiUnion.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{

public:
	DetectorConstruction();
	~DetectorConstruction();
	
	virtual G4VPhysicalVolume *Construct();
};

#endif
