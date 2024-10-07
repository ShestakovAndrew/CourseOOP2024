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
	char* m_firstName; //���
	char* m_lastName; //�������
	char* m_middleName; //��������

	Date m_birthDate;

	static int instanceCount;
};