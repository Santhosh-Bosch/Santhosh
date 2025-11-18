# 🔄 GitHub Actions Workflows

## Overview

This project includes automated CI/CD workflows that trigger on every push to the `main` branch.

---

## 📋 Workflows

### 1. CI/CD Pipeline (`ci.yml`)

**Trigger:** Push or Pull Request to `main` branch

**Jobs:**

#### Build and Test
- ✅ Checkout code
- ✅ Setup GCC compiler
- ✅ Build C project using Makefile
- ✅ Run unit tests
- ✅ Check syntax of C files
- ✅ Generate build summary

#### Validate Dashboard
- ✅ Checkout code
- ✅ Setup Node.js
- ✅ Validate HTML files exist
- ✅ Check documentation

#### Notify
- ✅ Success notification
- ✅ Deployment summary
- ✅ Project statistics

---

### 2. Deploy Dashboard (`deploy.yml`)

**Trigger:** Push to `main` branch (when dashboard or docs change)

**Jobs:**

#### Deploy to GitHub Pages
- ✅ Checkout code
- ✅ Setup GitHub Pages
- ✅ Copy dashboard to public directory
- ✅ Upload artifact
- ✅ Deploy to GitHub Pages
- ✅ Deployment summary

**Live URL:** https://santhosh-bosch.github.io/Santhosh/

---

## 🚀 Workflow Triggers

### What Triggers the Workflows?

```yaml
# ci.yml - Triggers on:
on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main
```

```yaml
# deploy.yml - Triggers on:
on:
  push:
    branches:
      - main
    paths:
      - 'dashboard_enhanced.html'
      - '**.md'
      - 'src/**'
```

---

## 📊 Workflow Execution

### When You Push to Main

```bash
git push origin main
```

**What Happens:**

1. **CI/CD Pipeline Starts**
   - ⏱️ Duration: ~2-3 minutes
   - 🔨 Builds C code
   - 🧪 Runs tests
   - ✅ Validates dashboard
   - 📢 Sends notification

2. **Deploy Pipeline Starts** (if dashboard/docs changed)
   - ⏱️ Duration: ~1-2 minutes
   - 📦 Packages dashboard
   - 🚀 Deploys to GitHub Pages
   - 🔗 Makes live at URL

---

## 🎯 Workflow Status

### View on GitHub

1. Go to: https://github.com/Santhosh-Bosch/Santhosh
2. Click **"Actions"** tab
3. See all workflow runs

### Status Badges

Add to README.md:

```markdown
[![CI/CD](https://github.com/Santhosh-Bosch/Santhosh/actions/workflows/ci.yml/badge.svg)](https://github.com/Santhosh-Bosch/Santhosh/actions/workflows/ci.yml)

[![Deploy](https://github.com/Santhosh-Bosch/Santhosh/actions/workflows/deploy.yml/badge.svg)](https://github.com/Santhosh-Bosch/Santhosh/actions/workflows/deploy.yml)
```

---

## 📝 Workflow Files

### Location

```
.github/
└── workflows/
    ├── ci.yml      # CI/CD pipeline
    └── deploy.yml  # Deployment pipeline
```

### File Structure

**ci.yml:**
- Build and test C code
- Validate web dashboard
- Send notifications

**deploy.yml:**
- Deploy dashboard to GitHub Pages
- Make accessible via web URL
- Update live version

---

## 🔧 Customization

### Modify CI Pipeline

Edit `.github/workflows/ci.yml`:

```yaml
# Add more jobs
jobs:
  your-custom-job:
    name: Custom Job
    runs-on: ubuntu-latest
    steps:
      - name: Your step
        run: echo "Custom action"
```

### Change Trigger

```yaml
# Trigger on specific branches
on:
  push:
    branches:
      - main
      - develop
      - feature/*
```

### Add Notifications

```yaml
# Add Slack notification
- name: Slack Notification
  uses: 8398a7/action-slack@v3
  with:
    status: ${{ job.status }}
    webhook_url: ${{ secrets.SLACK_WEBHOOK }}
```

---

## 🎨 What Gets Built/Deployed

### CI Pipeline Builds:
- ✅ C telemetry engine
- ✅ Visualization system
- ✅ Utility functions
- ✅ Test suite

### Deploy Pipeline Deploys:
- ✅ dashboard_enhanced.html (as index.html)
- ✅ Documentation files (*.md)
- ✅ All resources needed for web app

---

## 📦 GitHub Pages Setup

### Enable GitHub Pages

1. Go to repository **Settings**
2. Click **Pages** (left sidebar)
3. Source: **GitHub Actions**
4. Save

### Access Deployed Dashboard

**URL:** https://santhosh-bosch.github.io/Santhosh/

**Features Available:**
- 🚗 10-vehicle fleet tracking
- 🚨 Speed notifications (80 km/h)
- 🗺️ Live map (Coimbatore)
- 📊 Real-time charts
- 🎨 Modern UI

---

## 🐛 Troubleshooting

### Workflow Failed?

**Check:**
1. Go to Actions tab
2. Click failed workflow
3. Expand failed step
4. Read error message

**Common Issues:**

**Build Failure:**
```bash
# Fix: Ensure Makefile is correct
make clean
make
```

**Test Failure:**
```bash
# Fix: Update test files
make test
```

**Deploy Failure:**
```bash
# Fix: Check GitHub Pages settings
# Ensure source is "GitHub Actions"
```

### Re-run Workflow

1. Go to Actions tab
2. Click workflow run
3. Click "Re-run jobs"
4. Select "Re-run all jobs"

---

## 📊 Workflow Output

### CI Pipeline Output

```
✅ Build completed successfully
📊 Project: Vehicle Telemetry Visualization System
🚗 Fleet: 10 vehicles
🚨 Speed alerts: 80 km/h
📍 Location: Coimbatore, Tamil Nadu, India
```

### Deploy Pipeline Output

```
🚀 Dashboard deployed successfully!
🔗 Access at: https://santhosh-bosch.github.io/Santhosh/

📊 Deployed Components:
  ✅ 10-vehicle fleet dashboard
  ✅ Speed notification system (80 km/h)
  ✅ Live map (Coimbatore)
  ✅ Real-time charts
  ✅ Documentation
```

---

## 🎯 Benefits

### Automated CI/CD

✅ **Automatic builds** on every push  
✅ **Automatic tests** to catch errors  
✅ **Automatic deployment** to web  
✅ **Quality assurance** before merge  
✅ **Continuous integration** of changes  

### GitHub Pages Hosting

✅ **Free hosting** for dashboard  
✅ **Automatic updates** on push  
✅ **HTTPS enabled** by default  
✅ **CDN distribution** worldwide  
✅ **No server management** needed  

---

## 🚀 Quick Commands

### Push and Trigger Workflows

```bash
# Make changes
git add .
git commit -m "Update dashboard"
git push origin main

# Workflows automatically trigger!
# View at: github.com/Santhosh-Bosch/Santhosh/actions
```

### Check Workflow Status

```bash
# Using GitHub CLI
gh workflow list
gh run list
gh run view
```

---

## 📈 Workflow History

All workflow runs are saved:
- ✅ View past builds
- ✅ See what changed
- ✅ Debug failures
- ✅ Track deployment history

**Access:** https://github.com/Santhosh-Bosch/Santhosh/actions

---

## 🎉 Success!

Your repository now has:

✅ **Automated CI/CD** on every push  
✅ **Automatic testing** of code  
✅ **Automatic deployment** to web  
✅ **GitHub Pages** hosting enabled  
✅ **Live dashboard** accessible online  

**Next push to `main` will trigger the workflows!** 🚀

---

**Workflows Created:** November 18, 2025  
**Repository:** Santhosh-Bosch/Santhosh  
**CI/CD:** ✅ Active  
**Deployment:** ✅ Automated  
**Status:** 🟢 Ready
