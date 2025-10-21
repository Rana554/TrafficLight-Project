# Smart Traffic Light System 🚦

This project is a simple traffic light system built using the STM32F103C8T6 microcontroller.  
All drivers (GPIO, RCC) are written manually without using HAL — just low-level register access.

## Features
- Custom-written low-level drivers  
- Red, Yellow, and Green LEDs for traffic control  
- Pedestrian button input  
- Delay-based timing (2s yellow, 5s red)

## Hardware Setup
- PA5 → Red LED  
- PA6 → Yellow LED  
- PA7 → Green LED  
- PB0 → Pedestrian Button  
