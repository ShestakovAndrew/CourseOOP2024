#include <string>
#include <iostream>


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

	group.printGradesTable();
	group.printStudentAverage();
	group.printSubjectAverage();
	group.printGroupAvarage();
	group.printMinMaxGrades();
}