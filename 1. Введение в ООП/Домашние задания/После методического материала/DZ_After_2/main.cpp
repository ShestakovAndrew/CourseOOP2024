#include <iostream>
#include <vector>

#include "Apartment.h";
#include "Room.h";
#include "Roll.h"

int main()
{
	size_t numberOfRooms;
	std::cout << "¬ведите кол-во комнат: ";
	std::cin >> numberOfRooms;

	Apartment aparment;

	for (size_t i = 0; i < numberOfRooms; i++)
	{
		std::string name;
		double length, width;
		bool wallpaperOnCelling;

		std::cout << "¬ведте название комнаты " << (i + 1) << ": ";
		std::cin >> name;

		std::cout << "¬ведте длину комнаты (в метрах): ";
		std::cin >> length;

		std::cout << "¬ведте ширину комнаты (в метрах): ";
		std::cin >> width;

		std::cout << " леить потолок? (1 - да, 0 - нет): ";
		std::cin >> wallpaperOnCelling;


		Room room(name, length, width, wallpaperOnCelling);
		aparment.AddRoom(room);
	}

	size_t numberOfRolls;
	std::cout << "¬ведите кол-во видов рулонов: ";
	std::cin >> numberOfRolls;

	std::vector<Roll> rolls;
	for (size_t i = 0; i < numberOfRolls; i++)
	{
		std::string name;
		double height, width, price;

		std::cout << "¬ведте название обоев " << (i + 1) << ": ";
		std::cin >> name;

		std::cout << "¬ведте длину рулона (в метрах): ";
		std::cin >> height;

		std::cout << "¬ведте ширину рулона (в метрах): ";
		std::cin >> width;

		std::cout << "¬ведите цену рулона: ";
		std::cin >> price;

		Roll roll(name, height, width, price);
		rolls.push_back(roll);
	}

	aparment.CalculateWallpaperRequierments(rolls);
}