
  void keypadEvent(KeypadEvent key){
    int state=keypad.getState();
    if(state==HOLD&&key=='*'){
          if(backlightState==true){
//              lcd.noBacklight();
              backlightState=!backlightState;
           }
           else{
//              lcd.backlight();
              backlightState=!backlightState;
           }
         
    }
    if(state==HOLD&&key=='1'){
      lcd.clear();
      char query[]="Opening Settings";
      char status_[]="please Wait";
      intro(0,0,30,query,status_);
      delay(1000);//***********************************************************************************************************************************************
      total();
    }
     if(state==HOLD&&key=='2'){
      lcd.clear();
      char query[]="view prev. data";
      char status_[]="please Wait";
      intro(0,0,30,query,status_);
      delay(1000);//***********************************************************************************************************************************************
      lcd.clear();
      view_Data();
    }

         if(state==HOLD&&key=='0'){
      lcd.clear();
      lcd.noBlink();
      char query[]="  Change Mode";
      char status_[]=" please Wait";
      intro(0,0,15,query,status_);
      delay(600);
      last=false;
      lcd.clear();
      countingMode();
    }


  }
