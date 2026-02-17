# FINAL SUBMISSION  
# Electrical Load Monitoring & Billing Simulator

## MID SEMESTER CAPSTONE PROJECT

**Course:** EEE 227 (PT)  
**Programme:** HND Electrical Engineering (Level 200)  
**Development Environment:** VS Code (Windows)  
**Programming Language:** C++  
**Data Storage:** Text File using fstream  

---

## Project Overview

This project is a console-based C++ application designed to simulate electrical load monitoring and electricity billing for a small household or facility.

The system allows users to register electrical appliances, calculate daily energy consumption, estimate electricity costs using a tariff per kilowatt-hour (kWh), and automatically store appliance data using file handling.

This project demonstrates the practical application of C++ programming concepts in solving real-world electrical engineering problems.

---

## Features Implemented

### Appliance Management
- Register appliance (Name, Power rating in watts, Usage hours per day)
- View all registered appliances
- Search appliance by name
- Structured menu-driven interface

---

### Energy Calculation

Energy consumption is calculated using the formula:

Energy (kWh/day) = (Power × Hours) ÷ 1000

The system:
- Computes individual appliance energy usage
- Computes total daily energy consumption
- Displays formatted energy summary tables

---

### Billing Calculation

The program:
- Accepts electricity tariff per kWh
- Calculates daily electricity cost
- Estimates monthly energy and cost (30-day projection)

Formulas used:

Daily Cost = Total kWh/day × Tariff  
Monthly Energy = Daily Energy × 30  
Monthly Cost = Monthly Energy × Tariff  

---

### File Storage (fstream Implementation)

Appliance data is saved in:

appliances.txt

Data format:

Name|PowerW|HoursPerDay

Example:

Fan|75|8  
TV|120|5  

When the program restarts:
- Data is automatically loaded
- Previously registered appliances are restored
- Ensures data persistence

---

## Input Validation

The system validates:

- Appliance name must not be empty
- Power rating must be greater than zero
- Usage hours must be between 0 and 24
- Tariff must be positive
- Invalid menu selections are handled safely

---

## How to Compile and Run

Open terminal inside the project folder and run:

g++ main.cpp -o main  
./main  

---

## Repository Structure

electrical-load-monitoring/  
│── main.cpp  
│── appliances.txt  
│── billing_summary.txt (optional)  
│── README.md  
│── .gitignore  

---

## Learning Outcomes Achieved

- Applied C++ structures and functions  
- Used vectors for dynamic storage  
- Implemented energy and billing computations  
- Applied file handling using fstream  
- Used GitHub for professional version control  
- Built a structured console application  

---

## Author

Pascal Gavey 
HND Electrical Engineering (Level 200)