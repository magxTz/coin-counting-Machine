
void intro(int x,int y,int wait,char fore1[],char fore2[]){
int i;
for(i=0;i<strlen(fore1);i++){
  lcd.setCursor((x+i),1);
  lcd.print(fore1[i]);
  delay(wait);
}
for(i=0;i<strlen(fore2);i++){
  lcd.setCursor((y+i),2);
  lcd.print(fore2[i]);
  delay(wait);
  }
}
void intro_dimish(int x,int y,int wait,char fore1[],char fore2[]){
  int i;
  for(i=strlen(fore2);i>=0;i--){
  lcd.setCursor((x+i),2);
  lcd.print(" ");
  delay(wait);
  }
  for(i=strlen(fore1);i>=0;i--){
  lcd.setCursor((y+i),1);
  lcd.print(" ");
  delay(wait);
   }
}
void finalize(){
 int i;
 for(i=0;i<6;i++){
    if (i%2==0){
      lcd.setCursor(5,2);
      lcd.print("welcome");
    }
    else
     lcd.clear();
     delay(500);
 }
 for(i=0;i<4;i++){
  lcd.setCursor(0,i);
  lcd.print("________________");
  lcd.setCursor(0,i-1);
  lcd.print("                ");
  delay(200);
 }
}
void done() {
  lcd.clear();
  lcd.setCursor(1,2);
  lcd.noBlink();
  lcd.print("done setting up");
  delay(500);
  lcd.clear();
  // update limit array...
  for(int a=0;a<5;a++)
      limit[a]=EEPROM.get(100*(a+1),limit[a]);
      
    countingMode();
  }
  void countingMode(){
    lcd.clear();
    last=true;
    int a=8;
    int choice=0;
    char msg1[]="Mode of counting";
    char msg2[]="1.Total   2.Indv";
    
    intro(0,0,30,msg1,msg2);
    while(last){
    lcd.setCursor(a,3);
    lcd.blink();
    key=keypad.getKey();
    if(key!=NO_KEY&&(key=='1'||key=='2')){
       lcd.setCursor(a,3);
       lcd.print(key);
       lcd.noBlink();
       choice= key-'0';
       
      
    }
    if(key!=NO_KEY&&key=='#'){
      last=false;
      lcd.noBlink();
      break;
    } 
  }
    lcd.clear();
    if(choice==0|| choice>2){
      lcd.clear();
      lcd.setCursor(1,1);
      lcd.print("Wrong Selection");
      delay(1000);
      countingMode();
    }
    if (choice==1){
      lcd.setCursor(1,1);
      Total=true;
      individual=false;
    }
    if(choice==2){
      individual=true;
      Total=false;
    }
     loop();
  }

