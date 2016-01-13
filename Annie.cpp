#include "Macros.h"
#include "Drive/Drive.h"
#include "Manipulator/Manipulator.h"
#include "Manipulator/ManipArm.h"
#include "Catapult/Catapult.h"
#include "Operator Interface/OperatorInterface.h"


class Annie: public IterativeRobot
{
private:
	Drive *drive;
	Manipulator *manip;
	ManipArm* manipArm;
	Catapult *catapult;
	OperatorInterface *oi;

	void RobotInit()
	{
		manipArm = new ManipArm();
		drive = new Drive();
		manip = new Manipulator();
		// TJF: new catapult constructor needs pointer to an OperatorInterface
		//catapult = new Catapult();
		oi = new OperatorInterface();
		catapult = new Catapult(oi);

	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		manip->toggleCompressor(oi->joyDrive->GetRawButton(COMPRESSOR_BUTTON));

		//drive
		drive->drive(oi->joyDrive->GetRawAxis(FORWARD_Y_AXIS), oi->joyDrive->GetRawAxis(TURN_X_AXIS));
		drive->shift(oi->joyDrive->GetRawButton(8), oi->joyDrive->GetRawButton(9));

		//manipulator
		// TJF: Replaced "magic numbers" with named constants
		manipArm->moveArm(oi->joyDrive->GetRawButton(UP_INTAKE_BUTTON), oi->joyDrive->GetRawButton(DOWN_INTAKE_BUTTON)); //manipArm->moveArm(oi->joyDrive->GetRawButton(6), oi->joyDrive->GetRawButton(7));
		manip->intakeBall(oi->joyDrive->GetRawButton(INTAKE_BUTTON), oi->joyDrive->GetRawButton(OUTTAKE_BUTTON), (oi->joyDrive->GetThrottle()+1)/2);

		// TJF: removed only because it doesn't work yet
		catapult->launchBall();
	}

	void printSmartDashboard()
	{
		SmartDashboard::PutNumber("Drive Y-Value", oi->joyDrive->GetRawAxis(FORWARD_Y_AXIS)); //oi->getDashboard()->PutNumber("Drive Y-Value", oi->joyDrive->GetRawAxis(FORWARD_Y_AXIS));
		SmartDashboard::PutNumber("Drive X-Value", oi->joyDrive->GetRawAxis(TURN_X_AXIS));//oi->getDashboard()->PutNumber("Drive X-Value", oi->joyDrive->GetRawAxis(TURN_X_AXIS));

		SmartDashboard::PutBoolean("Compressor On?", manip->compressorState()); //oi->getDashboard()->PutBoolean("Compressor On?", manip->compressorState());


		SmartDashboard::PutNumber("Gyro value", drive->getGyroDashboard());//NavX gyro dashboard testing

	}

	void TestPeriodic()
	{

	}
};

START_ROBOT_CLASS(Annie);
