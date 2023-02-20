# Task
I2C/I2S/SPI/Analog (3%)

For this part, you need a chip, a breadboard and wires.

Connect a chip using I2C, I2S, SPI or ADC interface based on your Stage 2 proposal

Show that you can access the device


# Group
Zhang Zhen
Tian Linxue
Lim Zhi

# Introduction 
In this course design, an intelligent temperature detection and alarm system based on STM32F103 is implemented.to realize the collection and display of temperature, set the alarm temperature, and alarm the environment exceeding the set temperature.

https://youtu.be/5GZ3V-UoJ7w

# components 
STM32F103C8T6 microcontroller is selected as the main control chip and S18B20 temperature sensor to collect temperature data, and the temperature is displayed on the OLED LCD screen, and the buzzer and button are connected to set the alarm temperature. After the set temperature is exceeded, the alarm function is realized. The specific circuit can be seen in the figure below.

# step 
Create a new project in STM32CudeIDE

Choosing the right board (STM32F103C8)

Initialize GPIOA—GPIOB

Initialize key delay

Initialize temperature detection signal

Feedback information to OLED

Set alarm value alarm
