#pragma once

class Date
{
private:
	int m_day;
	int m_month;
	int m_year;

public:
	Date() = default;
	Date(int day, int month, int year);

	void Display() const;
};