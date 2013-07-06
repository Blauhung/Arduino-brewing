/*-----( Controls LCD intaction )-----*/
boolean MenuCall = true; //holds program in menu loop while true
boolean buttonPressed = false; //holts in wait for button loop while false
int menuarray[4] = 0; //menu state array

char headString[] = "probe1 probe2 probe3";


void setupLCD() {
  lcd.begin(20,4);
  lcd.clear();
  lcd.home();
  lcd.print("Tony's Brewery      ");
}

void updateLCD() {
  //if at the begining of a new brew step, clears the LCD
  if (lcdFlush == 0) { 
    lcd.clear();
    lcdFlush = 1;
    lcd.print("Step"); 
    lcd.print(runStep);
    lcd.print(": ");
    lcd.print(runStepName);
  }
  
  if (button4.isPressed() && inProcess){
    MainMenu();
  }
  
    
  lcd.setCursor(0,1);
  lcd.print(headString);
  for (int i=0; i<NUM_TS; i++) {
    lcd.setCursor(i*7,3);
    lcd.print(tempC[i]);
    lcd.print("C");
  }
}

/*-- Menu setup --*/
void MainMenu(){
  lcd.clear();
  lcdFlush = 1;
  lcd.print("Tony's Brewery");
  lcd.setCursor(0,1);
  lcd.print("Main Menu:");
  lcd.setCursor(0,3);
  lcd.print(" LFT  RGT  SEL  BCK "); 
  menu[] = {1,0,0,0};
  
  /* Hold loop in menu mode untill process start  
  /* Use MenuCall = false to exit */
  while(MenuCall){
   if(menu[0] = 1 {
     lcdClearLine(0);
     lcd.print("All Stop");
     lcdClearLine(1);
     lcd.print("Stop All Outputs")
     
   } 
  }  
}

/* clears a row */
void lcdClearLine(int row){
  lcd.setCursor(0,row);
  lcd.print("                    ");
  lcd.setCursor(0,row);
}
  
