#ifndef DRIVE_H_
#define DRIVE_H_
#include "../Macros.h"
#include "../Operator Interface/OperatorInterface.h"

class Drive
{
public:
	Drive();
	~Drive();
	
	void shift(bool highButton, bool lowButton);
	bool getShiftState();
	
	float setLinVelocity(float linVal);
	
	float setTurnSpeed(float turn, bool turboButton);	
	
	void setLeftMotors(float velocity);
	void setRightMotors(float velocity);

	void drive(float joyY, float joyX);

	// TJF: Test only function
	void TestSpeedController(int device_id, float velocity);

private:
	CANTalon *frontLeftMotor;
	CANTalon *rearLeftMotor;
	CANTalon *frontRightMotor;
	CANTalon *rearRightMotor;
	DoubleSolenoid *shifter;
	float leftCmd;
	float rightCmd;	
};
#endif
