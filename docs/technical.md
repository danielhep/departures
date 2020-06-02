# What hardware does this use?
- Aliexpress 64x32 RGB LED Matrix
- ESP32 DevKit
- Headways Departures PCB and all related components
- 5 volt power supply capable of at least 3 amps. 
- 3D printed case
- Some wire

# How does it work?
The ESP32 DevKit is the brains of the entire operation. It contains the WiFi module and main processor. Sending data to the display requires about 8 wires, which, without the Departures PCB looks something like this: 

TODO: insert pic 

The Departures PCB handles all this mess of wires for you, although it does require some simple wiring to connect to the daughter board that plugs into the other side of the matrix. 

# How is the WiFi connection established? 
Upon initial startup, the device will host its own WiFi network entitled "bus good." Connect to this network with your smart phone or laptop and you should be guided through the setup process. The setup process asks for a username and pin, which the device will use to connect to our online configuration service to pull your configuration.