void formatSpeed(float speed, char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "Speed: %.2f km/h", speed);
}

void formatBatteryLevel(float batteryLevel, char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "Battery Level: %.2f%%", batteryLevel);
}

void formatGPS(float latitude, float longitude, char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "GPS: Latitude %.6f, Longitude %.6f", latitude, longitude);
}

void handleError(const char* errorMessage) {
    fprintf(stderr, "Error: %s\n", errorMessage);
}