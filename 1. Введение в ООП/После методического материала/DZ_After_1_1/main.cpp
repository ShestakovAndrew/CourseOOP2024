#include <iostream>

#include "Lift.h"

void PrintLiftInfo(Lift const& lift)
{
	std::cout << "Статус лифта: " << lift.GetStatus() << std::endl
			  << "Текущий этаж: " << lift.GetCurrentFloor() << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");

	Lift lift;

	PrintLiftInfo(lift);

	lift.TurtOn();

	PrintLiftInfo(lift);

	lift.CallLift(12);

	PrintLiftInfo(lift);

	lift.SetRange(1, 15);

	lift.CallLift(12);

	PrintLiftInfo(lift);

	lift.TurtOff();

	PrintLiftInfo(lift);

	lift.CallLift(1);
}