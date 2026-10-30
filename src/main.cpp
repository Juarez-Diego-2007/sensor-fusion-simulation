#include <iostream>
#include <limits>
#include "simulation.h"
#include "tasks.h"

static void printMenu() {
    std::cout << "\n===== Sensor-Fusion Simulation =====\n"
              << " 1. Configure sensors\n"
              << " 2. Set ground truth and random seed\n"
              << " 3. Generate sensor readings\n"
              << " 4. Run weighted-average fusion\n"
              << " 5. Show results table\n"
              << " 6. Error metrics and comparison\n"
              << " 7. Run test scenarios (low / high noise / outlier-failure)\n"
              << " 8. Export results to CSV\n"
              << " 0. Exit\n"
              << "Choice: ";
}

int main() {
    Simulation sim;
    int choice = -1;

    while (choice != 0) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number.\n";
            continue;
        }
        switch (choice) {
            case 1: taskConfigureSensors(sim); break;
            case 2: taskSetTruthAndSeed(sim);  break;
            case 3: taskGenerateReadings(sim); break;
            case 4: taskRunFusion(sim);        break;
            case 5: taskShowResults(sim);      break;
            case 6: taskErrorMetrics(sim);     break;
            case 7: taskRunScenarios(sim);     break;
            case 8: taskExportResults(sim);    break;
            case 0: std::cout << "Goodbye.\n"; break;
            default: std::cout << "Invalid option.\n";
        }
    }
    return 0;
}
