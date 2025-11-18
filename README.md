# Vehicle Telemetry Visualization

## Overview
The Vehicle Telemetry Visualization project is designed to ingest and visualize telemetry data from vehicles for fleet operators. This system captures essential data such as speed, battery level, and GPS coordinates, providing a comprehensive view of vehicle performance and status.

## Project Structure
```
vehicle-telemetry-visualization
├── src
│   ├── main.c            # Entry point of the application
│   ├── telemetry.c       # Implementation of telemetry data ingestion
│   ├── telemetry.h       # Header file for telemetry functions
│   ├── visualization.c    # Implementation of telemetry data visualization
│   ├── visualization.h    # Header file for visualization functions
│   ├── utils.c           # Utility functions for data handling
│   └── utils.h           # Header file for utility functions
├── include
│   ├── telemetry.h       # Duplicate header for telemetry functions
│   ├── visualization.h    # Duplicate header for visualization functions
│   └── utils.h           # Duplicate header for utility functions
├── tests
│   ├── test_telemetry.c  # Unit tests for telemetry functions
│   ├── test_visualization.c # Unit tests for visualization functions
│   └── test_utils.c      # Unit tests for utility functions
├── Makefile              # Build instructions for the project
└── README.md             # Project documentation
```

## Setup Instructions
1. **Clone the repository**:
   ```
   git clone <repository-url>
   cd vehicle-telemetry-visualization
   ```

2. **Build the project**:
   Use the provided Makefile to compile the source code:
   ```
   make
   ```

3. **Run the application**:
   After building, execute the application:
   ```
   ./vehicle-telemetry-visualization
   ```

## Usage
- The application initializes the telemetry system and starts ingesting data from the vehicle.
- Telemetry data is processed and visualized in real-time, allowing fleet operators to monitor vehicle performance.

## Contributing
Contributions are welcome! Please submit a pull request or open an issue for any enhancements or bug fixes.

## License
This project is licensed under the MIT License. See the LICENSE file for details.