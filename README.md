# Sensor-Fusion Simulation

**EECE 2140 — Iteration 2: System Design and Implementation**  
**Project team:** Diego Juarez (Iteration 2 Project Leader) and Anthony Santana  
**Repository:** https://github.com/Juarez-Diego-2007/sensor-fusion-simulation

## Project status

**Iteration 2 implementation: complete.** The C++ application has been compiled and manually tested with all seven menu tasks. Diego Juarez reviewed Anthony's integration work and **merged the pull request into the `main` branch**, as confirmed by the team. The code uses shared simulation results so the sensor readings, fused estimate, and error calculations refer to the same sample.

The **README and `docs/` files must also be present on `main` before final submission**; review and merge of the code do not by themselves confirm that the documentation has been uploaded. Each student submits the final repository link separately on Canvas.

## Overview

This C++17 text-based simulation models two sensors measuring the distance to an obstacle. Each sensor generates a noisy reading for a known ground-truth distance. A weighted-average algorithm combines the readings into a fused estimate, and an evaluation class compares the fused error with the errors of each individual sensor.

The program demonstrates how noise levels, fixed reliability weights, and a faulty sensor affect estimation accuracy. This version uses software-generated data only: no external libraries, physical sensors, or graphics are required.

## Requirements

- A C++17-compatible compiler (`g++` recommended)
- A terminal, such as Ubuntu on WSL, Linux, or macOS
- VS Code or another text editor (optional)

## Build and run

Open a terminal **in the root of the repository** (the folder that contains `src/`), then enter the following **one-line** compilation command:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp src/sensor.cpp src/fusion.cpp src/tasks_sim.cpp src/evaluator.cpp src/tasks_eval.cpp -o sensor_fusion
```

Run the executable separately:

```bash
./sensor_fusion
```

For Windows users working in VS Code, run these commands in the **Ubuntu (WSL)** terminal. Recompile after changing C++ source files.

## Main menu

The program uses a `while` loop and `switch` statement to call one function per menu task.

| Option | Task | What it does |
| --- | --- | --- |
| `1` | Generate Sensor Readings | Generates two readings from the 100 cm ground truth and saves the readings and sensor weights. |
| `2` | Calculate Fused Estimate | Calculates a weighted average using the **saved readings** from option 1 (or the most recently saved scenario). |
| `3` | Calculate Estimation Errors | Compares the errors of Sensor 1, Sensor 2, and the fused estimate using the saved sample. |
| `4` | Run Low-Noise Scenario | Generates, fuses, saves, and evaluates a sample with small sensor noise. |
| `5` | Run High-Noise Scenario | Generates, fuses, saves, and evaluates a sample with larger sensor noise. |
| `6` | Run Outlier Scenario | Adds an artificial 40 cm error to Sensor 2 and evaluates how the fault affects fusion. |
| `7` | Display Simulation Results | Redisplays the most recently saved readings, weights, fused estimate (when available), and errors. |
| `0` | Exit Program | Exits the application. |

**Recommended standard workflow:** select `1`, then `2`, then `3`, then `7`, and finally `0`. Options `4`, `5`, and `6` can be run independently; use option `7` afterward to redisplay the saved scenario. A new run of option `1` replaces the previous sample and requires fusion to be calculated again.

Results are stored **in memory** and reset when the program closes.

## Sensor model and calculations

- **Ground-truth distance:** 100.0 cm
- **Sensor 1 weight:** 0.7
- **Sensor 2 weight:** 0.3
- **Noise:** Normally distributed random error, so individual run values vary
- **Weights:** Fixed inputs chosen for this prototype, not learned automatically

The fused estimate is a weighted average:

```text
fused = (weight1 * reading1 + weight2 * reading2) / (weight1 + weight2)
```

Absolute error is calculated against the known ground truth:

```text
absolute_error = abs(actual_distance - estimate)
```

A lower absolute error means a more accurate result **for that particular sample**. Fusion is not guaranteed to outperform both individual readings every time.

### Scenarios

| Scenario | Sensor 1 noise level | Sensor 2 noise level | Special behavior |
| --- | ---: | ---: | --- |
| Standard | 2.0 | 5.0 | Normal generated readings |
| Low noise | 0.5 | 1.0 | Reduced random noise |
| High noise | 8.0 | 15.0 | Increased random noise |
| Outlier | 2.0 | 5.0 | Add 40 cm to Sensor 2's reading |

## Repository structure

```text
sensor-fusion-simulation/
├── src/
│   ├── main.cpp                 # Main menu, input validation, and switch statement
│   ├── tasks.h                  # Declarations for all seven menu functions
│   ├── tasks_sim.cpp            # Sensor reading and fused-estimate tasks
│   ├── tasks_eval.cpp           # Error analysis, scenarios, and saved-result display
│   ├── simulation_state.h       # Shared LastSimulation structure/declaration
│   ├── sensor.h                 # Sensor class declaration
│   ├── sensor.cpp               # Sensor implementation and noise generation
│   ├── fusion.h                 # FusionEngine class declaration
│   ├── fusion.cpp               # Weighted-average fusion implementation
│   ├── evaluator.h              # Evaluation class declaration
│   └── evaluator.cpp            # Absolute errors and accuracy comparisons
├── docs/
│   ├── Sensor_Fusion_Iteration2_System_Design_Report.pdf
│   └── Sensor_Fusion_Iteration2_Project_Plan.xlsx
├── README.md
└── .gitignore
```

The `docs/` files are the **required final repository deliverables**. Ensure they have actually been committed to `main` before submitting the repository. The system design report includes the class diagram and task register; the spreadsheet includes the revised task plan, timeline, contributions, and testing record.

## Manual testing

The team used `g++` to compile the program and tested the menu and scenario behavior. The following checks were demonstrated:

1. Select `7` before running a simulation; the program reports that no saved results are available.
2. Select `1`, then `7`; the same readings are displayed, and the program notes that fusion has not yet been calculated.
3. Select `2`, `3`, and `7`; the readings stay unchanged, and the fused estimate and absolute errors agree across menu tasks.
4. Select `4`, `5`, and `6`; each scenario generates readings and displays an accuracy comparison.
5. After a scenario, select `7`; the corresponding saved results appear without generating a new random sample.
6. Enter an invalid choice such as `8`; the program rejects it and returns to the menu.
7. Enter `0`; the program exits normally.

### Recorded example results

These are **observed manual-test examples**, not fixed outputs. Random noise causes results to differ on each run. Values are shown to two decimal places.

| Scenario | True distance (cm) | Sensor 1 (cm) | Sensor 2 (cm) | Fused estimate (cm) | S1 error (cm) | S2 error (cm) | Fused error (cm) |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| Standard | 100.00 | 96.88 | 100.07 | 97.84 | 3.12 | 0.07 | 2.16 |
| Low noise | 100.00 | 100.07 | 99.79 | 99.99 | 0.07 | 0.21 | 0.01 |
| High noise | 100.00 | 91.69 | 122.86 | 101.04 | 8.31 | 22.86 | 1.04 |
| Outlier | 100.00 | 99.77 | 142.64 | 112.63 | 0.23 | 42.64 | 12.63 |

These examples demonstrate why a weighted average may help when noise is moderate, but can be pulled away from the ground truth by a faulty sensor. The displayed readings are rounded; calculations use their full underlying precision.

## Architecture

1. The `Sensor` class generates noisy measurements from the actual distance.
2. The `FusionEngine` calculates the weighted estimate.
3. The `LastSimulation` structure, declared in `simulation_state.h`, stores the shared sample and fusion state.
4. The `Evaluation` class computes absolute errors and prints comparisons.
5. The task functions connect these components to the `main.cpp` menu.

The shared state prevents options 1, 2, 3, and 7 from accidentally comparing unrelated random sensor readings.

## Team contributions and GitHub workflow

| Team member | Iteration 2 role and contribution |
| --- | --- |
| **Diego Juarez** | **Project Leader.** Built the initial `Sensor` class, `FusionEngine`, and sensor simulation/fusion functions. Coordinated work, reviewed Anthony's integration, and merged the pull request into `main`. |
| **Anthony Santana** | Created the `Evaluation` class, error comparisons, three test scenarios, switch-based menu, saved-result display, and shared-data integration. Compiled the complete program and recorded manual test outputs. |

**Review and merge status:** Code review completed by Diego; Anthony's implementation/integration branch was merged into **`main`** (team-confirmed). The updated README and Iteration 2 PDF/Excel documents must be committed as separate documentation changes if they are not already on `main`.

## Limitations and possible future improvements

This system is a two-sensor, single-sample software prototype with fixed weights and random noise. The tests demonstrate program behavior, not statistical accuracy across thousands of runs. Potential extensions include repeated-run averages, a fixed random seed for reproducible comparisons, automatic reliability weighting, more sensors, outlier rejection, visualization, and physical hardware testing.

## Iteration 2 documentation and submission

Required project documents:

- [`docs/Sensor_Fusion_Iteration2_System_Design_Report.pdf`](docs/Sensor_Fusion_Iteration2_System_Design_Report.pdf)
- [`docs/Sensor_Fusion_Iteration2_Project_Plan.xlsx`](docs/Sensor_Fusion_Iteration2_Project_Plan.xlsx)

**Final check:** verify that `main` contains the complete source code, this README, and both files in `docs/`. Both team members must each submit the final GitHub repository link through Canvas.
