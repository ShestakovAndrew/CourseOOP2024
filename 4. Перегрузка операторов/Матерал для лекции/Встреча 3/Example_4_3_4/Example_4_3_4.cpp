#include <iostream>
#include <cassert>

class MedalRow
{
private:
	char m_country[4];
	int m_medals[3];

public:
	static const int GOLD{ 0 };
	static const int SILVER{ 1 };
	static const int BRONZE{ 2 };

	MedalRow(const char* countryP, const int* medalsP)
	{
		strcpy_s(m_country, 4, countryP ? countryP : "NON");
		for (int i{ 0 }; i < 3; ++i)
		{
			m_medals[i] = medalsP ? medalsP[i] : 0;
		}
	}

	MedalRow() : MedalRow(nullptr, nullptr) {}

	MedalRow& setCountry(const char* countryP)
	{
		if (countryP)
		{
			strcpy_s(m_country, 4, countryP);
		}
		return *this;
	}

	const char* getCountry() const { return m_country; }

	int& operator[](int idx)
	{
		assert((idx >= 0 && idx < 3) && "Index out of range!");
		return m_medals[idx];
	}

	int operator[](int idx) const
	{
		assert((idx >= 0 && idx < 3) && "Index out of range!");
		return m_medals[idx];
	}

	void print() const
	{
		std::cout << '[' << m_country << "]-( ";
		for (int i{ 0 }; i < 3; ++i)
		{
			std::cout << m_medals[i];
			if (i < 2) { std::cout << '\t'; }
		}
		std::cout << " )\n";
	}
};

class MedalsTable
{
public:
	static const int maxSize{ 10 };

	MedalsTable() : m_size{ 0 } {};

	MedalRow& operator[](const char* country)
	{
		int idx{ findCountry(country) };
		if (idx == -1)
		{
			assert(m_size < MedalsTable::maxSize && "Table is FULL!");
			idx = m_size++;
			m_medalRows[idx].setCountry(country);
		}
		return m_medalRows[idx];
	}

	const MedalRow& operator[](const char* country) const
	{
		int idx{ findCountry(country) };
		assert(idx != -1 && "Country not found on const table");
		return m_medalRows[idx];
	}

	void print() const
	{
		for (int i{ 0 }; i < m_size; ++i)
		{
			m_medalRows[i].print();
		}
	}

private:
	MedalRow m_medalRows[MedalsTable::maxSize];
	int m_size;

	int findCountry(const char* country) const
	{
		for (int i{ 0 }; i < m_size; ++i)
		{
			if (strcmp(m_medalRows[i].getCountry(), country) == 0)
			{
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	MedalsTable mt1;
	std::cout << "Medals table #1:\n";

	mt1["RUS"][MedalRow::GOLD] = 14;
	mt1["RUS"][MedalRow::SILVER] = 5;
	mt1["HUN"][MedalRow::BRONZE] = 9;
	mt1["HUN"][MedalRow::GOLD] = 7;
	mt1["POL"][MedalRow::GOLD] = 4;
	mt1["POL"][MedalRow::SILVER] = 2;

	mt1.print();

	// создаем константную копию таблицы №1
	std::cout << "\nMedals table #2:\n";

	const MedalsTable mt2{ mt1 };

	mt2.print();
	// раскомментировав следующую строку можно протестировать
	// проверку отсутствия страны в константной таблице медалей
	// программа аварийно завершиться, что нормально!
	// mt2["SLO"].print();
	return 0;
}