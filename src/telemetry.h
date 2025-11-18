#ifndef TELEMETRY_H
#define TELEMETRY_H

typedef struct {
    float speed;        // Vehicle speed in km/h
    float batteryLevel; // Battery level in percentage
    float latitude;     // GPS latitude
    float longitude;    // GPS longitude
} TelemetryData;

// Function prototypes
void initTelemetry();
void readTelemetry(TelemetryData* data);
void processTelemetry(const TelemetryData* data);

#endif // TELEMETRY_H