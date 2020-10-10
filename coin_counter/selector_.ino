void bulk_of_50(){
  bool last=true;
  lcd.clear();
  delay(300);
  int a=8;
  lcd.setCursor(0,0);
  lcd.print("Bulk of 50");
  lcd.setCursor(1,1);
  lcd.print("limit : ");
        lcd.setCursor(a,1);
    lcd.blink();
  long lim_50_Bulk=0;
 while(last){
      lcd.setCursor(a,1);
    key=keypad.getKey();
  switch(key){
    case NO_KEY:
       break;
    case '1':case '2':case '3':case '4':case '5':
    case '6':case '7':case '8':case '9':case '0':
    lcd.setCursor(a,1);
    a++;
    lcd.print(key);
    lim_50_Bulk=lim_50_Bulk*10+(key-'0');
    break;
    case '#':
        if(lim_50_Bulk%50>=1||lim_50_Bulk==0){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Invalid Amount");
      lcd.noBlink();
      delay(1000);
      last=false;
      bulk_of_50();
    }else{
    lcd.noBlink();
    lcd.setCursor(1,3);
    lcd.print(lim_50_Bulk);
    EEPROM.put(lim50_Address,int(lim_50_Bulk));
    lcd.setCursor(10,3);
    lcd.print("Tsh ");
    delay(1000);
    last=false;
    cont_setting();
    break;
    }
    case '*':
    a=8;
    lcd.setCursor(a,1);
    lcd.print("         ");
    lim_50_Bulk=0,a=8;
    lcd.setCursor(a,1);
    lcd.print(lim_50_Bulk);
    break;
    
     }
  }
  
}

void bulk_of_100(){
  bool last=true;
  lcd.clear();
  delay(300);
  int a=8;
  lcd.setCursor(0,0);
  lcd.print("Bulk of 100");
  lcd.setCursor(1,1);
  lcd.print("limit : ");
        lcd.setCursor(a,1);
    lcd.blink();
  long lim_100_Bulk=0;
 while(last){
      lcd.setCursor(a,1);
    key=keypad.getKey();
  switch(key){
    case NO_KEY:
       break;
    case '1':case '2':case '3':case '4':case '5':
    case '6':case '7':case '8':case '9':case '0':
    lcd.setCursor(a,1);
    a++;
    lcd.print(key);
    lim_100_Bulk=lim_100_Bulk*10+(key-'0');
    break;
    case '#':
            if(lim_100_Bulk%100>=1||lim_100_Bulk==0){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Invalid Amount");
      lcd.noBlink();
      delay(1000);
      bulk_of_100();
    }else{
    lcd.noBlink();
    lcd.setCursor(1,3);
    lcd.print(lim_100_Bulk);
    EEPROM.put(lim100_Address,int(lim_100_Bulk));
    lcd.setCursor(10,3);
    lcd.print("Tsh ");
    delay(1000);
    cont_setting();
    last=false;
    break;
    }
    case '*':
    a=8;
    lcd.setCursor(a,1);
    lcd.print("         ");
    lim_100_Bulk=0,a=8;
    lcd.setCursor(a,1);
    lcd.print(lim_100_Bulk);
    break;
    
     }
  }
}




void bulk_of_200(){
  bool last=true;
  lcd.clear();
  delay(300);
  int a=8;
  lcd.setCursor(0,0);
  lcd.print("Bulk of 200");
  lcd.setCursor(1,1);
  lcd.print("limit : ");
        lcd.setCursor(a,1);
    lcd.blink();
  long lim_200_Bulk=0;
 while(last){
      lcd.setCursor(a,1);
    key=keypad.getKey();
  switch(key){
    case NO_KEY:
       break;
    case '1':case '2':case '3':case '4':case '5':
    case '6':case '7':case '8':case '9':case '0':
    lcd.setCursor(a,1);
    a++;
    lcd.print(key);
    lim_200_Bulk=lim_200_Bulk*10+(key-'0');
    break;
    case '#':
     if(lim_200_Bulk%200>=1||lim_200_Bulk==0){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Invalid Amount");
      lcd.noBlink();
      delay(1000);
      bulk_of_200();
    }else{
    lcd.noBlink();
    lcd.setCursor(1,3);
    lcd.print(lim_200_Bulk);
    EEPROM.put(lim200_Address,int(lim_200_Bulk));
    lcd.setCursor(10,3);
    lcd.print("Tsh ");
    delay(1000);
    cont_setting();
    last=false;
    break;
    }
    case '*':
    a=8;
    lcd.setCursor(a,1);
    lcd.print("         ");
    lim_200_Bulk=0,a=8;
    lcd.setCursor(a,1);
    lcd.print(lim_200_Bulk);
    break;
    
     }
  }
}





void bulk_of_500(){
  bool last=true;
  lcd.clear();
  delay(300);
  int a=8;
  lcd.setCursor(0,0);
  lcd.print("Bulk of 500");
  lcd.setCursor(1,1);
  lcd.print("limit : ");
        lcd.setCursor(a,1);
    lcd.blink();
  long lim_500_Bulk=0;
 while(last){
      lcd.setCursor(a,1);
    key=keypad.getKey();
  switch(key){
    case NO_KEY:
       break;
    case '1':case '2':case '3':case '4':case '5':
    case '6':case '7':case '8':case '9':case '0':
    lcd.setCursor(a,1);
    a++;
    lcd.print(key);
    lim_500_Bulk=lim_500_Bulk*10+(key-'0');
    break;
    case '#':
      if(lim_500_Bulk%500>=1||lim_500_Bulk==0){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Invalid Amount");
      lcd.noBlink();
      delay(1000);
      bulk_of_500();
    }else{
    lcd.noBlink();
    lcd.setCursor(1,3);
    lcd.print(lim_500_Bulk);
    EEPROM.put(lim500_Address,int(lim_500_Bulk));
    lcd.setCursor(10,3);
    lcd.print("Tsh ");
    delay(1000);
    cont_setting();
    last=false;
    break;
    }
    case '*':
    a=8;
    lcd.setCursor(a,1);
    lcd.print("         ");
    lim_500_Bulk=0,a=8;
    lcd.setCursor(a,1);
    lcd.print(lim_500_Bulk);
    break;
    
     }
  }
}
