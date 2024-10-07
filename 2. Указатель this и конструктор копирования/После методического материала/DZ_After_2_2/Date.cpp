#include <iostream>

#include "Date.h"

Date::Date(int day, int month, int year)
	: m_day{ day }, m_month{ month }, m_year{ year }
{
}

Date::Date() : Date(1, 1, 1970)
{
}

int Date::GetDay() const
{
	return m_day;
}

int Date::GetMonth() const
{
	return m_month;
}

int Date::GetYear() const
{
	return m_year;
}

void Date::Display() const
{
	std::cout << m_day << "/" << m_month << "/" << m_year << std::endl;
}
