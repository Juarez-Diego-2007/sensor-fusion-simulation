#pragma once
#include <string>
#include <vector>
#include "simulation.h"

struct ErrorStats {
    std::string name;      // sensor name or "Fused"
    double meanAbsError;
    double maxAbsError;
    double rmse;
};

// Error analysis and reporting (owner: Anthony)
class Evaluator {
public:
    void printResultsTable(const Simulation& sim) const;                 // T5
    std::vector<ErrorStats> computeStats(const Simulation& sim) const;   // T6
    void printComparison(const std::vector<ErrorStats>& stats) const;    // T6
    bool exportCsv(const Simulation& sim, const std::string& file) const; // T8
};
