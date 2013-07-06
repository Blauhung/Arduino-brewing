/*-----( Controls PID interaction )-----*/
PID pidHLT(&tempF[0], &pidOUT[0], &pidSET[0], kHLT[0], kHLT[1], kHLT[2], DIRECT);
PID pidMT(&tempF[1], &pidOUT[1], &pidSET[1], kMT[0], kMT[1], kMT[2], DIRECT);
PID pidBK(&tempF[2], &pidOUT[2], &pidSET[2], kBK[0], kBK[1], kBK[2], DIRECT);


void setupPID() {

  pidHLT.SetOutputLimits(0, eWindow);
  pidMT.SetOutputLimits(0, eWindow);
  pidBK.SetOutputLimits(0, eWindow);
  
    
}


void updatePID() {
  pidHLT.Compute();
  pidMT.Compute();
  pidBK.Compute();
  
}
