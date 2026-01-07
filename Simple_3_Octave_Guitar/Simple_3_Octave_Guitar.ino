#define BUZZ_PIN 5
#define BUTTON_PIN 6
#define ROTARY_PIN A0

// 3-octave range (C3 → B5)
int notes[] = {
  131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 247, // C3–B3
  262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, // C4–B4
  523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988  // C5–B5
};

int numNotes = sizeof(notes) / sizeof(notes[0]);

int currentNoteIndex = 0;
int lastNoteIndex = -1;

void setup() {
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  int rotaryValue = analogRead(ROTARY_PIN);
  int buttonState = digitalRead(BUTTON_PIN);

  // Map rotary to note range
  currentNoteIndex = map(rotaryValue, 0, 1023, 0, numNotes - 1);

  if (buttonState == HIGH) {
    if (currentNoteIndex != lastNoteIndex) {
      noTone(BUZZ_PIN);
      delay(5); // very brief pause to have a better distinction between notes
      tone(BUZZ_PIN, notes[currentNoteIndex]);
      lastNoteIndex = currentNoteIndex;
    }
  } else {
    noTone(BUZZ_PIN);
    lastNoteIndex = -1;
  }
}
