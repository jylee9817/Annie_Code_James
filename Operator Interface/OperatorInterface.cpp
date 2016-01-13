#include "OperatorInterface.h"

OperatorInterface::OperatorInterface()
{
	joyDrive = new Joystick(0);
	// TJF: SmartDashboard is a singleton, so you can't create your own instance of it
	dashboard->init();
	SmartDashboard::init();
}

OperatorInterface::~OperatorInterface()
{
	delete joyDrive;
	
	joyDrive = NULL;
	dashboard = NULL;
}

SmartDashboard* OperatorInterface::getDashboard()
{
	return dashboard;
}
