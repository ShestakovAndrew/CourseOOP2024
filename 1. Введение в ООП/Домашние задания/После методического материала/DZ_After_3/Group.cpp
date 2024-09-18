#include <iostream>
#include <iomanip>

#include "Group.h"

Group::Group(std::string const& groupName)
	: m_groupName{groupName}
{
}

void Group::PrintGradesTable() const
{
	std::cout << "������� ������ ���������:" << std::endl;
	std::cout << std::setw(10) << "�������";

	for (const auto& subject : m_subjects)
	{
		std::cout << std::setw(10) << subject.GetSubjectName();
	}
	std::cout << std::endl;

	for (const auto& student : m_students)
	{
		std::cout << std::setw(10) << student.GetStudentName();
		for (const auto& subject : m_subjects)
		{
			if (student.GetStudentGrades().count(subject.GetSubjectName()))
			{
				std::cout << std::setw(10) << student.GetAvarageGradeBySubject(subject);
			}
			else
			{
				std::cout << std::setw(10) << "N/A";
			}
		}
		std::cout << std::endl;
	}
}

void Group::PrintStudentAverage() const
{
	std::cout << "������� ������ ���������: " << std::endl;
	for (const auto& student : m_students)
	{
		std::cout << student.GetStudentName() << ": " << student.GetAvarageGrade();
	}
}

void Group::PrintSubjectAverage() const
{
	std::cout << "������� ������ �� ���������: " << std::endl;

	for (const auto& subject : m_subjects)
	{
		double sum{ 0 }, count{ 0 };

		for (const auto& student : m_students)
		{
			if (student.GetStudentGrades().count(subject.GetSubjectName()))
			{
				sum += student.GetAvarageGradeBySubject(subject);
				count++;
			}
		}
		std::cout << subject.GetSubjectName() << ": " << (count ? sum / count : 0.0) << std::endl;
	}
}

void Group::PrintGroupAverage() const
{
	double sum{ 0 }, count{ 0 };

	for (const auto& student : m_students)
	{
		sum += student.GetAvarageGrade();
		count++;
	}
	std::cout << "������� ���� ������: " << (count ? (sum / count) : 0.0) << std::endl;
}

void Group::PrintMinMaxGrades() const
{
	std::cout << "����������� � ������������ ������ �� ���������: " << std::endl;

	for (const auto& subject : m_subjects)
	{
		int minGrade = std::numeric_limits<int>::max();
		int maxGrade = std::numeric_limits<int>::min();

		std::string minStudent, maxStudent;

		for (const auto& student : m_students)
		{
			if (student.GetStudentGrades().count(subject.GetSubjectName()))
			{
				for (int grade : student.GetStudentGrades().at(subject.GetSubjectName()))
				{
					if (grade < minGrade)
					{
						minGrade = grade;
						minStudent = student.GetStudentName();
					}

					if (grade > maxGrade)
					{
						maxGrade = grade;
						maxStudent = student.GetStudentName();
					}
				}
			}
		}

		std::cout << subject.GetSubjectName() << std::endl;
		std::cout << "�������: " << minGrade << " (�������: " << minStudent << ")" << std::endl;
		std::cout << "��������: " << maxGrade << " (�������: " << maxStudent << ")" << std::endl;
	}
}
