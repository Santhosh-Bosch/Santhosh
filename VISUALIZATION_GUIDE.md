# Vehicle Telemetry Visualization System - India Fleet Operations

## Overview
This system provides real-time visualization of vehicle telemetry data (Speed, Battery Level, GPS coordinates) for fleet operators in India.

## Features

### 1. Console Visualization
- **Color-coded displays** for easy status recognition
- **Real-time updates** with automatic console refresh
- **Status bars** for speed and battery levels
- **Alert indicators** for critical conditions:
  - High speed warnings (>100 km/h)
  - Low battery alerts (<20%)
  - Moderate warnings (speed >60 km/h, battery <50%)

### 2. HTML Dashboard
The system generates two types of HTML dashboards:

#### A. Auto-generated Dashboard (`telemetry_dashboard.html`)
- Generated automatically by the C program
- Updates every 2 seconds with latest telemetry data
- Features:
  - Speed monitoring with visual indicators
  - Battery level with progress bars
  - GPS coordinates display
  - Color-coded status alerts
  - Timestamp of last update

#### B. Enhanced Dashboard (`dashboard_enhanced.html`)
- Standalone, feature-rich dashboard
- Professional design with gradient backgrounds
- Additional features:
  - **Statistics tracking**: Max speed, Average speed
  - **Battery details**: Voltage and range estimation
  - **Alert banner**: Prominent warnings for critical conditions
  - **Live update indicator**
  - **Map placeholder**: Ready for Google Maps/OpenStreetMap integration
  - **Chart placeholder**: For telemetry history visualization

## Usage

### Running the Console Application

1. **Build the project:**
   ```bash
   make
   ```

2. **Run the application:**
   ```bash
   ./bin/telemetry_visualization
   ```
   Or on Windows:
   ```bash
   .\bin\telemetry_visualization.exe
   ```

3. **View console output:**
   - Real-time telemetry data displayed in color-coded format
   - Press `Ctrl+C` to stop

### Viewing HTML Dashboards

#### Option 1: Auto-generated Dashboard
1. Run the C application (it will generate `telemetry_dashboard.html`)
2. Open the file in a web browser
3. The page auto-refreshes every 2 seconds to show latest data

#### Option 2: Enhanced Dashboard
1. Open `dashboard_enhanced.html` directly in a web browser
2. Currently shows simulated data (replace with actual data integration)
3. Auto-updates every 2 seconds

### Integrating Real Data

To connect the enhanced dashboard to your actual telemetry system:

1. **WebSocket Integration:**
   ```javascript
   const ws = new WebSocket('ws://localhost:8080');
   ws.onmessage = (event) => {
       const data = JSON.parse(event.data);
       updateDashboard(data);
   };
   ```

2. **REST API Integration:**
   ```javascript
   async function fetchTelemetryData() {
       const response = await fetch('/api/telemetry');
       return await response.json();
   }
   ```

3. **File-based Integration:**
   The C program generates `telemetry_data.json`:
   ```javascript
   async function fetchTelemetryData() {
       const response = await fetch('telemetry_data.json');
       return await response.json();
   }
   ```

## Dashboard Components

### Speed Monitoring
- **Display**: Current speed in km/h
- **Progress bar**: Visual representation (0-120 km/h scale)
- **Status indicators**:
  - 🟢 Green: Normal speed (0-60 km/h)
  - 🟡 Yellow: Moderate speed (60-100 km/h)
  - 🔴 Red: High speed alert (>100 km/h)
- **Statistics**: Maximum and average speed tracking

### Battery Monitoring
- **Display**: Current battery level in percentage
- **Progress bar**: Visual representation (0-100%)
- **Status indicators**:
  - 🟢 Green: Good battery (>50%)
  - 🟡 Yellow: Moderate battery (20-50%)
  - 🔴 Red: Low battery alert (<20%)
- **Details**: Estimated voltage and range

### GPS Tracking
- **Display**: Latitude and longitude coordinates
- **Precision**: 6 decimal places (±0.11 meters accuracy)
- **Map integration ready**: Placeholder for live map display

## Configuration

### Thresholds (in `dashboard_enhanced.html`)
```javascript
const SPEED_LIMIT = 100;      // km/h - Speed warning threshold
const BATTERY_LOW = 20;       // % - Low battery threshold
const BATTERY_MEDIUM = 50;    // % - Medium battery threshold
const UPDATE_INTERVAL = 2000; // ms - Dashboard refresh rate
```

### Color Schemes
The visualization uses India-friendly color coding:
- **Speed**: Green → Yellow → Red gradient
- **Battery**: Green → Yellow → Red gradient
- **Background**: Purple gradient (professional appearance)

## Advanced Features

### Map Integration
To add a live map to the dashboard:

1. **Google Maps API:**
   ```html
   <script src="https://maps.googleapis.com/maps/api/js?key=YOUR_API_KEY"></script>
   <script>
       function initMap() {
           const location = {lat: data.latitude, lng: data.longitude};
           const map = new google.maps.Map(document.getElementById('map'), {
               zoom: 15,
               center: location
           });
           new google.maps.Marker({position: location, map: map});
       }
   </script>
   ```

2. **OpenStreetMap (Leaflet.js):**
   ```html
   <link rel="stylesheet" href="https://unpkg.com/leaflet@1.9.4/dist/leaflet.css" />
   <script src="https://unpkg.com/leaflet@1.9.4/dist/leaflet.js"></script>
   <script>
       const map = L.map('map').setView([data.latitude, data.longitude], 15);
       L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png').addTo(map);
       L.marker([data.latitude, data.longitude]).addTo(map);
   </script>
   ```

### Chart Integration
To add telemetry history charts:

1. **Install Chart.js:**
   ```html
   <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
   ```

2. **Create chart:**
   ```javascript
   const ctx = document.getElementById('myChart').getContext('2d');
   const chart = new Chart(ctx, {
       type: 'line',
       data: {
           labels: timeLabels,
           datasets: [{
               label: 'Speed (km/h)',
               data: speedData,
               borderColor: 'rgb(75, 192, 192)',
               tension: 0.1
           }]
       }
   });
   ```

## Deployment for Fleet Operations

### For Single Vehicle Monitoring
1. Run the C application on the vehicle's embedded system
2. Access the generated HTML dashboard on a local network
3. Use a simple HTTP server if needed:
   ```bash
   python -m http.server 8000
   ```

### For Fleet-wide Monitoring
1. Set up a central server to collect data from all vehicles
2. Use WebSocket or MQTT for real-time data streaming
3. Deploy the dashboard on a web server
4. Each vehicle sends telemetry to the central server
5. Fleet operators access the dashboard via web browser

## Troubleshooting

### Dashboard not updating
- Check if `telemetry_data.json` is being generated
- Verify file permissions
- Check browser console for errors

### Colors not showing in console
- Windows: Ensure Windows 10+ with ANSI color support
- Linux/Mac: Should work by default

### Performance issues
- Increase `UPDATE_INTERVAL` if updates are too frequent
- Limit history data to recent entries only

## License
This is a project for vehicle telemetry visualization in India.

## Support
For issues or questions, refer to the main README.md or contact your fleet operations team.
