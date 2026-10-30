
#include "fusion.h"
#include <stdexcept>

// Calculate weighted average of two sensor readings
double FusionEngine::weightedAverage(
    double reading1,
    double weight1,
    double reading2,
    double weight2
) {

    if (weight1 < 0 || weight2 < 0 ||
        weight1 + weight2 <= 0) {
        throw std::invalid_argument("Invalid sensor weights.");
    }

    double fusedEstimate =
        (reading1 * weight1 + reading2 * weight2)
        / (weight1 + weight2);

    return fusedEstimate;
}
