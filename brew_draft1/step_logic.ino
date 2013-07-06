/*---( dictates behavior at brew step change )---
Step Definitions
0 = Ini, wait for input
1 = fill
2 = heat strike
3 = Strike mash
4 = mash
5 = mashout
6 = sparge
7 = boil
8 = transfer to ferment
9 = clean
*/



void setupStep() {
  switch (runStep){
    case 0:{
      runStepName = "SysInit";
      break;
    }
    case 1:{
      runStepName = "Fill";
      break;
    }
    case 2:{
      runStepName = "Heat Strike";
      break;
    }
    case 3:{
      runStepName = "Strike Mash";
      break;
    }
    case 4:{
      runStepName = "Mash";
      break;
    }
    case 5:{
      runStepName = "Mashout";
      break;
    }
    case 6:{
      runStepName = "Sparge";
      break;
    }
    case 7:{
      runStepName = "Boil";
      break;
    }
    case 8:{
      runStepName = "Transfer";
      break;
    }
    case 9:{
      runStepName = "Clean";
      break;
    }
  }
}

void stepAdvance(){
  runStep++; //increment run step variable
  lcdFlush = 0; //new step flags for LCD clear
  processStop(); //halt all control signals
  
}

/*---( closes all outputs )---*/
void processStop(){
  
}

/*---( System in error, halts program and closes outputs )---*/
void processHalt(){
  
}

void runFill(){
  
}
void runHeatStrike(){
  
}
void runStrikeMash(){
  
}
void runMash(){
  
}
void runMashOut(){
  
}
void runSparge(){
  
}
void runBoil(){
  
}
void runTransfer(){
  
}
void runClean(){
  
}
