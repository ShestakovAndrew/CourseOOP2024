#include <string>
#include <iostream>

#include "Group.h"

void LoadFromFile(std::string const& fileName, Group& group)
{

}

int main()
{
	std::string groupName;
	std::cout << "¬ведите название группы: ";
	std::cin >> groupName;

	Group group(groupName);

	std::string fileName;
	std::cout << "¬ведите им€ файла с данными: ";
	std::cin >> fileName;

	LoadFromFile(fileName, group);

	group.PrintGradesTable();
	group.PrintStudentAverage();
	group.PrintSubjectAverage();
	group.PrintGroupAverage();
	group.PrintMinMaxGrades();
}