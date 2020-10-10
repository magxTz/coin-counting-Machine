int setBulk(){
  lcd.clear();
  bool last=true;
  int a=8;
  lcd.setCursor(0,0);
  lcd.print("Total coin Bulk");
  lcd.setCursor(1,1);
  lcd.print("limit : ");
  long lim_Bulk=0;
 while(last){
      lcd.setCursor(a,1);
    lcd.blink();
    key=keypad.getKey();
  switch(key){
    case NO_KEY:
       break;
    case '1':case '2':case '3':case '4':case '5':
    case '6':case '7':case '8':case '9':case '0':
    lcd.setCursor(a,1);
    a++;
    lcd.print(key);
    lim_Bulk=lim_Bulk*10+(key-'0');
    break;
    case '#':
    if(lim_Bulk%50>=1||lim_Bulk==0){
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Invalid Amount");
      lcd.noBlink();
      delay(1000);
      last=false;
      setBulk();
    }else{
    lcd.noBlink();
    lcd.setCursor(1,3);
    lcd.print(lim_Bulk);
    EEPROM.put(limGen_Address,int(lim_Bulk));
    lcd.setCursor(7,3);
    lcd.print("Tsh_Total");
    delay(1000);
    individualCoin();
    last=false;
    break;
    }
    case '*':
    a=8;
    lcd.setCursor(a,1);
    lcd.print("         ");
    lim_Bulk=0,a=8;
    lcd.setCursor(a,1);
    lcd.print(lim_Bulk);
    break;
    
     }
  }
} 

void individualCoin(){
  int choice=0;
  bool last=true;
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("set individual");
  lcd.setCursor(0,1);
  lcd.print("   coin bulk");
  lcd.setCursor(2,2);
  lcd.print("1.Yes");
  lcd.setCursor(10,2);
  lcd.print("2.No");
  lcd.setCursor(8,3);
  lcd.blink();
 
while(last){
  key=keypad.getKey();
  switch(key){
     case NO_KEY:
       break;
     case '1':case '2':
      lcd.setCursor(8,3);
      choice=key-'0';
      lcd.print(choice);
      lcd.noBlink();
      break;
      
    }
    if(key== '#'){
      lcd.noBlink();
       last=false;
        break;
  }
}
  if(choice==1){
    individual=true;
    single_type_Bulk();
  }
  if(choice==2){
    individual=false;
    done();
  }
  if(choice==0|| choice>2){
      lcd.clear();
      lcd.setCursor(1,1);
      lcd.print("Wrong Selection");
      delay(1000);
      individualCoin();
    }
  
}


void total(){
  bool last=true;
  int choice=0;
  lcd.clear();
  delay(1000);
  lcd.setCursor(1,0);
  lcd.print("  set Total");
  lcd.setCursor(0,1);
  lcd.print("   coin bulk");
  lcd.setCursor(2,2);
  lcd.print("1.Yes");
  lcd.setCursor(10,2);
  lcd.print("2.No");
  lcd.setCursor(8,3);
  lcd.blink();
 
while(last){
  key=keypad.getKey();
  switch(key){
     case NO_KEY:
       break;
     case '1':case '2':
      lcd.setCursor(8,3);
      choice=key-'0';
      lcd.print(choice);
      lcd.noBlink();
      break;
      
    }
    if(key== '#'){
      lcd.noBlink();
       last=false;
        break;
  }
}
  if(choice==1){
    Total=true;
    setBulk();
  }
  if(choice==2){
    Total=false;
     individualCoin();
  }
 if(choice==0|| choice>2){
      lcd.clear();
      lcd.setCursor(1,1);
      lcd.print("Wrong Selection");
      delay(1000);
      total();
    }
  
  
}






void single_type_Bulk(){
  int choice_of_bulk=0;
  lcd.clear();
  bool last=true;
  delay(300);
  lcd.setCursor(0,0);
  lcd.print("choose coin");
  lcd.setCursor(0,1);
  lcd.print("1. 50    2. 100");
  lcd.setCursor(0,2);
  lcd.print("3. 200   4. 500");
    lcd.setCursor(8,3);
  lcd.blink();
  while(last){
    key=keypad.getKey();
    switch(key){
      case NO_KEY:
         break;
      case '1':case '2':case '3':case '4':
      choice_of_bulk=key-'0';
      lcd.setCursor(8,3);
      lcd.print(key);
      lcd.noBlink();
      break;
    }
    if(key=='#'){
      lcd.noBlink();
     last=false;
     break;
    }
  }
  if(choice_of_bulk==0|| choice_of_bulk>4){
      lcd.clear();
      lcd.setCursor(1,1);
      lcd.print("Wrong Selection");
      delay(1000);
      single_type_Bulk();
    }
  if(choice_of_bulk==1)
     bulk_of_50();
  else if(choice_of_bulk==2)
    bulk_of_100();
  else if(choice_of_bulk==3)
    bulk_of_200();
  else if(choice_of_bulk==4)
    bulk_of_500();
}
void cont_setting(){
  int decision;
  bool last=true;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1.Cont. setting?");
  lcd.setCursor(2,1);
  lcd.print("2.End...");
  lcd.setCursor(8,3);
  lcd.blink();
  while(last){
    key=keypad.getKey();
    switch(key){
      case NO_KEY:
      break;
      case '1':case '2':
        lcd.noBlink();
        lcd.setCursor(8,3);
        lcd.print(key);
        decision=key-'0';
        break;
    }
    if(key=='#'){
      lcd.noBlink();
     last=false;
    break;
    }
  }
  if(decision==1)
    single_type_Bulk();
  if(decision==2){
    lcd.clear();
    lcd.print("please Wait");
    lcd.setCursor(12,3);
    lcd.blink();
    delay(1000);
    done();
    
  }
  if(decision==0|| decision>2){
      lcd.clear();
      lcd.setCursor(1,1);
      lcd.print("Wrong Selection");
      delay(1000);
      cont_setting();
    }
}



