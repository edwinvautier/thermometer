# Thermometer

This project is a wifi connected temperature and humidity sensor solar powered.

## Components

Made with :

- ESP32

- DHT11 (temp + moisture sensor)

- 2x 5V solar pannels

- lithium battery

- battery charger module

## Infos

The ESP collects data from the DHT11, and also hosts a small server in order to access to this data.

To access data, you and the ESP have to be on the same wi-fi access point. There is just the API address of the ESP to hit + the port.

Made with `C++`

## Setup

You can use the **arduino software** to flash the ESP.
