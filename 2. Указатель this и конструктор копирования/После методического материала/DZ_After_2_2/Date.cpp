#include <iostream>

#include "Date.h"

Date::Date(int day, int month, int year)
	: m_day{ day }, m_month{ month }, m_year{ year }
{
}

Date::Date() : Date(1, 1, 1970)
{
}

void Date::Display() const
{
	std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
}
