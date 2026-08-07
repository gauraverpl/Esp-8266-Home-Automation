# Esp-8266-Home-Automation
"IoT smart home project using an ESP8266 to control lights and appliances over Wi-Fi."

A home automation system is an automating the bulk of electronic and electrical tasks within a home. It uses a combination of hardware and software to enable control and management over appliances and devices within a home.

Home automation not only refers to reduce human efforts but also energy efficiency and time saving. Here we are performing home automation by using ESP8266 – WiFi SoC and Blynk or Sinric Pro Playstore App.

# Component	Quantity

ESP8266 NodeMCU	1

4 Channel Relay Module	1

LCD 16x2 with I2C Module	1

5V 2A Power Supply	1

Jumper Wires	As required

Breadboard (testing)	1

# Optional
Push Buttons (manual control)

Buzzer

LED indicators

Fuse

SMPS enclosure

# How System Works


                                               Google Assistant

                                                     │
        
                                                     │
        
                                                     ▼
        
                                                  Google Home
   
                                                     │
        
                                                     ▼
                                                     
                                                Sinric Pro Cloud
                                                
    
                                                     │
                                                     
                                                 Internet (WiFi)
                                                
                                                     │
                                                     
                                                     ▼
                                                     
                                                   ESP8266
                                                  
                                                     │
                                                     
                                              ┌──────┼─────────┐
                                              
                                              │      │         │
                                              
                                              ▼      ▼         ▼
                                              
                                         Relay1 Relay2   Relay3 Relay4

                                                     │
                                                     
                                                     ▼
                                                     
                                                 LCD 16x2
                                                 
                                                Shows Status
