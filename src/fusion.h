#pragma once
#include <vector>
#include "sensor.h"

// Fusion algorithms (owner: Diego)
class Fusion {
public:
    // estimate = sum(w_i * r_i) / sum(w_i), skipping failed sensors
    static double weightedAverage(const std::vector<double>& readings,
                                  const std::vector<Sensor>& sensors);  // T4
};
