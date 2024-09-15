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
};

int main()
{
	/* Создаем и инициализируем экземпляр класса Date
	Выделяется память для экземпляра date1 и его персональных полей
	date1.day, date1.month, date1.year
	*/
	Date date1{ 1,1,2020 };

	/* Создаем и инициализируем экземпляр класса Date
	Выделяется память для экземпляра date2 и его персональных полей
	date2.day, date2.month, date2.year
	*/
	Date date2{ 24,07,1976 };

	/*
	Вызываем функцию-член print. Код функции-члена общий для всех экземпляров Date.
	*/
	date1.print();
	date2.print();

	return 0;
}