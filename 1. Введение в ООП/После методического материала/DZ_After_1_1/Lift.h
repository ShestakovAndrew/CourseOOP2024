#pragma once

class Lift
{
public:

	Lift(size_t lowerFloor = 1, size_t upperFloor = 10);

	void TurtOn();
	void TurtOff();
	bool GetStatus() const;
	size_t GetCurrentFloor() const;

	void SetRange(size_t lowerFloor, size_t upperFloor);
	void CallLift(size_t floor);

	~Lift();

private:
	size_t m_currentFloor; //текущий этаж
	size_t m_lowerFloor; //Нижный этаж
	size_t m_upperFloor; //Верхний этаж
	bool m_isOn; //Состояние лифта
};

