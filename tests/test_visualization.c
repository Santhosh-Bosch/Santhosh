#include <stdio.h>
#include <assert.h>
#include "visualization.h"

void test_initVisualization() {
    int result = initVisualization();
    assert(result == 0); // Assuming 0 indicates success
}

void test_displayTelemetry() {
    TelemetryData data = { 60, 80, {37.7749, -122.4194} }; // Example data
    int result = displayTelemetry(data);
    assert(result == 0); // Assuming 0 indicates success
}

void test_updateDisplay() {
    TelemetryData data = { 70, 75, {34.0522, -118.2437} }; // Example data
    int result = updateDisplay(data);
    assert(result == 0); // Assuming 0 indicates success
}

int main() {
    test_initVisualization();
    test_displayTelemetry();
    test_updateDisplay();
    
    printf("All tests passed!\n");
    return 0;
}