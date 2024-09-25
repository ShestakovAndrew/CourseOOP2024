#include "Person.h"
#include <memory>

Person::Person(int id, const char* firstName, const char* middleName, const char* lastName, Date birthDate)
	: m_id{ id }, m_birthDate{ birthDate }
{
	m_firstName = new char[strlen(firstName) + 1];
	m_middleName = new char[strlen(middleName) + 1];
	m_lastName = new char[strlen(lastName) + 1];

	strcpy_s(m_firstName, strlen(firstName), firstName);
	strcpy_s(m_middleName, strlen(middleName), middleName);
	strcpy_s(m_lastName, strlen(lastName), lastName);

	instanceCount++;
}

Person::Person() : Person(0, "Имя", "Фамилия", "Отчество", Date())
{
}

Person::Person(const Person& person)
{

}

Person::~Person()
{
	delete[] m_firstName;
	delete[] m_middleName;
	delete[] m_lastName;

	instanceCount--;
}
