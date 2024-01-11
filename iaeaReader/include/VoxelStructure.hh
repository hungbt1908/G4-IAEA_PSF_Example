#ifndef VoxelStructure
#define voxelStructure

#include "globals.hh"
#include <vector>
#include "G4RotationMatrix.hh"


struct Svoxel
{
	G4ThreeVector pos, HalfSize;
	G4double absorbed_dose, absorbed_dose2,
	rsd;// relative standard deviation.
	G4String volumeName;
	G4int nEvents;
};
#endif
