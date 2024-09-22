#include <cmath>
#include <iostream>

#include "Apartment.h"

void Apartment::AddRoom(Room const& room)
{
	m_rooms.push_back(room);
}

void Apartment::CalculateWallpaperRequierments(std::vector<Roll> const& rolls)
{
	for (const Roll& roll : rolls)
	{
		double totalRoomArea = 0;

		for (const Room& room : m_rooms)
		{
			totalRoomArea += room.GetTotalArea();
		}

		double roolArea = roll.GetArea();

		size_t requiresRolls = std::ceil(totalRoomArea / roolArea);

		std::cout << "Для обоев " << roll.GetName() << " потребуется " << requiresRolls
			<< " рулонов общей стоимостью " << requiresRolls * roll.GetPrice() << " рублей." << std::endl;
	}
}
