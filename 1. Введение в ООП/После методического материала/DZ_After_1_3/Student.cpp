#include "Student.h"

Student::Student(std::string const& name)
	: m_name { name }
{
}

void Student::SetGrade(std::string const& subject, int grade)
{
	m_grades[subject].push_back(grade);
}

double Student::GetAvarageGrade() const
{
	double sum{ 0 }, count{ 0 };

	for (auto const& subjectGrade: m_grades)
	{
		for (int grade: subjectGrade.second)
		{
			sum += grade;
			count++;
		}
	}

	return count ? (sum / count) : 0.0;
}

double Student::GetAvarageGradeBySubject(Subject const& subject) const
{
	double sum{ 0 }, count{ 0 };

	for (int grade : m_grades.at(subject.GetSubjectName()))
	{
		sum += grade;
		count++;
	}

	return count ? (sum / count) : 0.0;
}

std::string Student::GetStudentName() const
{
	return m_name;
}

Student::Grades Student::GetStudentGrades() const
{
	return m_grades;
}
