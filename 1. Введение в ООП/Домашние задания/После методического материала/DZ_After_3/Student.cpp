#include "Student.h"

Student::Student(std::string const& name)
	: m_name { name }
{
}

double Student::SetAvarageGrade() const
{
	return 0.0;
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
