#include <string>
#include <iostream>


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

	group.printGradesTable();
	group.printStudentAverage();
	group.printSubjectAverage();
	group.printGroupAvarage();
	group.printMinMaxGrades();
}