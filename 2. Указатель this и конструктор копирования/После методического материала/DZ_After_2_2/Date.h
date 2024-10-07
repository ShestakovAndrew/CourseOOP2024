#pragma once

class Date
{
private:
	int m_day;
	int m_month;
	int m_year;

public:
	Date();
	Date(int day, int month, int year);

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	void Display() const;
};