#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(9,8,7,6,5,4);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns 

char hexaKeys [ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'C','0','=','+'}};
  //define the symbol on the buttons of the keypad
byte rowPins [ROWS] = {3,2,19,18};
byte colPins [COLS] = {17,16,15,14};

Keypad customKeypad = Keypad (
  makeKeymap (hexaKeys),
  rowPins,
  colPins, 
  ROWS,
  COLS
  );

const byte LED_GREEN =11;
const byte LED_RED =10;
const byte RELAY =12;

char keycount=0;
char code[4]; //hold pressed keys

void clearLine(byte row){
  lcd.setCursor(0,row);
  lcd.print("                ");
}

void setup(){
  pinMode(LED_GREEN,OUTPUT);
  pinMode(LED_RED,OUTPUT);
  pinMode(RELAY,OUTPUT);

  lcd.begin(16,2);
  lcd.print("Password Access:");
  lcd.setCursor(0,1);
  lcd.cursor();
  digitalWrite(LED_GREEN,HIGH);
  digitalWrite(LED_RED,LOW);
  digitalWrite(RELAY,LOW);
}
void loop(){
  char customKey = customKeypad.getKey();
  
  if(customKey&&(keycount<4)&&(customKey !='=')&& (customKey !='C')){
    lcd.print('*');
    code[keycount]=customKey;
    keycount++;
  }

  if(customKey =='C'){
    Lock();
  }

  if(customKey =='=')
  {
    if((code[0]=='1')&& (code[1]=='2')&&(code[2]=='3')&&(code[3]=='4'))
    {
      digitalWrite(LED_GREEN,LOW);
      digitalWrite(LED_RED,HIGH);
      digitalWrite(RELAY,HIGH);
      clearLine(1);
      lcd.setCursor(0,1);
      lcd.print("DOOR OPEN");
      delay(5000); // keep door open for 5 seconds
      Lock();
    }
    else{
      clearLine(1);
      lcd.setCursor(0,1);
      lcd.print("invalid Password!"); //Display error
      delay(1500); //Message delay for 2 seconds
      clearLine(1);
      Lock();
    }
  }
}
void Lock() {
  lcd.setCursor(0,1);
  lcd.print("DOOR LOCKED");
  delay(1500);
  clearLine(1);
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  keycount=0;
  digitalWrite(LED_GREEN,HIGH);
  digitalWrite(LED_RED,LOW);
  digitalWrite(RELAY,LOW);
}