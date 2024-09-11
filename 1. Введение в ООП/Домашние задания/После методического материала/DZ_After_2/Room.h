#pragma once
#include <string>

class Room
{
public:
	Room(std::string const& name, double length, double width, bool wallpaperOnCelling);

	double GetWallArea() const;

	double GetCeilingArea() const;

	double GetTotalArea() const;

private:
	std::string m_name;
	double m_length;
	double m_width;
	bool m_wallpaperOnCelling;
};

