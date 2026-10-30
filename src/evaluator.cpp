#include "evaluator.h"
#include <iostream>

void Evaluator::printResultsTable(const Simulation& sim) const {
    // TODO (Anthony): print truth, each reading, fused, abs error per sample
    (void)sim;
}

std::vector<ErrorStats> Evaluator::computeStats(const Simulation& sim) const {
    // TODO (Anthony): MAE, max error, RMSE for each sensor and the fused estimate
    (void)sim;
    return {};
}

void Evaluator::printComparison(const std::vector<ErrorStats>& stats) const {
    // TODO (Anthony): print stats and whether fusion beat the best single sensor
    (void)stats;
}

bool Evaluator::exportCsv(const Simulation& sim, const std::string& file) const {
    // TODO (Anthony): write samples to a CSV file
    (void)sim; (void)file;
    return false;
}
