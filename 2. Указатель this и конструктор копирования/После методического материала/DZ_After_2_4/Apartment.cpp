#include <iostream>
#include "Apartment.h"

Apartment::Apartment()
	: m_personCount{0}, m_capacity{2}
{
	m_persons = new Person[m_capacity];

	std::cout << "Apartment constr: " << this << std::endl;
}

Apartment::Apartment(const Apartment& other)
	: m_personCount{other.m_personCount}, m_capacity(other.m_capacity)
{
	m_persons = new Person[m_capacity];

	for (size_t i = 0; i < m_personCount; i++)
	{
		m_persons[i] = other.m_persons[i];
	}
}

void Apartment::AddPerson(const Person& person)
{
	if (m_personCount == m_capacity)
	{
		m_capacity *= 2;
		Person* newPersons = new Person[m_capacity];
		for (size_t i = 0; i < m_personCount; i++)
		{
			newPersons[i] = m_persons[i];
		}
		delete[] m_persons;
		m_persons = newPersons;
	}

	m_persons[m_personCount++] = person;
}

void Apartment::DisplayPersons() const
{
	std::cout << "Жители квартиры: " << std::endl;

	for (size_t i = 0; i < m_personCount; i++)
	{
		m_persons[i].Display();
	}
}

Apartment& Apartment::operator=(const Apartment& other)
{
	if (this == &other) return *this;

	delete[] m_persons;

	m_personCount = other.m_personCount;
	m_capacity = other.m_capacity;

	m_persons = new Person[m_capacity];

	for (size_t i = 0; i < m_personCount; i++)
	{
		m_persons[i] = other.m_persons[i];
	}

	return *this;
}

Apartment::~Apartment()
{
	std::cout << "Apartment: " << this << std::endl;
	delete[] m_persons;
}