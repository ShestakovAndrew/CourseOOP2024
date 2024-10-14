#include <iostream>

#include "../DZ_After_2_2/Person.h"
#include "Apartment.h"
#include "House.h"

int main()
{
    setlocale(LC_ALL, "rus");

    Person person1(1, "Shestakov", "Andrew", "Dmitrievich", Date(26, 2, 2001));
    Person person2(2, "Romanova", "Tatiana", "Vladimirovna", Date(26, 2, 1990));

    Apartment apartment1;
    apartment1.AddPerson(person1);
    apartment1.AddPerson(person2);

    House house;
    house.AddAppartment(apartment1);
    house.DisplayAparments();
    
    return 0;
}