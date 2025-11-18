#include <stdio.h>
#include "telemetry.h"
#include "visualization.h"

int main() {
    // Initialize the telemetry system
    if (initTelemetry() != 0) {
        fprintf(stderr, "Failed to initialize telemetry system.\n");
        return 1;
    }

    // Initialize the visualization system
    if (initVisualization() != 0) {
        fprintf(stderr, "Failed to initialize visualization system.\n");
        return 1;
    }

    // Main loop to read telemetry data and update visualization
    while (1) {
        TelemetryData data;
        
        // Read telemetry data from the vehicle
        if (readTelemetry(&data) != 0) {
            fprintf(stderr, "Failed to read telemetry data.\n");
            break;
        }

        // Process the telemetry data
        processTelemetry(&data);

        // Update the visualization with the latest telemetry data
        updateDisplay(&data);
    }

    return 0;
}