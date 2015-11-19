#ifndef MANIPULATOR_H_
#define MANIPULATOR_H_

#include "WPILib.h"
#include "../Macros.h"
#include "../Operator Interface/OperatorInterface.h"
#include "ManipCamera.h"
#include "ManipArm.h"

class Manipulator
{
public:
	Manipulator();
	~Manipulator();

	void intakeBall(bool intake, bool outtake, double speed);
	void toggleCompressor(bool start);


	// DigitalInput *intakeSwitch;
	ManipArm *arm;
	ManipCamera *camera;
	Talon *intakeRoller;
	Timer *timer;
	Compressor* comp599;
	int step;

private:
	OperatorInterface* oi;
	int count;
};

#endif
