#include "Room.h"

Room::Room(std::string const& name, double length, double width, bool wallpaperOnCelling)
	: m_name{ name }, m_length{ length }, m_width{ width }, m_wallpaperOnCelling{ wallpaperOnCelling }
{
}

double Room::GetWallArea() const
{
	return 2 * (m_length + m_width) * 2.5;
}

double Room::GetCeilingArea() const
{
	return m_length * m_width;
}

double Room::GetTotalArea() const
{
	double area = GetWallArea();
	if (m_wallpaperOnCelling)
	{
		area += GetCeilingArea();
	}
	return area;
}
