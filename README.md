# Arduino Uno Experiments

This repository contains a set of basic Arduino experiments I created while learning and experimenting with the Arduino Uno. The goal was to explore different sensors, outputs, and simple interactive programs. These scripts helped me understand how to read inputs, control outputs, and implement simple logic.

## Sensors and Components Used
- **Rotary Encoder / Potentiometer**: Used to select notes in the guitar project and navigate the Tic-Tac-Toe board.
- **Button**: Used to trigger actions, such as playing a note or placing a mark in Tic-Tac-Toe.
- **NeoPixel LED Strip**: Used to display colorful light patterns.
- **Buzzer**: Used to play tones for the guitar project.
- **OLED Display (128x64)**: Used to display the Tic-Tac-Toe board and win messages.

---

## Scripts

### 1. Rainbow Flow (NeoPixel)
- **Library**: `Adafruit_NeoPixel`
- **Sensors / Components**: NeoPixel LED strip
- **Logic**: 
  - Cycles through a rainbow pattern across all LEDs.
  - Each LED color is determined by a position on a color wheel.
  - The pattern continuously shifts to create a flowing rainbow effect.

### 2. 3-Octave Guitar
- **Library**: None (uses built-in Arduino functions)
- **Sensors / Components**: Rotary potentiometer and button, buzzer
- **Logic**: 
  - The rotary knob selects a note from a 3-octave range.
  - Pressing the button plays the selected note on the buzzer.
  - Releasing the button stops the note.
  - A brief pause ensures notes change cleanly without overlap.

### 3. Tic-Tac-Toe on OLED
- **Library**: `U8g2` for the OLED display
- **Sensors / Components**: Rotary potentiometer and button, OLED display
- **Logic**: 
  - The rotary knob selects one of the nine squares.
  - Pressing the button places the current player's mark (X or O) on the board.
  - The program checks for a win after each move.
  - Displays a win message when a player wins.
  - Alternates turns between Player X and Player O.