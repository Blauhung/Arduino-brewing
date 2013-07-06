/*-----( controls temp sensor interaction )-----*/


/*----( initialize temperature sensors )----*/
//DeviceAddress tempHLT = { address };
//DeviceAddress tempMT = { address };
//DeviceAddress tempBK = { address };

void setupTemp() {
  MyWireBus.reset();
  sensors.begin();
  //sensors.setResolution(tempHLT, 10);
  //sensors.setResolution(tempMT, 10);
  //sensors.setResolution(tempBK, 10);
}

/*----( update temperature arrays )----*/
void updateTemp() {
  sensors.requestTemperatures(); // Send the command to get temperatures
  for (int i=0; i<NUM_TS; i++) {
    tempC[i] = sensors.getTempCByIndex(i);
    tempF[i] = (tempC[i]*1.8)+32;
  }
}
