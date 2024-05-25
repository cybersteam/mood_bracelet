# mood_bracelet
mood bracelet with PWM leds and protrinket 5V

setup - 
  adafruit libraries in your IDE
  AVR dude installed with apt or in IDE

checking ports:
 lsusb
 dmesg
 ls /dev/tty*

unlup and replug the trinket
maybe press reset button twice

avrdude -c usbtiny -p atmega328p -U flash:w:/home/ivan/Arduino/sketch_may25b/build/adafruit.avr.protrinket5/sketch_may25b.ino.hex
