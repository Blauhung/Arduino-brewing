/*--
Brewing software by Tony Narciso, 2012
narciso.tony@gmail.com

general code is inspired by various arduino tutorials and BrewTroller available at www.brewtroller.com
*/

/*-----( includes )-----*/
#include <OneWire.h> //onewire communication
#include <DallasTemperature.h> //read temperature
#define ONE_WIRE_BUS 2 //Define onewire pinout
/*initialize onewire*/
OneWire MyWireBus(ONE_WIRE_BUS); //start OneWire library using pin defined as bus
DallasTemperature sensors(&MyWireBus); //pass bus to DStemp library

/*----( setup LCD )----*/
#include "Wire.h"
#include "LiquidCrystal.h"
LiquidCrystal lcd(0);

/*-----( Setup PID )-----*/
#include <PID_v1.h>

/*-----( Initialize buttons )-----*/
#include <Button.h>
Button button1 = Button(46,PULLUP);
Button button2 = Button(47,PULLUP);
Button button3 = Button(48,PULLUP);
Button button4 = Button(49,PULLUP);
int pressed = 0;

/*-----( constants definitions )-----*/
const int NUM_TS=2; //number of temp probes
const int NUM_PID=2; //number of PID controls
double tempC[NUM_TS]; //C array
double tempF[NUM_TS]; //F array
double temp1;  //???
unsigned long starttime, ttime; //timers 
int eWindow;  //element duty cycle window
double pidSET[NUM_PID];  //PID setpoints
double pidOUT[NUM_PID];  //PID output
/*PID constants [Kp, Ki, Kd] */
double kHLT[3] = {2, 2, 2};
double kMT[3] = {2, 2, 2};
double kBK[3] = {2, 2, 2};


unsigned int runStep = 0; //step tracker
const char* runStepName; //step tracker name
unsigned int lcdFlush = 0; //LCD tracker
int j = 1; //debug counter

boolean inProcess = false;


/*----( Main setup )----*/
void setup() {
  /*init LCD and wait for input*/
  setupLCD(); 
  lcd.setCursor(0,1);
  lcd.print("Begining init");

  /*init system and wait for input*/
  setupTemp();
  setupSerial();
  lcd.print("...DONE");
  lcd.setCursor(0,2);
  lcd.print("Start Program?      ");
  while (runStep == 0){
    if (button4.isPressed()){
      runStep++;
      lcd.setCursor(0,3);
      lcd.print("Loading.....");
    }
  }  
}

/*----( Main Loop )----*/
void loop() {
  

  starttime=millis(); //start loop timer
  setupStep();
  updateTemp();
  updatePID();
  updateLCD();
  //  serialRecieve();
  serialSend();

  ttime=millis()-starttime; //calculate loop time
}


