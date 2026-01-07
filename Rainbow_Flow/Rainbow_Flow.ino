#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 10
#define BRIGHTNESS 80

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint16_t offset = 0;

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();
}

void loop() {
  for (int i = 0; i < strip.numPixels(); i++) {
    int colorIndex = (i * 256 / strip.numPixels() + offset) % 256;
    strip.setPixelColor(i, colorWheel(colorIndex));
  }

  strip.show();
  offset++;
  delay(15);
}

uint32_t colorWheel(byte pos) {
  pos = 255 - pos;

  if (pos < 85) {
    return strip.Color(255 - pos * 3, 0, pos * 3);
  } else if (pos < 170) {
    pos -= 85;
    return strip.Color(0, pos * 3, 255 - pos * 3);
  } else {
    pos -= 170;
    return strip.Color(pos * 3, 255 - pos * 3, 0);
  }
}
