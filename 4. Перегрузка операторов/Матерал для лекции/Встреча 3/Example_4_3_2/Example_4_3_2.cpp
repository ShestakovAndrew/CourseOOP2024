#include <iostream>
#include <cassert>

class MedalRow
{
	char m_country[4];
	int m_medals[3];
public:

	/* определяем константы для удобного и однозначного
	доступа к элементам массива */
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
int main()
{
	MedalRow mr;
	mr.setCountry("RUS");
	std::cout << "Country is: " << mr.getCountry() << '\n';

	mr[MedalRow::GOLD] = 3;
	mr[MedalRow::BRONZE] = 2;
	mr[MedalRow::SILVER] = 4;

	/* Создаем строку-копию, на основе mr */
	MedalRow mr1{ mr };

	/* Убеждаемся, что создалась копия */
	mr1.print();

	/* Модифицируем значения строки-копии, выводим ее
	на экран*/
	mr1[MedalRow::GOLD] = 11;
	mr1[MedalRow::BRONZE] = 22;
	mr1[MedalRow::SILVER] = 33;
	mr1.print();

	/* Убеждаемся, что оригинал остался не модифицированным */
	mr.print();

	return 0;
}