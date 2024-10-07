#pragma once

#include "Date.h"

class Person
{
public:
	Person();
	Person(int id, const char* lastName, const char* firstName, const char* middleName, Date birthDate);

	Person(const Person& person);

	void Display() const;

	static int GetInstanceCount()
	{
		return instanceCount;
	} 

	~Person();

private:

	int m_id;
	char* m_firstName; //Имя
	char* m_lastName; //Фамилия
	char* m_middleName; //Отчество

	Date m_birthDate;

	static int instanceCount;
};