#pragma once
#include "IMPU.h"
#include "IeepromMPU.h"

class WMPU: public IMPU
{
public:
	WMPU(IeepromMPU& ieepromMPU);
	// Inherited via IMPU
	void Init() override;
	void getYawPitchRoll(float& y, float& p, float& r) override;
	void Calibrate() override;
	bool isCalibrated() override;
	void resetCalibFlag() override;

private:
	IeepromMPU& eepromMngr;
	void guessOffsets();
	void loadCalibration();
	int begin();
};

