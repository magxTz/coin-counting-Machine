
void initial(){
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("prev_set data");
  lcd.setCursor(0,1);
  lcd.print("Total:");
  lcd.setCursor(7,1);
  lcd.print(EEPROM.get(limGen_Address,limit[0]));
  delay(500);
  lcd.setCursor(0,2);
  lcd.print("b_50:");
  lcd.setCursor(7,2);
  lcd.print(EEPROM.get(lim50_Address,limit[1]));
  delay(500);
  lcd.setCursor(0,3);
  lcd.print("b_100:");
  lcd.setCursor(7,3);
  lcd.print(EEPROM.get(lim100_Address,limit[2]));
  delay(500);
  lcd.setCursor(0,3);
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("prev_set data");
  lcd.setCursor(0,1);
  lcd.print("b_200:");
  lcd.setCursor(7,1);
  lcd.print(EEPROM.get(lim200_Address,limit[3]));
  delay(500);
   lcd.setCursor(0,2);
  lcd.print("b_500:");
  lcd.setCursor(7,2);
  lcd.print(EEPROM.get(lim500_Address,limit[4]));
  delay(1000);
  usePrev();
}
void usePrev(){
  bool last=true;
  int decision=0;
  lcd.clear();
  delay(1000);
  char q1[]=" Use prev Data?";
  char q2[]="1.Yes      2.No";
  intro(0,0,30,q1,q2);
  lcd.setCursor(7,3);
  lcd.blink();
  while(last){
    key=keypad.getKey();
    switch(key){
      case NO_KEY:
      break;
      case '1':case '2':
      lcd.setCursor(7,3);
      lcd.print(key);
      decision=key-'0';
      lcd.noBlink();
      break;
    }
    if(key=='#'){
      lcd.noBlink();
      last=false;
      break;
    }
  }
  if(decision==1){
      done();
  }
  if(decision==2)
        total();
  if(decision==0|| decision>2){
      lcd.clear();
      lcd.setCursor(1,1);
      lcd.print("Wrong Selection");
      delay(1000);
      usePrev();
    }
}

void view_Data(){
for(int i=0;i<5;i++){
  if(i==0){
   lcd.setCursor(1,1);
   lcd.print("Total is: "); 
   lcd.setCursor(10,1);
   lcd.print(limit[i]);
   delay(1000);
   lcd.setCursor(1,1);
   lcd.print("               ");
   delay(1000);

  }
  else{
   lcd.setCursor(1,0);
   lcd.print("b_50: ");
   lcd.setCursor(1,1);
   lcd.print("b_100: ");
   lcd.setCursor(1,2);
   lcd.print("b_200: ");
   lcd.setCursor(1,3);
   lcd.print("b_500: ");
   lcd.setCursor(9,i-1); 
   lcd.print(limit[i]);
   delay(100);
  }
 }
 delay(1000);
 lcd.clear();
 loop();
}
