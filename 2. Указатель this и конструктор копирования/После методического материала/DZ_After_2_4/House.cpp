#include "House.h"
#include <iostream>

House::House()
	: m_apartmentCount{ 0 }, m_capacity{2}
{
	m_apartments = new Apartment[m_capacity];

	std::cout << "House constr: " << this << std::endl;
}

House::House(const House& other)
	: m_apartmentCount{ other.m_apartmentCount }, m_capacity{ other.m_capacity }
{
	m_apartments = new Apartment[m_capacity];

	for (size_t i = 0; i < m_apartmentCount; i++)
	{
		m_apartments[i] = other.m_apartments[i];
	}
}

void House::AddAppartment(const Apartment& apartment)
{
	if (m_apartmentCount == m_capacity)
	{
		m_capacity *= 2;
		Apartment* newApartments = new Apartment[m_capacity];
		for (size_t i = 0; i < m_apartmentCount; i++)
		{
			newApartments[i] = m_apartments[i];
		}
		delete[] m_apartments;
		m_apartments = newApartments;
	}

	m_apartments[m_apartmentCount++] = apartment;
}

void House::DisplayAparments() const
{
	std::cout << " вартиры в доме: " << std::endl;

	for (size_t i = 0; i < m_apartmentCount; i++)
	{
		m_apartments[i].DisplayPersons();
	}
}

House& House::operator=(const House& other)
{
	if (this == &other) return *this;

	delete[] m_apartments;

	m_apartmentCount = other.m_apartmentCount;
	m_capacity = other.m_capacity;

	m_apartments = new Apartment[m_capacity];

	for (size_t i = 0; i < m_apartmentCount; i++)
	{
		m_apartments[i] = other.m_apartments[i];
	}

	return *this;
}

House::~House()
{
	std::cout << "House: " << this << std::endl;
	delete[] m_apartments;
}
