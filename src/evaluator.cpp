#include "evaluator.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Constructor: calculate the errors for each estimate
Evaluation::Evaluation(double actualDistance,
                       double sensor1Reading,
                       double sensor2Reading,
                       double fusedEstimate) {

    sensor1Error = absoluteError(actualDistance, sensor1Reading);
    sensor2Error = absoluteError(actualDistance, sensor2Reading);
    fusedError = absoluteError(actualDistance, fusedEstimate);
}

// Calculate absolute error
double Evaluation::absoluteError(double actual, double measured) {
    return fabs(actual - measured);
}

// Display and compare the errors
void Evaluation::printReport() const {

    cout << fixed << setprecision(2);

    cout << "\n========== ERROR ANALYSIS ==========\n";

    cout << "Sensor 1 Absolute Error: "
         << sensor1Error << " cm\n";

    cout << "Sensor 2 Absolute Error: "
         << sensor2Error << " cm\n";

    cout << "Fused Estimate Error: "
         << fusedError << " cm\n";

    cout << "\n========== ACCURACY COMPARISON ==========\n";

    // Compare fusion with Sensor 1
    if (fusedError < sensor1Error) {
        cout << "Fusion is more accurate than Sensor 1.\n";
    }
    else if (fusedError > sensor1Error) {
        cout << "Sensor 1 is more accurate than fusion.\n";
    }
    else {
        cout << "Fusion and Sensor 1 have equal accuracy.\n";
    }

    // Compare fusion with Sensor 2
    if (fusedError < sensor2Error) {
        cout << "Fusion is more accurate than Sensor 2.\n";
    }
    else if (fusedError > sensor2Error) {
        cout << "Sensor 2 is more accurate than fusion.\n";
    }
    else {
        cout << "Fusion and Sensor 2 have equal accuracy.\n";
    }

    cout << "=====================================\n";
}
