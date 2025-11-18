#include <stdio.h>
#include <assert.h>
#include "telemetry.h"

void test_initTelemetry() {
    TelemetryData data;
    initTelemetry(&data);
    assert(data.speed == 0);
    assert(data.batteryLevel == 0);
    assert(data.gps.latitude == 0);
    assert(data.gps.longitude == 0);
}

void test_readTelemetry() {
    TelemetryData data;
    initTelemetry(&data);
    readTelemetry(&data, 60, 75, 37.7749, -122.4194);
    assert(data.speed == 60);
    assert(data.batteryLevel == 75);
    assert(data.gps.latitude == 37.7749);
    assert(data.gps.longitude == -122.4194);
}

void test_processTelemetry() {
    TelemetryData data;
    initTelemetry(&data);
    readTelemetry(&data, 60, 75, 37.7749, -122.4194);
    processTelemetry(&data);
    // Add assertions based on expected processed data
}

int main() {
    test_initTelemetry();
    test_readTelemetry();
    test_processTelemetry();
    printf("All telemetry tests passed!\n");
    return 0;
}