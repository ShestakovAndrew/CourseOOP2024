#pragma once
#include "../DZ_After_2_2/Person.h"

class Apartment
{
private:
	Person* m_persons;
	int m_personCount;
	int m_capacity;

public:
	Apartment();

	Apartment(const Apartment& other);

	void AddPerson(const Person& person);

	void DisplayPersons() const;

	Apartment& operator=(const Apartment& other);

	~Apartment();
};

