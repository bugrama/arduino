#include "IMPU.h"
#include "SampleConfig.h"

SampleConfig config;
IMPU& mpu = config.getMPU();



// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	while (!Serial);
	mpu.Init();
}

// the loop function runs over and over again until power down or reset
void loop() {
	float y, p, r;
	mpu.getYawPitchRoll(y, p, r);

	Serial.print(y);
	Serial.print("\t");
	Serial.print(p);
	Serial.print("\t");
	Serial.println(r);
  
	
  
}
