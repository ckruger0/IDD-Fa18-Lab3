# Data Logger (and using cool sensors!)

*A lab report by Chris Kruger - crk78*

## In The Report

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**<BR>
0 - 1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**<BR>
 10 bits of resolution across the range of values 0 - 1023

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**<BR>
I connected the R, G, and B pins of the LED to the 9 10 and 11 PWM pins on the arduino. I connected the common anode to the 5V rail.

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**<BR>
0 - 4.94 V (Basically 5V)<BR>
Voltage values were calculated using **analogReadValue * (5.0 / 1023.0)**

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**<BR>
 Voltage relative to force applied appears to have a logarithmic relationship. There is rapid rise at the beginning, however there is a clear ceiling where more force is applied linearly however it isn't represented that way in the serial plotter.
<BR><img src="https://i.imgur.com/cfJY3jK.png">

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

### 2. Accelerometer
 
<a href="https://github.com/ckruger0/IDD-Fa18-Lab3/blob/master/accel_lcd_print.ino">Accelerometer Read-Out Code</a>

### 3. IR Proximity Sensor

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**<BR>
 There is increased voltage the closer you are to the proximity sensor (aside from a small drop off when you get too close), and it drops off rapidly as you move away from the sensor. This is roughly in line with what I expected from the datasheet, however their chart has a more pronounced parabolic shape.

**b. Upload your merged code to your lab report repository and link to it here.**<BR>
 
 Building upon the prior accelerometer read-out code, I added the capability to write proximity data to the serial monitor, while the original accelerometer data writes to LCD: 
<a href = "https://github.com/ckruger0/IDD-Fa18-Lab3/blob/master/accel_vcnl_lcd.ino">Merged Code</a>

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
