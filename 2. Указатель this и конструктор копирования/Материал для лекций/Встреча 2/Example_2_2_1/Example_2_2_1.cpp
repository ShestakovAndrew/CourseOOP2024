#include <iostream>

class Date
{
	int day;
	int month;
	int year;
public:
	Date(int dayP, int monthP, int yearP)
		:day{ dayP }, month{ monthP }, year{ yearP }
	{}
	Date() : Date(1, 1, 1970) {}
	void print() { std::cout << day << '.' << month << '.' << year << '\n'; }
	void setDay(int dayP) { day = dayP; }
	void setMonth(int monthP) { month = monthP; }
	void setYear(int yearP) { year = yearP; }
};

int main()
{
	Date date1;
	date1.setDay(29);
	date1.setMonth(2);
	date1.setYear(2004);
	date1.print();

	return 0;
}