#pragma once
#include "simulation.h"

// One function per menu option.
// Diego's tasks live in tasks_sim.cpp, Anthony's in tasks_eval.cpp,
// so each person only edits their own file.

// Diego
void taskConfigureSensors(Simulation& sim);  // T1
void taskSetTruthAndSeed(Simulation& sim);   // T2
void taskGenerateReadings(Simulation& sim);  // T3
void taskRunFusion(Simulation& sim);         // T4

// Anthony
void taskShowResults(Simulation& sim);       // T5
void taskErrorMetrics(Simulation& sim);      // T6
void taskRunScenarios(Simulation& sim);      // T7
void taskExportResults(Simulation& sim);     // T8
