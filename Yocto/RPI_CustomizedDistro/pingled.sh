#!/bin/bash

LED_PIN=7  # GPIO pin number for LED 

# Initialize the GPIO pin
gpio mode $LED_PIN out

while true; do
    # Ping the IP address
    if ping -c 1 -W 1 192.168.1.6 > /dev/null 2>&1; then
        # Ping successful, turn on the LED
        gpio write $LED_PIN 1
        echo "Ping successful, LED ON"
    else
        # Ping failed, turn off the LED
        gpio write $LED_PIN 0
        echo "Ping failed, LED OFF"
    fi

    # Wait for 1 second before the next ping
    sleep 1
done
