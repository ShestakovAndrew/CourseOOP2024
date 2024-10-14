#include <iostream>
#include <memory>

#include "Person.h"

int Person::instanceCount = 0;

Person::Person(int id, const char* lastName, const char* firstName, const char* middleName, Date birthDate)
	: m_id{ id }, m_birthDate{ birthDate }
{
	m_lastName = new char[strlen(lastName) + 1];
	m_firstName = new char[strlen(firstName) + 1];
	m_middleName = new char[strlen(middleName) + 1];

	strcpy_s(m_lastName, sizeof(lastName) * 2, lastName);
	strcpy_s(m_firstName, sizeof(firstName) * 2, firstName);
	strcpy_s(m_middleName, sizeof(middleName) * 2, middleName);

	instanceCount++;

	std::cout << "Person constr: " << this << std::endl;
}

Person::Person() : Person(0, "Неизвестно", "Неизвестно", "Неизвестно", Date())
{
}

Person::Person(const Person& other)
	: m_id{ other.m_id }, m_birthDate{ other.m_birthDate }
{
	m_lastName = new char[strlen(other.m_lastName) + 1];
	m_firstName = new char[strlen(other.m_firstName) + 1];
	m_middleName = new char[strlen(other.m_middleName) + 1];

	strcpy_s(m_lastName, sizeof(other.m_lastName) * 2, other.m_lastName);
	strcpy_s(m_firstName, sizeof(other.m_firstName) * 2, other.m_firstName);
	strcpy_s(m_middleName, sizeof(other.m_middleName) * 2, other.m_middleName);
	
	instanceCount++;
}

void Person::Display() const
{
	std::cout << "ID: " << m_id << std::endl
		<< "Фамилия: " << m_lastName << std::endl
		<< "Имя: " << m_firstName << std::endl
		<< "Отчетство: " << m_middleName << std::endl
		<< "Дата рождения: ";

	m_birthDate.Display();

	std::cout << std::endl;
}

Person& Person::operator=(const Person& other)
{
	if (this == &other) return *this;

	delete[] m_firstName;
	delete[] m_middleName;
	delete[] m_lastName;

	m_id = other.m_id;

	m_lastName = new char[strlen(other.m_lastName) + 1];
	m_firstName = new char[strlen(other.m_firstName) + 1];
	m_middleName = new char[strlen(other.m_middleName) + 1];

	strcpy_s(m_lastName, sizeof(other.m_lastName) * 2, other.m_lastName);
	strcpy_s(m_firstName, sizeof(other.m_firstName) * 2, other.m_firstName);
	strcpy_s(m_middleName, sizeof(other.m_middleName) * 2, other.m_middleName);

	return *this;
}

Person::~Person()
{
	std::cout << "Person: " << this << std::endl;
	delete[] m_firstName;
	delete[] m_middleName;
	delete[] m_lastName;

	instanceCount--;
}
