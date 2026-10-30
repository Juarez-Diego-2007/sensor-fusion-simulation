#include "tasks.h"
#include <iostream>

void taskConfigureSensors(Simulation& sim) {
    (void)sim;
    std::cout << "[T1] Configure sensors: not implemented yet.\n";
}

void taskSetTruthAndSeed(Simulation& sim) {
    (void)sim;
    std::cout << "[T2] Set ground truth and seed: not implemented yet.\n";
}

void taskGenerateReadings(Simulation& sim) {
    (void)sim;
    std::cout << "[T3] Generate sensor readings: not implemented yet.\n";
}

void taskRunFusion(Simulation& sim) {
    (void)sim;
    std::cout << "[T4] Run weighted-average fusion: not implemented yet.\n";
}
