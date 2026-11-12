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

                                                
<img width="742" height="408" alt="1615453918-external-power-supply-circuit" src="https://github.com/user-attachments/assets/275a4968-8f32-473d-aa17-8ba531767b32" />
# circuit diagram 

<img width="1492" height="1054" alt="home" src="https://github.com/user-attachments/assets/74e44d3d-cc42-4417-aa43-76696ee8fdc3" />



# PCB DESIGN
<img width="472" height="380" alt="Arduino-IoT-Cloud-Home-Automation-PCB (1)" src="https://github.com/user-attachments/assets/9657f4a3-abc1-4397-a701-e8ba9ec61966" />


# 5. Sinric Pro configuration
Create four separate Switch devices in your Sinric Pro account.
Device	Name	Hardware

Switch 1	Living Room Light	Relay 1

Switch 2	Bedroom Light	Relay 2

Switch 3	Fan	Relay 3

Switch 4	Main Appliance	Relay 4


