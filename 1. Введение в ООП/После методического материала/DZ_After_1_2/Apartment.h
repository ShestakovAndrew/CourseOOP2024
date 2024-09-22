#pragma once
#include <vector>

#include "Room.h"
#include "Roll.h"

class Apartment
{
public:
	void AddRoom(Room const& room);

	void CalculateWallpaperRequierments(std::vector<Roll> const& m_rolls);

private: 
	std::vector<Room> m_rooms;
};

