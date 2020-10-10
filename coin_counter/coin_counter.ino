#include <EEPROM.h>
#include <FastIO.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
bool last=false;
bool individual=false;
bool Total=true;
int limit[5]; //array that contain all values of set values;;

// limit[0]= for general bulk(all);
// limit[1]= for lim50_bulk;
// limit[2]= for lim100_bulk;
// limit[3]= for lim200_bulk;
// limit[4]= for lim500_bulk;
 int limGen_Address=100;
 int lim50_Address=200;
 int lim100_Address=300;
 int lim200_Address=400;
 int lim500_Address=500;


int f=5,mia1=6,mia2=7,mia5=8;
bool nostart=true;
bool Stop=false;
int vibrator=4;

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3,POSITIVE);
char key;
const byte rows = 4, cols = 3;
char keys[rows][cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[rows] = {A0, A1, A2, A3};
byte colPins[cols] = { 12,11,10};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

 bool backlightState=true;
void setup() {
  pinMode(f,INPUT);
  pinMode(mia1,INPUT);
  pinMode(mia2,INPUT);
  pinMode(mia5,INPUT);
 // pinMode(StartPin,INPUT);
  pinMode(vibrator,OUTPUT);
  digitalWrite(vibrator,HIGH);
  keypad.addEventListener(keypadEvent);
 char fore1[]="CoinUno";
 char fore2[]="Smart counter";
  Serial.begin(115200);
  lcd.begin(16,4);
  keypad.setHoldTime(1500);
    
  intro(5,2,40,fore1,fore2);
  delay(2000);
  intro_dimish(2,5,40,fore1,fore2);
  finalize();
  initial();
  
  }
int c50=0,c100=0,c200=0,c500=0;
long am50,am100,am200,am500;
void loop() {
key=keypad.getKey();
while(nostart){
  key=keypad.getKey();
  lcd.setCursor(2,2);
  lcd.print("PRESS START");
  if (key=='0'){
        nostart=false;
        lcd.clear();
  }
  
  else
   nostart=true;
}
digitalWrite(vibrator,LOW);
int fif,mia_1,mia_2,mia_5;
fif=digitalRead(f);
mia_1=digitalRead(mia1);
mia_2=digitalRead(mia2);
mia_5=digitalRead(mia5);
if(fif==0){
  am50=50*c50++;
}
if(mia_1==0){
  am100=100*c100++;
}
if(mia_2==0){
  am200=200*c200++;
}
if(mia_5==0){
  am500=500*c500++;
}
long totalAmount=am50+am100+am200+am500;
lcd.setCursor(0,0);
 lcd.print("50");
 lcd.setCursor(0,1);
 lcd.print("100");
 lcd.setCursor(0,2);
 lcd.print("200");
 lcd.setCursor(0,3);
 lcd.print("500");
 lcd.setCursor(4,0);
 lcd.print(am50);
 lcd.setCursor(4,1);
 lcd.print(am100);
 lcd.setCursor(4,2);
 lcd.print(am200);
 lcd.setCursor(4,3);
 lcd.print(am500);

 delay(80);
if(Total){
    lcd.setCursor(11,0);
 lcd.print("TOTAL");
 lcd.setCursor(11,1);
 lcd.print(totalAmount);
  int limTotal;
  EEPROM.get(limGen_Address,limTotal);
  if(totalAmount>=limTotal){
    digitalWrite(vibrator,HIGH);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Limit Reached");
    delay(2000);
      totalAmount=0;
  am50=0,am100=0,am200=0,am500=0;
  c50=0,c100=0,c200=0,c500=0;
  lcd.clear();
    
  }
}
if(individual){
  int limi50,limi100,limi200,limi500;
  EEPROM.get(lim50_Address,limi50);
   EEPROM.get(lim100_Address,limi100);
   EEPROM.get(lim200_Address,limi200);
    EEPROM.get(lim500_Address,limi500);
    if(am50>=limi50){
    digitalWrite(vibrator,HIGH);
    lcd.clear();
           lcd.setCursor(5,0);
    lcd.print("50");
    lcd.setCursor(0,1);
    lcd.print("Limit Reached");
    delay(2000);
  am50=0;
  c50=0;
  lcd.clear();
  }
      if(am100>=limi100){
    digitalWrite(vibrator,HIGH);
    lcd.clear();
           lcd.setCursor(5,0);
    lcd.print("100");
    lcd.setCursor(0,1);
    lcd.print("Limit Reached");
    delay(2000);
  am100=0;
  c100=0;
  lcd.clear();
  }
      if(am200>=limi200){
    digitalWrite(vibrator,HIGH);
    lcd.clear();
        lcd.setCursor(5,0);
    lcd.print("200");
    lcd.setCursor(0,1);
    lcd.print("Limit Reached");
    delay(2000);
  am200=0;
  c200=0;
  lcd.clear();
  }
      if(am500>=limi500){
    digitalWrite(vibrator,HIGH);
    lcd.clear();
           lcd.setCursor(5,0);
    lcd.print("500");
    lcd.setCursor(0,1);
    lcd.print("Limit Reached");
    delay(2000);
  am500=0;
  c500=0;
  lcd.clear();
  }
    
}

}
