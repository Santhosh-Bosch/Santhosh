#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "visualization.h"
#include "telemetry.h"

#define HTML_FILE "telemetry_dashboard.html"
#define DATA_FILE "telemetry_data.json"

// ANSI color codes for better console visualization
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_BOLD    "\033[1m"

static int visualizationInitialized = 0;

int initVisualization() {
    printf("Initializing Vehicle Telemetry Visualization System...\n");
    printf("Dashboard will be available at: %s\n", HTML_FILE);
    visualizationInitialized = 1;
    return 0;
}

void displayTelemetry(const TelemetryData* data) {
    if (!data) {
        fprintf(stderr, "Error: NULL telemetry data\n");
        return;
    }

    // Get current timestamp
    time_t now;
    time(&now);
    char timeStr[26];
    ctime_s(timeStr, sizeof(timeStr), &now);
    timeStr[strlen(timeStr) - 1] = '\0'; // Remove newline

    printf("\n");
    printf(COLOR_BOLD COLOR_CYAN "╔════════════════════════════════════════════════════════════╗\n");
    printf("║          VEHICLE TELEMETRY DASHBOARD - INDIA              ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n" COLOR_RESET);
    
    printf(COLOR_BLUE "Time: %s\n" COLOR_RESET, timeStr);
    printf("\n");

    // Speed display with color coding
    printf(COLOR_BOLD "🚗 SPEED:" COLOR_RESET " ");
    if (data->speed > 100.0f) {
        printf(COLOR_RED "%.2f km/h ⚠️  (High Speed!)\n" COLOR_RESET, data->speed);
    } else if (data->speed > 60.0f) {
        printf(COLOR_YELLOW "%.2f km/h\n" COLOR_RESET, data->speed);
    } else {
        printf(COLOR_GREEN "%.2f km/h\n" COLOR_RESET, data->speed);
    }

    // Battery level display with color coding
    printf(COLOR_BOLD "🔋 BATTERY LEVEL:" COLOR_RESET " ");
    if (data->batteryLevel < 20.0f) {
        printf(COLOR_RED "%.2f%% ⚠️  (Low Battery!)\n" COLOR_RESET, data->batteryLevel);
    } else if (data->batteryLevel < 50.0f) {
        printf(COLOR_YELLOW "%.2f%%\n" COLOR_RESET, data->batteryLevel);
    } else {
        printf(COLOR_GREEN "%.2f%%\n" COLOR_RESET, data->batteryLevel);
    }

    // GPS coordinates
    printf(COLOR_BOLD "📍 GPS LOCATION:\n" COLOR_RESET);
    printf("   Latitude:  " COLOR_CYAN "%.6f°\n" COLOR_RESET, data->latitude);
    printf("   Longitude: " COLOR_CYAN "%.6f°\n" COLOR_RESET, data->longitude);

    // Battery bar visualization
    printf("\n" COLOR_BOLD "Battery Status: " COLOR_RESET);
    int batteryBars = (int)(data->batteryLevel / 10);
    printf("[");
    for (int i = 0; i < 10; i++) {
        if (i < batteryBars) {
            if (batteryBars < 3) printf(COLOR_RED "█" COLOR_RESET);
            else if (batteryBars < 5) printf(COLOR_YELLOW "█" COLOR_RESET);
            else printf(COLOR_GREEN "█" COLOR_RESET);
        } else {
            printf("░");
        }
    }
    printf("]\n");

    // Speed bar visualization
    printf(COLOR_BOLD "Speed Status:   " COLOR_RESET);
    int speedBars = (int)(data->speed / 12);
    if (speedBars > 10) speedBars = 10;
    printf("[");
    for (int i = 0; i < 10; i++) {
        if (i < speedBars) {
            if (speedBars > 8) printf(COLOR_RED "█" COLOR_RESET);
            else if (speedBars > 5) printf(COLOR_YELLOW "█" COLOR_RESET);
            else printf(COLOR_GREEN "█" COLOR_RESET);
        } else {
            printf("░");
        }
    }
    printf("]\n\n");

    printf(COLOR_CYAN "════════════════════════════════════════════════════════════\n" COLOR_RESET);
}

void updateDisplay(const TelemetryData* data) {
    if (!visualizationInitialized) {
        fprintf(stderr, "Error: Visualization not initialized\n");
        return;
    }

    // Clear the console
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    // Display telemetry on console
    displayTelemetry(data);

    // Update HTML dashboard
    generateHTMLVisualization(data);
}

int generateHTMLVisualization(const TelemetryData* data) {
    if (!data) {
        return -1;
    }

    // First, save the data to JSON file for web dashboard
    FILE* jsonFile = fopen(DATA_FILE, "w");
    if (!jsonFile) {
        fprintf(stderr, "Error: Could not create JSON data file\n");
        return -1;
    }

    time_t now;
    time(&now);
    char timeStr[26];
    ctime_s(timeStr, sizeof(timeStr), &now);
    timeStr[strlen(timeStr) - 1] = '\0'; // Remove newline

    fprintf(jsonFile, "{\n");
    fprintf(jsonFile, "  \"timestamp\": \"%s\",\n", timeStr);
    fprintf(jsonFile, "  \"speed\": %.2f,\n", data->speed);
    fprintf(jsonFile, "  \"batteryLevel\": %.2f,\n", data->batteryLevel);
    fprintf(jsonFile, "  \"latitude\": %.6f,\n", data->latitude);
    fprintf(jsonFile, "  \"longitude\": %.6f\n", data->longitude);
    fprintf(jsonFile, "}\n");

    fclose(jsonFile);

    // Generate enhanced HTML dashboard
    FILE* htmlFile = fopen(HTML_FILE, "w");
    if (!htmlFile) {
        fprintf(stderr, "Error: Could not create HTML file\n");
        return -1;
    }

    fprintf(htmlFile, "<!DOCTYPE html>\n");
    fprintf(htmlFile, "<html lang=\"en\">\n");
    fprintf(htmlFile, "<head>\n");
    fprintf(htmlFile, "    <meta charset=\"UTF-8\">\n");
    fprintf(htmlFile, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
    fprintf(htmlFile, "    <title>Vehicle Telemetry Dashboard - India</title>\n");
    fprintf(htmlFile, "    <style>\n");
    fprintf(htmlFile, "        * { margin: 0; padding: 0; box-sizing: border-box; }\n");
    fprintf(htmlFile, "        body { font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; background: linear-gradient(135deg, #667eea 0%%, #764ba2 100%%); color: #333; min-height: 100vh; padding: 20px; }\n");
    fprintf(htmlFile, "        .container { max-width: 1200px; margin: 0 auto; }\n");
    fprintf(htmlFile, "        .header { background: white; padding: 20px; border-radius: 10px; box-shadow: 0 4px 6px rgba(0,0,0,0.1); margin-bottom: 20px; text-align: center; }\n");
    fprintf(htmlFile, "        .header h1 { color: #667eea; margin-bottom: 5px; }\n");
    fprintf(htmlFile, "        .header .subtitle { color: #666; font-size: 14px; }\n");
    fprintf(htmlFile, "        .dashboard { display: grid; grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); gap: 20px; }\n");
    fprintf(htmlFile, "        .card { background: white; padding: 25px; border-radius: 10px; box-shadow: 0 4px 6px rgba(0,0,0,0.1); }\n");
    fprintf(htmlFile, "        .card-title { font-size: 14px; color: #666; text-transform: uppercase; margin-bottom: 10px; }\n");
    fprintf(htmlFile, "        .card-value { font-size: 36px; font-weight: bold; margin-bottom: 10px; }\n");
    fprintf(htmlFile, "        .card-unit { font-size: 18px; color: #999; }\n");
    fprintf(htmlFile, "        .speed-card .card-value { color: #4CAF50; }\n");
    fprintf(htmlFile, "        .battery-card .card-value { color: #2196F3; }\n");
    fprintf(htmlFile, "        .gps-card .card-value { color: #FF9800; font-size: 20px; }\n");
    fprintf(htmlFile, "        .progress-bar { width: 100%%; height: 20px; background: #e0e0e0; border-radius: 10px; overflow: hidden; margin-top: 10px; }\n");
    fprintf(htmlFile, "        .progress-fill { height: 100%%; background: linear-gradient(90deg, #4CAF50, #8BC34A); transition: width 0.5s; }\n");
    fprintf(htmlFile, "        .progress-fill.low { background: linear-gradient(90deg, #f44336, #ff5722); }\n");
    fprintf(htmlFile, "        .progress-fill.medium { background: linear-gradient(90deg, #ff9800, #ffc107); }\n");
    fprintf(htmlFile, "        .status { margin-top: 10px; padding: 8px; border-radius: 5px; text-align: center; font-weight: bold; }\n");
    fprintf(htmlFile, "        .status.good { background: #e8f5e9; color: #4CAF50; }\n");
    fprintf(htmlFile, "        .status.warning { background: #fff3e0; color: #ff9800; }\n");
    fprintf(htmlFile, "        .status.danger { background: #ffebee; color: #f44336; }\n");
    fprintf(htmlFile, "        .timestamp { text-align: center; color: white; margin-top: 20px; font-size: 14px; }\n");
    fprintf(htmlFile, "        .icon { font-size: 40px; margin-bottom: 10px; }\n");
    fprintf(htmlFile, "        .map-container { grid-column: 1 / -1; height: 400px; background: #e0e0e0; border-radius: 10px; display: flex; align-items: center; justify-content: center; flex-direction: column; }\n");
    fprintf(htmlFile, "    </style>\n");
    fprintf(htmlFile, "</head>\n");
    fprintf(htmlFile, "<body>\n");
    fprintf(htmlFile, "    <div class=\"container\">\n");
    fprintf(htmlFile, "        <div class=\"header\">\n");
    fprintf(htmlFile, "            <h1>🚗 Vehicle Telemetry Dashboard</h1>\n");
    fprintf(htmlFile, "            <div class=\"subtitle\">Fleet Operations - India</div>\n");
    fprintf(htmlFile, "        </div>\n");
    fprintf(htmlFile, "        <div class=\"dashboard\">\n");
    
    // Speed Card
    fprintf(htmlFile, "            <div class=\"card speed-card\">\n");
    fprintf(htmlFile, "                <div class=\"icon\">🚗</div>\n");
    fprintf(htmlFile, "                <div class=\"card-title\">Vehicle Speed</div>\n");
    fprintf(htmlFile, "                <div class=\"card-value\">%.2f <span class=\"card-unit\">km/h</span></div>\n", data->speed);
    fprintf(htmlFile, "                <div class=\"progress-bar\"><div class=\"progress-fill%s\" style=\"width: %.0f%%\"></div></div>\n",
        data->speed > 100 ? " low" : (data->speed > 60 ? " medium" : ""),
        (data->speed > 120 ? 100 : (data->speed / 120.0 * 100)));
    fprintf(htmlFile, "                <div class=\"status%s\">%s</div>\n",
        data->speed > 100 ? " danger" : (data->speed > 60 ? " warning" : " good"),
        data->speed > 100 ? "⚠️ High Speed Alert!" : (data->speed > 60 ? "⚠️ Moderate Speed" : "✓ Normal Speed"));
    fprintf(htmlFile, "            </div>\n");
    
    // Battery Card
    fprintf(htmlFile, "            <div class=\"card battery-card\">\n");
    fprintf(htmlFile, "                <div class=\"icon\">🔋</div>\n");
    fprintf(htmlFile, "                <div class=\"card-title\">Battery Level</div>\n");
    fprintf(htmlFile, "                <div class=\"card-value\">%.2f <span class=\"card-unit\">%%</span></div>\n", data->batteryLevel);
    fprintf(htmlFile, "                <div class=\"progress-bar\"><div class=\"progress-fill%s\" style=\"width: %.0f%%\"></div></div>\n",
        data->batteryLevel < 20 ? " low" : (data->batteryLevel < 50 ? " medium" : ""),
        data->batteryLevel);
    fprintf(htmlFile, "                <div class=\"status%s\">%s</div>\n",
        data->batteryLevel < 20 ? " danger" : (data->batteryLevel < 50 ? " warning" : " good"),
        data->batteryLevel < 20 ? "⚠️ Low Battery!" : (data->batteryLevel < 50 ? "⚠️ Battery Moderate" : "✓ Battery Good"));
    fprintf(htmlFile, "            </div>\n");
    
    // GPS Card
    fprintf(htmlFile, "            <div class=\"card gps-card\">\n");
    fprintf(htmlFile, "                <div class=\"icon\">📍</div>\n");
    fprintf(htmlFile, "                <div class=\"card-title\">GPS Location</div>\n");
    fprintf(htmlFile, "                <div class=\"card-value\">%.6f°</div>\n", data->latitude);
    fprintf(htmlFile, "                <div style=\"font-size: 14px; color: #666; margin-bottom: 5px;\">Latitude</div>\n");
    fprintf(htmlFile, "                <div class=\"card-value\">%.6f°</div>\n", data->longitude);
    fprintf(htmlFile, "                <div style=\"font-size: 14px; color: #666;\">Longitude</div>\n");
    fprintf(htmlFile, "                <div class=\"status good\">✓ GPS Signal Active</div>\n");
    fprintf(htmlFile, "            </div>\n");
    
    // Map placeholder
    fprintf(htmlFile, "            <div class=\"card map-container\">\n");
    fprintf(htmlFile, "                <div style=\"text-align: center;\">\n");
    fprintf(htmlFile, "                    <h2>🗺️ Map View</h2>\n");
    fprintf(htmlFile, "                    <p style=\"color: #666; margin-top: 10px;\">Location: %.6f, %.6f</p>\n", data->latitude, data->longitude);
    fprintf(htmlFile, "                    <p style=\"color: #999; font-size: 12px; margin-top: 10px;\">Integrate with Google Maps or OpenStreetMap API for live map</p>\n");
    fprintf(htmlFile, "                </div>\n");
    fprintf(htmlFile, "            </div>\n");
    
    fprintf(htmlFile, "        </div>\n");
    fprintf(htmlFile, "        <div class=\"timestamp\">Last Updated: %s</div>\n", timeStr);
    fprintf(htmlFile, "    </div>\n");
    fprintf(htmlFile, "    <script>\n");
    fprintf(htmlFile, "        // Auto-refresh every 2 seconds\n");
    fprintf(htmlFile, "        setTimeout(function() { location.reload(); }, 2000);\n");
    fprintf(htmlFile, "    </script>\n");
    fprintf(htmlFile, "</body>\n");
    fprintf(htmlFile, "</html>\n");

    fclose(htmlFile);
    
    return 0;
}

void cleanupVisualization() {
    printf("Cleaning up visualization resources...\n");
    visualizationInitialized = 0;
}