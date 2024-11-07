#include "IMPU.h"
#include "SampleConfig.h"

SampleConfig config;
IMPU& mpu =config.getMPU();

void setup(){
  Serial.begin(115200);
  while(!Serial);
  mpu.Calibrate();
}

void loop(){
  
}