// Matrice LED 8x8
#include <MaxMatrix.h>
int DIN = 7;
int CLK = 6;
int CS = 5;
int maxInUse = 1;
byte buffer[20];
char text[] = "a";
MaxMatrix m(DIN, CS, CLK, maxInUse);

byte X[] = {
  2, 2,
  B10,
  B01
};

byte O[] = {
  2, 2,
  B11,
  B11
};

// Telecomanda IR
#include <IRremote.h>
#define UNU 0XFFA25D
#define DOI 0XFF629D
#define TREI 0XFFE21D
#define PATRU 0XFF22DD
#define CINCI 0XFF02FD
#define SASE 0XFFC23D
#define SAPTE 0XFFE01F
#define OPT 0XFFA857
#define NOO 0XFF906F
#define OK 0XFF38C7
const int RECV_PIN = 8;
const int RECV_PIN2 = 12;
IRrecv irrecv(RECV_PIN);

decode_results results;

// Ecran LCD
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Variabile pentru joc

  int start = 0;
  int board[10] = {0};
  int player1 = 0;
  int player2 = 0;
  int moves = 0;

// Functie de verificare win

int checkWin() {
   for (int i = 0; i < 3; i++) {
      if (board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3 + 2] == board[i * 3 + 3]) {
          if (board[i * 3 + 1] == 1) {
            start = 0;
            return 1;
          } else if (board[i * 3 + 1] == 2) {
            start = 0;
            return 2;
          } 
      }
   }

   for (int i = 1; i <= 3; i++) {
      if (board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
        if (board[i] == 1) {
            start = 0;
            return 1;
          } else if (board[i] == 2) {
            start = 0;
            return 2;
          }
      }
   }

   if (board[1] == board[5] && board[5] == board[9]) {
      if (board[1] == 1) {
            start = 0;
            return 1;
          } else if (board[1] == 2) {
            start = 0;
            return 2;
          }
   }

   if (board[3] == board[5] && board[5] == board[7]) {
      if (board[3] == 1) {
            start = 0;
            return 1;
          } else if (board[3] == 2) {
            start = 0;
            return 2;
          }
   }

   return 0;
}

void boardReset() {
  board[1] = 0;
  board[2] = 0;
  board[3] = 0;
  board[4] = 0;
  board[5] = 0;
  board[6] = 0;
  board[7] = 0;
  board[8] = 0;
  board[9] = 0;
}

void setup() {
  m.init();
  m.setIntensity(15);

   lcd.begin(16, 2);
  lcd.print("  Press OK to ");
  lcd.setCursor(0,1);
  lcd.print("    start :)");
  

  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);  
}


void loop() {

    if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }

  if (results.value == OK) {
    start = 1;
    lcd.clear();
    lcd.begin(16, 2);
    lcd.print("Player 1: ");
    lcd.print(player1);
    lcd.setCursor(0,1);
    lcd.print("Player 2: ");
    lcd.print(player2);
    results.value = 0;
  }

  if (start > 0)  {
    switch (results.value){
      case UNU:
        if(board[1] == 0) {
          if (start == 1) {
              board[1] = 1;
              moves++;
              start = 2;
              results.value = 0;
              delay(10);
          }
             else {
              board[1] = 2;
              moves++;
              start = 1;
              results.value = 0;
              delay(10);
             }
        }
        break;
      case DOI:
        if (board[2] == 0) {
          if (start == 1) {
              board[2] = 1;
              moves++;
              start = 2;
              results.value = 0;
              delay(10);
          }
             else {
              board[2] = 2;
              moves++;
              start = 1;
              results.value = 0;
              delay(10);
             }
        }
        break;
      case TREI:
      if (board[3] == 0) {
          if (start == 1) {
              board[3] = 1;
              moves++;
              start = 2;
              results.value = 0;
              delay(10);
          }
             else {
              board[3] = 2;
              moves++;
              start = 1;
              results.value = 0;
              delay(10);
             }
      }
        break;
      case PATRU:
        if (board[4] == 0) {
          if (start == 1) {
              board[4] = 1;
              moves++;
              start = 2;
              results.value = 0;
              delay(10);
          }
             else {
              board[4] = 2;
              moves++;
              start = 1;
              results.value = 0;
              delay(10);
             }
        }
        break;
      case CINCI:
        if (board[5] == 0) {
          if (start == 1) {
              board[5] = 1;
              moves++;
              start = 2;
              results.value = 0;
              delay(10);
          }
             else {
              board[5] = 2;
              moves++;
              start = 1;
              results.value = 0;
              delay(10);
             }
        }
        break;
      case SASE:
        if (board[6] == 0) {
          if (start == 1) {
              board[6] = 1;
              moves++;
              start = 2;
              results.value = 0;
              delay(10);
          }
             else {
              board[6] = 2;
              moves++;
              start = 1;
              results.value = 0;
              delay(10);
             }
        }
        break;
      case SAPTE:
        if (board[7] == 0) {
          if (start == 1) {
              board[7] = 1;
              moves++;
              start = 2;
              results.value = 0;
              delay(10);
          }
             else {
              board[7] = 2;
              moves++;
              start = 1;
              results.value = 0;
              delay(10);
             }
        }
        break;
      case OPT:
        if (board[8] == 0) {
          if (start == 1) {
              board[8] = 1;
              moves++;
              start = 2;
              results.value = 0;
              delay(10);
          }
             else {
              board[8] = 2;
              moves++;
              start = 1;
              results.value = 0;
              delay(10);
             }
          }
        break;
      case NOO:
        if (board[9] == 0) {
          if (start == 1) {
              board[9] = 1;
              moves++;
              start = 2;
              results.value = 0;
              delay(10);
          }
             else {
              board[9] = 2;
              moves++;
              start = 1;
              results.value = 0;
              delay(10);
             }
        }
        break;
      default:
        break;
    }  
  }

  if (board[1] == 1) {
    m.writeSprite(0, 0, X);
  } else if (board[1] == 2) {
    m.writeSprite(0, 0, O);
  }

  if (board[2] == 1) {
    m.writeSprite(3, 0, X);
  } else if (board[2] == 2) {
    m.writeSprite (3, 0, O);
  }
  
  if (board[3] == 1) {
    m.writeSprite(6, 0, X);
  } else if (board[3] == 2) {
    m.writeSprite (6, 0, O);
  }

  if (board[4] == 1) {
    m.writeSprite(0, 3, X);
  } else if (board[4] == 2) {
    m.writeSprite (0, 3, O);
  }

  if (board[5] == 1) {
    m.writeSprite(3, 3, X);
  } else if (board[5] == 2) {
    m.writeSprite (3, 3, O);
  }

  if (board[6] == 1) {
    m.writeSprite(6, 3, X);
  } else if (board[6] == 2) {
    m.writeSprite (6, 3, O);
  }

  if (board[7] == 1) {
    m.writeSprite(0, 6, X);
  } else if (board[7] == 2) {
    m.writeSprite (0, 6, O);
  }

  if (board[8] == 1) {
    m.writeSprite(3, 6, X);
  } else if (board[8] == 2) {
    m.writeSprite (3, 6, O);
  }

  if (board[9] == 1) {
    m.writeSprite(6, 6, X);
  } else if (board[9] == 2) {
    m.writeSprite (6, 6, O);
  }

  if (moves >= 5) {
    int win = checkWin();
    if (win == 1) {
      moves = 0;
      start = 0;
      player1 ++;
      

      lcd.clear();
      lcd.print("   Player 1 ");
      lcd.setCursor(0,1);
      lcd.print("     Wins !! ");
      delay(100);
      boardReset();
      delay(1500);
      lcd.clear();
      lcd.print("Press OK to start ");
      lcd.setCursor(0,1);
      lcd.print("new game!");
      m.clear();
    } else if (win == 2) {
      moves = 0;
      start = 0;
      player2 ++;
      

      lcd.clear();
      lcd.print("   Player 2 ");
      lcd.setCursor(0,1);
      lcd.print("     Wins !! ");
      delay(100);
      boardReset();
      delay(1500);
      lcd.clear();
      lcd.print("  Press OK to  ");  
      lcd.setCursor(0,1);
      lcd.print("start new game!");
      m.clear();     
    }
  }

  if (moves == 9) {
    if (checkWin() == 0) {
      moves = 0;
      start = 0;

      lcd.clear();
      lcd.print("   DRAW! ");
      lcd.setCursor(0,1);
      lcd.print("  :) ");
      delay(100);
      boardReset();
      delay(1500);
      lcd.clear();
      lcd.print("Press OK to start ");
      lcd.setCursor(0,1);
      lcd.print("new game!");
      m.clear();      
    }
  }
} 
