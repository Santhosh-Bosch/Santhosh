#ifndef UTILS_H
#define UTILS_H

// Utility function prototypes for telemetry formatting and error handling
#include <stddef.h>
#include <stdio.h>

void formatSpeed(float speed, char* buffer, size_t bufferSize);
void formatBatteryLevel(float batteryLevel, char* buffer, size_t bufferSize);
void formatGPS(float latitude, float longitude, char* buffer, size_t bufferSize);
void handleError(const char* errorMessage);

#endif // UTILS_H