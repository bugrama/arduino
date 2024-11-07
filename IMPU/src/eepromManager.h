#pragma once
#include "IeepromMPU.h"


class eepromManager :public IeepromMPU
{
	enum OffsetAddr
	{
		AddrxGyroE = 2,
		AddryGyroE = 4,
		AddrzGyroE = 6,
		AddrxAccelE = 8,
		AddryAccelE = 10,
		AddrzAccelE = 12,
	};
	const int CalibFlagAddr = 0;
	const int CalibFlagTrue = 77;
	const int CalibFlagFalse = 0;

	int readIntFromEEPROM(int address);
	void writeIntToEEPROM(int address, int value);

	// Inherited via IeepromMPU
	int getXGyroOffset() override;
	int getYGyroOffset() override;
	int getZGyroOffset() override;
	int getXAccelOffset() override;
	int getYAccelOffset() override;
	int getZAccelOffset() override;
	void setXGyroOffset(int os) override;
	void setYGyroOffset(int os) override;
	void setZGyroOffset(int os) override;
	void setXAccelOffset(int os) override;
	void setYAccelOffset(int os) override;
	void setZAccelOffset(int os) override;
	bool getCalibFlag() override;
	void setCalibFlag() override;
	void resetCalibFlag() override;
};

