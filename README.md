ESP32 Smart Monitoring System

A modular embedded firmware project for ESP32 that monitors temperature, door status, and current, controlling LEDs, buzzer, and relay based on a priority state machine.
This demonstrates real-world IoT skills, including sensor integration, peripheral control, FreeRTOS tasks, and system reliability.

🌟 Features

MCU: ESP32

Sensors:

MCP9600 (temperature, I2C)

Reed door sensor

Current sensor

Outputs: RGB LED indicators, buzzer, relay control

State Machine: Handles normal operation, temperature alarm, door alarm, and current fault

Priority Logic: Temperature alarm > Door alarm > Current fault

FreeRTOS Tasks: Non-blocking delays, responsive loop

Logging: ESP_LOG and printf for monitoring

Timers: Handles events like door open duration and current fault duration
