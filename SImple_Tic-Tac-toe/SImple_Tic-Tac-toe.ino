#include <U8g2lib.h>

#define ROTARY_PIN A0
#define BUTTON_PIN 6

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// board: 0 = empty, 1 = X, 2 = O
int board[9] = {0,0,0,0,0,0,0,0,0};

int selectedCell = 0;
int currentPlayer = 1; // 1 = X, 2 = O
int lastButtonState = LOW;
bool gameOver = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT);

  u8g2.begin();
  u8g2.setFlipMode(1);
  u8g2.setFont(u8g2_font_6x10_tf);

  drawBoard();
}

void loop() {
  if (gameOver) return;

  int rotaryValue = analogRead(ROTARY_PIN);
  selectedCell = map(rotaryValue, 0, 1023, 0, 8);

  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH && lastButtonState == LOW) {
    if (board[selectedCell] == 0) {
      board[selectedCell] = currentPlayer;

      if (checkWin()) {
        gameOver = true;
        drawWinScreen();
        return;
      }

      currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
  }

  lastButtonState = buttonState;
  drawBoard();
}

// ---------------- DRAWING ----------------

void drawBoard() {
  u8g2.clearBuffer();

  // grid lines
  u8g2.drawLine(42, 0, 42, 64);
  u8g2.drawLine(84, 0, 84, 64);
  u8g2.drawLine(0, 21, 128, 21);
  u8g2.drawLine(0, 42, 128, 42);

  for (int i = 0; i < 9; i++) {
    int x = (i % 3) * 42 + 18;
    int y = (i / 3) * 21 + 15;

    if (i == selectedCell) {
      u8g2.drawFrame((i % 3) * 42 + 2, (i / 3) * 21 + 2, 38, 17);
    }

    if (board[i] == 1) {
      u8g2.drawStr(x, y, "X");
    } else if (board[i] == 2) {
      u8g2.drawStr(x, y, "O");
    }
  }

  u8g2.sendBuffer();
}

void drawWinScreen() {
  u8g2.clearBuffer();
  u8g2.setCursor(20, 30);

  if (currentPlayer == 1) {
    u8g2.print("X wins!");
  } else {
    u8g2.print("O wins!");
  }

  u8g2.sendBuffer();
}

// ---------------- LOGIC ----------------

bool checkWin() {
  int wins[8][3] = {
    {0,1,2}, {3,4,5}, {6,7,8}, // rows
    {0,3,6}, {1,4,7}, {2,5,8}, // cols
    {0,4,8}, {2,4,6}           // diagonals
  };

  for (int i = 0; i < 8; i++) {
    int a = wins[i][0];
    int b = wins[i][1];
    int c = wins[i][2];

    if (board[a] != 0 &&
        board[a] == board[b] &&
        board[a] == board[c]) {
      return true;
    }
  }
  return false;
}
