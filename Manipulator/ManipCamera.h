#ifndef MANIP_CAMERA_H_
#define MANIP_CAMERA_H_

#include "WPILib.h"

#include "../Macros.h"

class ManipCamera
{
public:
	ManipCamera();
	~ManipCamera();

	void toggleCameraPosition(bool isForward);
	int getCameraPosition();

	Victor *cameraMotor;
	AnalogInput *pot;
};

#endif
