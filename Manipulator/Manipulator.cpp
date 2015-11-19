#include "Manipulator.h"

Manipulator::Manipulator()
{
	intakeRoller = new Talon(INTAKE_ROLLER_CHANNEL);
	//intakeSwitch = new DigitalInput(1, INTAKE_SWITCH_CHANNEL);
	comp599 = new Compressor(0);//change port as needed
	comp599->Start();

	step = 0;
	count = 0;
}

Manipulator::~Manipulator()
{
	delete intakeRoller;
	//delete intakeSwitch;
	
	intakeRoller = NULL;
	//intakeSwitch = NULL;
}

void Manipulator::intakeBall(bool outtake, bool intake, double speed)
{
	bool lastSwitchHit = false;

	if(!lastSwitchHit)
	{
		step = 1;
		if(outtake)
		{
			intakeRoller->Set(-speed, SYNC_STATE_OFF);
		}
		else if(intake)
		{
			intakeRoller->Set(speed, SYNC_STATE_OFF);
		}
		else
		{
			intakeRoller->Set(0, SYNC_STATE_OFF);
		}
	}
}

void Manipulator::toggleCompressor(bool start)
{
	// TODO: make this make sense
	if(start)
		count++;

	if(count%2 == 0)
		comp599->Stop();//checks if compressor has started, if it has then stop it
	else
		comp599->Start();// start the compressor
}
