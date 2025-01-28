# RGB-LED-SQUARE

Each square has 4 rows with 4 RGB LEDs. Each row is controlled by WS2811 LED driver. That means that individual LEDs can not be adressed (only rows).

## Wiring
- **VCC**: Connect the VCC pin of the LED squares to 12 V power supply.
- **GND**: Connect the GND pin of the LED squares to the GND of the power supply. 
       Optionally, you can connect the GND also to the dev board GND. 
- **DIN**: Connect the data pin of the LED squares to the dev board GPIO pin (used in this example).
       Logic voltage shold be 3 to 5 V DC.
- **DOUT**: Connect the DOUT pin of the LED squares to the DIN pin of the next LED square.
