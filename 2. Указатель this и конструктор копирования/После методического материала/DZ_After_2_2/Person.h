#pragma once

#include "Date.h"

int Person::instanceCount = 0;

class Person
{
public:
	Person() = default;
	Person(int id, const char* firstName, const char* middleName, const char* lastName, Date birthDate);

	Person(const Person& person);

	~Person();

	static int GetInstanceCount()
	{
		return instanceCount;
	} 

private:

	int m_id;
	char* m_firstName;
	char* m_middleName;
	char* m_lastName;

	Date m_birthDate;

	static int instanceCount;
};

