#pragma once

class Student
{
private:
	// ФИО
	char name[21];
	// оценки
	int marks[3];
public:
	// чтение закрытых членов класса
	const char* getName()
	{
		return name;
	}

	int getMark(int index)
	{
		return marks[index];
	}
	// запись закрытых членов класса
	void setName(const char* studentName);
	void setMark(int mark, int index);
	// вычисление среднего балла
	double getAver();
};