#include "telemetry.h"
#include <stdio.h>
#include <stdlib.h>

// ...existing code...

static TelemetryData currentTelemetry;

void initTelemetry() {
    currentTelemetry.speed = 0.0;
    currentTelemetry.batteryLevel = 100.0;
    currentTelemetry.latitude = 0.0;
    currentTelemetry.longitude = 0.0;
}

void readTelemetry(TelemetryData* data) {
    // Simulate reading telemetry data from a vehicle
    data->speed = (float)(rand() % 100); // Simulated speed
    data->batteryLevel = (float)(rand() % 101); // Simulated battery level
    data->latitude = (float)(rand() % 180) - 90; // Simulated latitude
    data->longitude = (float)(rand() % 360) - 180; // Simulated longitude
    currentTelemetry = *data;
}
void processTelemetry(const TelemetryData* data) {
    // Here you can add any processing logic if needed
    // For now, just update currentTelemetry
    currentTelemetry = *data;
}