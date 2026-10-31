
#ifndef SIMULATION_STATE_H
#define SIMULATION_STATE_H

#include <string>
using namespace std;

// Store sensor readings and fusion results
struct LastSimulation {
    bool available = false;
    string scenario;

    double actualDistance = 0.0;
    double reading1 = 0.0;
    double reading2 = 0.0;
    double fusedEstimate = 0.0;

    double weight1 = 0.0;
    double weight2 = 0.0;

    // Complete scenarios already have a fused estimate.
    // Option 1 sets this to false until option 2 runs.
    bool fusedAvailable = true;
};

// Shared variable used by both task files
extern LastSimulation lastSimulation;

#endif
