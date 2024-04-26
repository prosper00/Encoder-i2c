simple ch32v003 firmware to read a rotary encoder input device, and convert it to i2c.

Usage / notes
- configured for a CH32V003 SOP8 package
- encoder inputs are connected to PA1 and PA2
- encoder pushbutton is connected to PC4
- all encoder pins are externally RC debounced and pulled up [todo: add schematic]
- device is configured as an i2c slave device on address 0x09.
- 'read' two bytes: the first byte is the rotation value, and the second byte indicates whether the button has been pressed
- values are reset to zero after a read
- no software debounce or acceleration scaling has been implemented
- i2c writes not currently implemented. TODO: update this firmware for a 20-pin package, and use writes to light LEDs

