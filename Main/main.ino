#include <LiquidCrystal.h>
#include <Keypad.h>

#define ROWS 4
#define COLS 4
#define PASSWORD_LENGTH 4

const char kp4x4Keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte KEYPAD_4x4_rowPin[ROWS] = {9, 8, 7, 6};
byte KEYPAD_4x4_colPin[COLS] = {5, 4, 3, 2};

Keypad kp4x4 = Keypad(makeKeymap(kp4x4Keys),KEYPAD_4x4_rowPin, KEYPAD_4x4_colPin,ROWS, COLS);

int counter = 0;
char userInput[PASSWORD_LENGTH];
char password[PASSWORD_LENGTH] = "5170";
bool isPasswordTrue;

LiquidCrystal lcd(4, 6, 11, 12, 13, 14);


void setup()
{
  Serial.begin(9600);
  Serial.println(F("Initialize system"));

  CD4511_SetPins();
}

void loop()
{
  bool password = KEYPAD_4x4_ReadInput();
  

  delay(10);
}

/* ---------------------------------------------------------------- */

bool KEYPAD_4x4_ReadInput()
{
  char customKey = kp4x4.getKey();

  if(customKey)
  {
    Serial.print("*");
    userInput[counter] = customKey;
    counter++;
  }

  if(counter == PASSWORD_LENGTH)
  {
    Serial.println("");
    isPasswordTrue = true;
    counter = 0;

    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
      if (userInput[i] != password[i])
      {
        isPasswordTrue = false;
        break;
      }
    }

    if (isPasswordTrue)
      Serial.println("CORRECT");
      return true;
    else
      Serial.println("INCORRECT");
      return false;

    char userInput[4];
  }
}

void CD4511_SetPins(){
  
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);

  digitalWrite(41, HIGH); // Set LampTest and Blank at HIGH
  digitalWrite(42, HIGH);

  //-----------------------

  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  
  digitalWrite(49, HIGH); // Set LampTest and Blank at HIGH
  digitalWrite(50, HIGH);

}

void CD4511_StartCounter(){
  
  // 9

  digitalWrite(5, HIGH);
  digitalWrite(2, HIGH);
  
  delay(1000);

  // 8
  
  digitalWrite(2, LOW);
  
  delay(1000);
  
  // 7

  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  
  delay(1000);

  // 6
  
  digitalWrite(2, LOW);
  
  delay(1000);

  // 5
  
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  
  delay(1000);

  // 4
  
  digitalWrite(2, LOW);
  
  delay(1000);

  // 3
  
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
  
  delay(1000);

  // 2
  
  digitalWrite(2, LOW);
  
  delay(1000);
  
  // 1
  
  digitalWrite(3, LOW);
  digitalWrite(2, HIGH);
  
  delay(1000);

  // 0
  
  digitalWrite(2, LOW);
  digitalWrite(9, HIGH); // LED turned on (Explosion)
}