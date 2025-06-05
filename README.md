# mood_bracelet
mood bracelet with PWM leds and protrinket 5V

SETUP: Steps:</br>
adafruit libraries in your IDE</br>
AVR dude installed with apt or in IDE</br>

SETUP: Commands used:</br>
wget https://github.com/adafruit/Trinket_Arduino_Linux/blob/master/99-adafruit-boards.rules</br>
sudo mv 99-adafruit-boards.rules /etc/udev/rules.d/</br>
sudo udevadm control --reload-rules</br>
sudo udevadm trigger</br>
sudo usermod -a -G dialout $USER</br>
lsusb

PROTRINKET PINOUT and other detail:
https://learn.adafruit.com/introducing-pro-trinket/pinouts
https://cdn-learn.adafruit.com/downloads/pdf/introducing-pro-trinket.pdf

checking ports:</br>
 lsusb</br>
 dmesg</br>
 ls /dev/tty*</br>

unlup and replug the trinket</br>
maybe press reset button twice</br>

e.g. ----->>      avrdude -c usbtiny -p atmega328p -U flash:w:/home/ivan/Arduino/sketch_may25b/build/adafruit.avr.protrinket5/sketch_may25b.ino.hex
