# 🚗 Vehicle Telemetry Dashboard - Quick Reference

## Fleet Operator's Guide

### Dashboard Overview

#### Speed Indicator 🚗
- **Green (0-60 km/h)**: Normal, safe speed
- **Yellow (60-100 km/h)**: Moderate speed, monitor closely  
- **Red (>100 km/h)**: ⚠️ HIGH SPEED ALERT - Immediate attention required!

#### Battery Indicator 🔋
- **Green (>50%)**: Battery healthy, normal operation
- **Yellow (20-50%)**: Battery moderate, plan for charging
- **Red (<20%)**: ⚠️ LOW BATTERY - Charge immediately!

#### GPS Indicator 📍
- **Green checkmark**: GPS signal active and tracking
- Displays precise latitude and longitude coordinates
- Accuracy: ±11 cm (6 decimal places)

### Alert System

When you see the red alert banner at the top:
- **High Speed**: Vehicle exceeding 100 km/h
- **Low Battery**: Battery level below 20%
- **Action Required**: Contact driver immediately

### Dashboard Metrics

#### Speed Card
- **Current Speed**: Real-time speed in km/h
- **Max Speed**: Highest speed recorded in this session
- **Avg Speed**: Average speed over last 10 readings
- **Progress Bar**: Visual representation (0-120 km/h scale)

#### Battery Card  
- **Current Level**: Battery percentage (0-100%)
- **Voltage**: Estimated battery voltage
- **Range**: Estimated remaining distance in km
- **Progress Bar**: Visual battery level

#### GPS Card
- **Latitude**: North-South position (degrees)
- **Longitude**: East-West position (degrees)
- **Map View**: Shows current vehicle location

### Understanding the Colors

#### Status Colors
- 🟢 **Green**: Everything is normal, no action needed
- 🟡 **Yellow**: Caution, monitor the situation
- 🔴 **Red**: Alert! Immediate attention required

#### Background Indicators
- **Purple gradient**: Normal dashboard mode
- **Red pulsing banner**: Critical alert active

### Dashboard Updates

- **Refresh Rate**: Every 2 seconds
- **Live Indicator**: Top-right shows "🔄 Live Updates"
- **Timestamp**: Bottom shows last update time in IST

### Key Thresholds to Remember

| Metric | Normal | Caution | Alert |
|--------|--------|---------|-------|
| Speed | 0-60 km/h | 60-100 km/h | >100 km/h |
| Battery | >50% | 20-50% | <20% |
| GPS | Active | - | No Signal |

### Quick Actions

#### When Speed Alert Triggers:
1. Note the exact speed from dashboard
2. Contact the driver immediately
3. Request speed reduction
4. Log the incident
5. Monitor until speed normalizes

#### When Battery Alert Triggers:
1. Note the battery percentage
2. Check estimated range remaining
3. Contact driver to plan charging stop
4. Monitor battery drain rate
5. Arrange charging station if needed

#### If GPS Shows No Signal:
1. Last known coordinates are displayed
2. Contact driver for manual location
3. GPS will auto-recover when signal returns

### Statistics Interpretation

#### Max Speed
- Shows the highest speed achieved
- Useful for driver performance review
- Resets when dashboard is refreshed

#### Average Speed
- Calculated from last 10 readings
- Indicates general driving pattern
- Useful for route efficiency analysis

#### Voltage (Battery)
- Estimated from battery percentage
- Typical range: 0-48V
- Lower voltage = less battery charge

#### Range (Battery)
- Estimated distance possible with current battery
- Based on 300 km at 100% battery
- Plan charging when range < 50 km

### Best Practices

✅ **Do:**
- Monitor dashboard regularly (every 5-10 minutes)
- Respond immediately to red alerts
- Keep track of battery levels throughout the day
- Note GPS coordinates for route planning
- Document any unusual patterns

❌ **Don't:**
- Ignore red alerts
- Let battery drop below 10% if avoidable
- Assume yellow warnings will resolve themselves
- Forget to check before long routes

### Common Questions

**Q: Dashboard not updating?**
A: Check internet connection and refresh browser (F5)

**Q: All readings show 0?**
A: Vehicle may be off or sensors not connected

**Q: Colors look wrong?**
A: Ensure you're using a modern browser (Chrome, Firefox, Edge)

**Q: Can I see multiple vehicles?**
A: Currently single vehicle. Multi-vehicle dashboard coming soon.

**Q: What if browser crashes?**
A: Simply reopen dashboard - data is continuously updated

### Emergency Contacts

In case of:
- **High Speed Emergency**: Contact driver + supervisor
- **Battery Critical (<10%)**: Contact nearest charging station
- **GPS Lost**: Contact driver for manual location

### Technical Support

- **Dashboard Issues**: Refresh browser or restart system
- **Data Not Updating**: Check vehicle telemetry system
- **Display Problems**: Try different browser

---

## Dashboard Access

### To Open Dashboard:
**Option 1**: Double-click `open_dashboard.bat`  
**Option 2**: Open `dashboard_enhanced.html` in browser  
**Option 3**: After running vehicle program, open `telemetry_dashboard.html`

### System Requirements:
- Modern web browser (Chrome, Firefox, Edge, Safari)
- Screen resolution: 1024x768 or higher
- Internet not required (works offline)

---

**Remember**: The dashboard is your eyes on the fleet. Regular monitoring ensures safe and efficient operations!

**For detailed technical documentation, see**: `VISUALIZATION_GUIDE.md`

---
*Vehicle Telemetry Visualization System v1.0*  
*Designed for Fleet Operations in India* 🇮🇳
