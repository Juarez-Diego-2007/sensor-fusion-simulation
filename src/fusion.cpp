#include "fusion.h"

double Fusion::weightedAverage(const std::vector<double>& readings,
                               const std::vector<Sensor>& sensors) {
    // TODO (Diego): implement weighted average
    (void)sensors;
    return readings.empty() ? 0.0 : readings[0];
}
