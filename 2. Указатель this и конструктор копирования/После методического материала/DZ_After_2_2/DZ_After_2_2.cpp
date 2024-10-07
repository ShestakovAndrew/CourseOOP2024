#include <iostream>

#include "Person.h"

int Person::instanceCount = 0;

int main()
{
	setlocale(LC_ALL, "rus");

    Person person1(1, "Шестаков", "Андрей", "Дмитриевич", Date(1, 1, 1990));
	Person person2(2, "Петров", "Пётр", "Петрович", Date(2, 2, 1992));

	person1.Display();
	person2.Display();

	std::cout << "Количество созданных экземпляров класса Person: " << Person::GetInstanceCount() << std::endl;
}