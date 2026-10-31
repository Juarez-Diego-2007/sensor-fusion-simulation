
#include <iostream>
#include <limits>
#include "tasks.h"

using namespace std;

int main() {
    int choice;
    bool running = true;

    while (running) {

        cout << "\n========== SENSOR-FUSION SYSTEM ==========\n";
        cout << "1. Generate Sensor Readings\n";
        cout << "2. Calculate Fused Estimate\n";
        cout << "3. Calculate Estimation Errors\n";
        cout << "4. Run Low-Noise Scenario\n";
        cout << "5. Run High-Noise Scenario\n";
        cout << "6. Run Outlier Scenario\n";
        cout << "7. Display Simulation Results\n";
        cout << "0. Exit Program\n";
        cout << "==========================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                generateSensorReadings();
                break;

            case 2:
                calculateFusedEstimate();
                break;

            case 3:
                calculateEstimationErrors();
                break;

            case 4:
                runLowNoiseScenario();
                break;

            case 5:
                runHighNoiseScenario();
                break;

            case 6:
                runOutlierScenario();
                break;

            case 7:
                displaySimulationResults();
                break;

            case 0:
                cout << "Exiting Sensor-Fusion System.\n";
                running = false;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
