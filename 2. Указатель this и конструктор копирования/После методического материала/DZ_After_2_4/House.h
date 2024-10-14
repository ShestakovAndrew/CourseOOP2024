#pragma once
#include "Apartment.h"

class House
{
private:
	Apartment* m_apartments;
	int m_apartmentCount;
	int m_capacity;

public:

	House();

	House(const House& other);

	void AddAppartment(const Apartment& apartment);

	void DisplayAparments() const;

	House& operator=(const House& other);

	~House();

};

