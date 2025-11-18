@echo off
REM Vehicle Telemetry Dashboard Launcher
REM This script opens the enhanced dashboard in your default browser

echo ========================================
echo Vehicle Telemetry Dashboard - India
echo Fleet Operations Visualization System
echo ========================================
echo.

echo Opening Enhanced Dashboard...
start "" "%CD%\dashboard_enhanced.html"

echo.
echo Dashboard opened in your default browser!
echo.
echo Features:
echo   - Real-time Speed Monitoring
echo   - Battery Level Tracking
echo   - GPS Location Display
echo   - Alert System
echo   - Statistics Tracking
echo.
echo The dashboard auto-refreshes every 2 seconds.
echo.
echo To view the auto-generated dashboard from the C program,
echo run the telemetry application first, then open:
echo   telemetry_dashboard.html
echo.
echo Press any key to exit...
pause >nul
