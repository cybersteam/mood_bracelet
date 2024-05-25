# mood_bracelet
mood bracelet with PWM leds and protrinket 5V

SETUP: Steps:
adafruit libraries in your IDE
AVR dude installed with apt or in IDE

SETUP: Commands used:
sudo mv 99-adafruit-boards.rules /etc/udev/rules.d/
sudo usermod -a -G dialout $USER
wget https://github.com/adafruit/Trinket_Arduino_Linux/blob/master/99-adafruit-boards.rules
sudo mv 99-adafruit-boards.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
lsusb


checking ports:
 lsusb
 dmesg
 ls /dev/tty*

unlup and replug the trinket
maybe press reset button twice

e.g. ----->>      avrdude -c usbtiny -p atmega328p -U flash:w:/home/ivan/Arduino/sketch_may25b/build/adafruit.avr.protrinket5/sketch_may25b.ino.hex
