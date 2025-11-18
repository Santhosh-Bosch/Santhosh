#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "telemetry.h"

// Initialize the visualization system
int initVisualization();

// Display telemetry data to console
void displayTelemetry(const TelemetryData* data);

// Update the display with latest telemetry data
void updateDisplay(const TelemetryData* data);

// Generate HTML visualization file
int generateHTMLVisualization(const TelemetryData* data);

// Cleanup visualization resources
void cleanupVisualization();

#endif // VISUALIZATION_H