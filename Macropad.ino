/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>
#include <Keyboard.h>

#include <Encoder.h>   
//Library for simple interfacing with encoders (up to two)
//low performance ender response, pins do not have interrupts
Encoder RotaryEncoderA(14, 15); //the LEFT encoder (encoder A)
Encoder RotaryEncoderB(10, 16);  //the RIGHT encoder (encoder B)


long positionEncoderA  = -999; //encoderA LEFT position variable
long positionEncoderB  = -999; //encoderB RIGHT position variable


const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'*','0','#'},
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};


byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int mode = 1;
int new_mode = 0;

void setup(){
  Serial.begin(9600);
  Keyboard.begin(KeyboardLayout_fr_FR);
}
  
void loop(){

  //encoderA_Mode0();                         //custom function for encoder A
  //encoderB_Mode0(); 

  char key = keypad.getKey();

  if (key){
    Serial.println(key);
    //Serial.println(mode);
  }

  switch (mode) {
    case 1 : MacroMode1(key);
      break;
    case 2 : MacroMode2(key);
      break;
    case 3 : MacroMode3(key);
      break;
    case 4 : MacroMode4(key);
      break;
  }
}


void changeMode(){
  mode +=1 ;
  if (mode == 5){
    mode = 1;
  }
  Serial.println(mode);
}


//============= Macro Modes 1-4 =========================================================

void MacroMode1(char key){
    switch (key) {
      case '*':   //Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('*');
        break;
      case '0':   changeMode();
        break;
      case '#':   Keyboard.print('#');
        break;
      case '1':   Keyboard.print('1');
        break;
      case '2':   Keyboard.print('2');
        break;
      case '3':   Keyboard.print('3');
        break;
      case '4':   Keyboard.print('4');
        break;
      case '5':   Keyboard.print('5');
        break;
      case '6':   Keyboard.print('6');
        break;
      case '7':   Keyboard.print('7');
        break;
      case '8':   Keyboard.print('8');
        break;
      case '9':   Keyboard.print('9');
        break; 
    }
    delay(100); Keyboard.releaseAll();
}


void MacroMode2(char key){
    switch (key) {
      case '*':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('c');
        break;
      case '0':   changeMode();
        break;
      case '#':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '1':   Keyboard.press(KEY_LEFT_GUI);
                  Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.press(KEY_LEFT_ARROW);
        break;
      case '2':   Keyboard.press(KEY_LEFT_GUI);
                  Keyboard.press(KEY_LEFT_SHIFT);
                  Keyboard.print('m');
        break;
      case '3':   Keyboard.press(KEY_RIGHT_GUI);
                  Keyboard.press(KEY_RIGHT_CTRL);
                  Keyboard.press(KEY_RIGHT_ARROW);
        break;
      case '4':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('c');
        break;
      case '5':   Keyboard.press(KEY_LEFT_GUI);
                  Keyboard.print('m');
        break;
      case '6':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '7':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '8':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '9':   Keyboard.press(KEY_LEFT_CTRL);
        break; 
    }
    delay(100); Keyboard.releaseAll();
}


void MacroMode3(char key){
    switch (key) {
      case '*':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('c');
        break;
      case '0':   changeMode();
        break;
      case '#':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '1':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('c');
        break;
      case '2':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('v');
        break;
      case '3':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '4':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('c');
        break;
      case '5':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('v');
        break;
      case '6':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '7':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '8':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '9':   Keyboard.press(KEY_LEFT_CTRL);
        break; 
    }
    delay(100); Keyboard.releaseAll();
}


void MacroMode4(char key){
    switch (key) {
      case '*':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('c');
        break;
      case '0':   changeMode();
        break;
      case '#':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '1':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('c');
        break;
      case '2':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('v');
        break;
      case '3':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '4':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('c');
        break;
      case '5':   Keyboard.press(KEY_LEFT_CTRL);
                  Keyboard.print('v');
        break;
      case '6':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '7':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '8':   Keyboard.press(KEY_LEFT_CTRL);
        break;
      case '9':   Keyboard.press(KEY_LEFT_CTRL);
        break; 
    }
    delay(100); Keyboard.releaseAll();
}

//============= Encoder A & B basic principle =========================================================

void encoderA(){
  long newPos = RotaryEncoderA.read()/4; //When the encoder lands on a valley, this is an increment of 4.
  
  if (newPos != positionEncoderA && newPos > positionEncoderA) {
    positionEncoderA = newPos;
    Serial.println(positionEncoderA);
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);                      }

  if (newPos != positionEncoderA && newPos < positionEncoderA) {
    positionEncoderA = newPos;
    Serial.println(positionEncoderA);
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_RIGHT_ARROW);                      }
}

void encoderB(){
  long newPos = RotaryEncoderB.read()/4; //When the encoder lands on a valley, this is an increment of 4.
  if (newPos != positionEncoderB && newPos > positionEncoderB) {
    positionEncoderB = newPos;
    Serial.println(positionEncoderB);
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.release(KEY_UP_ARROW);                      }

  if (newPos != positionEncoderB && newPos < positionEncoderB) {
    positionEncoderB = newPos;
    Serial.println(positionEncoderB);
    Keyboard.press(KEY_DOWN_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);  }
}



//=============Encoder A & B Function ====== Set 0 =========================================================
void encoderA_Mode0(){
  long newPos = RotaryEncoderA.read()/4; //When the encoder lands on a valley, this is an increment of 4.
                                          // your encoder might be different (divide by 2) i dunno. 
  if (newPos != positionEncoderA && newPos > positionEncoderA) {
    positionEncoderA = newPos;
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.release(KEY_RIGHT_ARROW);
    Serial.println(newPos);                      }

  if (newPos != positionEncoderA && newPos < positionEncoderA) {
    positionEncoderA = newPos;
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.release(KEY_LEFT_ARROW);
    //Serial.println(newPos);                      }
    }
  }

void encoderB_Mode0(){
  long newPos = RotaryEncoderB.read()/4; 
  if (newPos != positionEncoderB && newPos > positionEncoderB) {
    positionEncoderB = newPos;
    Keyboard.press(KEY_DOWN_ARROW);
    Keyboard.release(KEY_DOWN_ARROW);
    //Serial.println(newPos);                      
    }

  if (newPos != positionEncoderB && newPos < positionEncoderB) {
    positionEncoderB = newPos;
    Keyboard.press(KEY_UP_ARROW);
    Keyboard.release(KEY_UP_ARROW);
    //Serial.println(newPos);                         }
    }
}

