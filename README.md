# Sensor-Fusion Simulation

**EECE 2140 — Iteration 3: System Design and Working Program**  
**Project team:** Anthony Santana (Iteration 3 Project Leader) and Diego Juarez (Technical Lead)  
**Repository:** https://github.com/Juarez-Diego-2007/sensor-fusion-simulation

## Project status

**Iteration 3 submission preparation:** The project builds on the completed Iteration 2 C++ implementation. The program has a working, switch-based menu with seven tasks, shared sensor readings, weighted-average fusion, error comparisons, three simulated scenarios, and saved-result display. The full program was compiled and manually tested during Iteration 2; Diego Juarez reviewed Anthony's implementation pull request and merged it into `main`, as confirmed by the team.

**Iteration 3 leadership:** Anthony Santana is Project Leader, responsible for coordinating check-ins, assigning work fairly, maintaining the task table and timeline, presenting the status report, and coordinating submission. Diego Juarez is Technical Lead, responsible for program verification and the system-design report, including the class diagram and technical documentation.

The Iteration 3 PDF report and Excel plan have been prepared as submission-ready documents. **Before submitting**, confirm that any listed meetings and reviews actually took place, that all 19 task statuses match completed work, that the latest documents are committed to `main`, and that each team member submits the repository link on Canvas. Earlier code review and merge do not establish those separate actions as complete.

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
│   ├── Sensor_Fusion_Iteration3_System_Design_Report.pdf
│   ├── Sensor_Fusion_Iteration3_Project_Plan.xlsx
│   └── ...                       # Keep earlier iteration documents if desired
├── README.md
└── .gitignore
```

The two Iteration 3 files shown above are the **required current documentation**: the PDF contains the class diagram, architecture, task register, and status-report material; the Excel workbook tracks task IDs, owners, menu options, files/functions, deliverables, statuses, the revised timeline, and contributions. Keep prior Iteration 2 files as historical records if they are already in `docs/`. Confirm the actual filenames in the repository match these references.

## Manual testing (Iteration 2 baseline)

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

### Completed implementation carried over from Iteration 2

| Team member | Verified or team-confirmed contribution |
| --- | --- |
| **Diego Juarez** | Iteration 2 Project Leader. Built the original `Sensor` class, `FusionEngine`, and sensor simulation/fusion functions. Reviewed Anthony's implementation and merged the pull request into `main` (team-confirmed). |
| **Anthony Santana** | Implemented the `Evaluation` class, error comparisons, three test scenarios, switch-based menu, saved-result display, and shared-data integration. Compiled the complete program and recorded manual test outputs. |

### Iteration 3 ownership

| Responsibility | Lead | Support / review |
| --- | --- | --- |
| Project Leader duties, check-ins, task status reports | Anthony | Diego |
| Excel task register, revised timeline, contribution tracking | Anthony | Diego |
| README update and GitHub documentation coordination | Anthony | Diego |
| Compile, run, and retest all seven menu options | Diego | Anthony |
| Class diagram, file structure, and system-design PDF | Diego | Anthony |
| Final review and individual Canvas submissions | Each member | Each member |

The Iteration 3 Excel task register covers **19 tasks**, including seven menu features, system architecture, documentation, verification, and closeout work. Existing implemented features are carryover work; newly assigned Iteration 3 tasks should be marked Done only after their completion is verified. The PDF includes prepared status-report content that should be reconciled against actual check-in meetings.

**GitHub workflow:** The Iteration 2 implementation pull request was reviewed by Diego and merged to `main`. Iteration 3 documentation changes should be committed to the current branch, reviewed as appropriate, and merged or pushed to `main` before submission.

## Limitations and possible future improvements

This system is a two-sensor, single-sample software prototype with fixed weights and random noise. The tests demonstrate program behavior, not statistical accuracy across thousands of runs. Potential extensions include repeated-run averages, a fixed random seed for reproducible comparisons, automatic reliability weighting, more sensors, outlier rejection, visualization, and physical hardware testing.

## Iteration 3 documentation and submission

Current project documents (place both inside `docs/`):

- [`docs/Sensor_Fusion_Iteration3_System_Design_Report.pdf`](docs/Sensor_Fusion_Iteration3_System_Design_Report.pdf) — classes, private data and public methods, menu and file organization, class diagram, task table, iteration status, and meeting-report material.
- [`docs/Sensor_Fusion_Iteration3_Project_Plan.xlsx`](docs/Sensor_Fusion_Iteration3_Project_Plan.xlsx) — updated task register, revised timeline, contributions, testing record, and meeting/check-in tracking.

**Final verification for Iteration 3:**

- Confirm a fresh compile and complete menu run from the `main` branch; capture the evidence if required.
- Verify that the task-register statuses, meeting dates, attendance, and status reports describe completed events accurately.
- Confirm both current Iteration 3 documents and this README are visible in `main` (not just on a local computer).
- Have each student submit the shared repository link individually on Canvas, following the assignment instructions.

Repository: https://github.com/Juarez-Diego-2007/sensor-fusion-simulation

The application and past test results are documented as complete; the final GitHub-documentation and Canvas checks should be verified at submission time.
