#include <iostream>

#include "Lift.h"

Lift::Lift(size_t lowerFloor, size_t upperFloor)
{
	m_lowerFloor = lowerFloor;
	m_upperFloor = upperFloor;
	m_currentFloor = lowerFloor;
	m_isOn = false;
}

void Lift::TurtOn()
{
	m_isOn = true;
	std::cout << "���� ���������" << std::endl;
}

void Lift::TurtOff()
{
	m_isOn = false;
	std::cout << "���� ����������" << std::endl;
}

bool Lift::GetStatus() const
{
	return m_isOn;
}

size_t Lift::GetCurrentFloor() const
{
	return m_currentFloor;
}

void Lift::SetRange(size_t lowerFloor, size_t upperFloor)
{
	m_lowerFloor = lowerFloor;
	m_upperFloor = upperFloor;

	if (m_currentFloor < lowerFloor) m_currentFloor = lowerFloor;
	if (m_currentFloor > upperFloor) m_currentFloor = upperFloor;
}

void Lift::CallLift(size_t floor)
{
	if (!m_isOn)
	{
		std::cout << "���� ��������. ������� �������� ���." << std::endl;
		return;
	}

	if (floor < m_lowerFloor || floor > m_upperFloor)
	{
		std::cout << "���� ��� ���������. ���� ����� ��������� ������ ����� " 
			<< m_lowerFloor << " � " << m_upperFloor << "�������." << std::endl;
		return;
	}

	if (floor == m_currentFloor)
	{
		std::cout << "���� ��� ��������� �� ����� " << floor << std::endl;
		return;
	}
	else
	{
		std::cout << "���� ��������� � �����" 
			<< m_currentFloor << " �� ���� " << floor << "����" << std::endl;
		m_currentFloor = floor;
		std::cout << "���� ������ �� ���� " << floor << std::endl;
	}
}

Lift::~Lift()
{
}
