#ifndef EVALUATOR_H
#define EVALUATOR_H

class Evaluation {
private:
    double sensor1Error;
    double sensor2Error;
    double fusedError;

public:
    // Constructor
    Evaluation(double actualDistance,
               double sensor1Reading,
               double sensor2Reading,
               double fusedEstimate);

    // Calculate absolute error
    static double absoluteError(double actual,
                                double measured);

    // Display and compare errors
    void printReport() const;
};

#endif