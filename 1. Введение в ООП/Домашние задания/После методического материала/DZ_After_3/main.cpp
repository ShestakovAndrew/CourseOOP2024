#include <string>
#include <iostream>

#include "Group.h"

void LoadFromFile(std::string const& fileName, Group& group)
{

}

int main()
{
	std::string groupName;
	std::cout << "������� �������� ������: ";
	std::cin >> groupName;

	Group group(groupName);

	std::string fileName;
	std::cout << "������� ��� ����� � �������: ";
	std::cin >> fileName;

	LoadFromFile(fileName, group);

	group.PrintGradesTable();
	group.PrintStudentAverage();
	group.PrintSubjectAverage();
	group.PrintGroupAverage();
	group.PrintMinMaxGrades();
}