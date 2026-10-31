
#ifndef FUSION_H
#define FUSION_H

class FusionEngine {
public:
    // Calculate weighted average of two sensor readings
    static double weightedAverage(
        double reading1,
        double weight1,
        double reading2,
        double weight2
    );
};

#endif
