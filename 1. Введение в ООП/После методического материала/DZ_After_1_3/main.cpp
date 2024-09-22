#include <string>
#include <iostream>

#include <fstream>

#include "Group.h"

void LoadFromFile(std::string const& fileName, Group& group)
{
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cerr << "Файл не открыт" << std::endl;
		return;
	}

	//Чтение предметов

	size_t numSubject;
	file >> numSubject;

	for (size_t i = 0; i < numSubject; ++i)
	{
		std::string subjectName;
		file >> subjectName;
		Subject subject(subjectName);
		group.AddSubject(subject);
	}

	//Чтение студентов

	size_t numStudents;
	file >> numStudents;
	for (size_t i = 0; i < numStudents; ++i)
	{
		std::string studentName;
		file >> studentName;
		Student student(studentName);
		
		for (const auto& subject : group.GetSubjects())
		{
			size_t numGrades;
			file >> numGrades;

			for (size_t j = 0; j < numGrades; j++)
			{
				size_t grade;
				file >> grade;
				student.SetGrade(subject.GetSubjectName(), grade);
			}
		}
		group.AddStudent(student);
	}

	file.close();
}

int main()
{
	std::string groupName;
	std::cout << "Введите название группы: ";
	std::cin >> groupName;

	Group group(groupName);

	std::string fileName;
	std::cout << "Введите имя файла с данными: ";
	std::cin >> fileName;

	LoadFromFile(fileName, group);

	group.PrintGradesTable();
	group.PrintStudentAverage();
	group.PrintSubjectAverage();
	group.PrintGroupAverage();
	group.PrintMinMaxGrades();
}