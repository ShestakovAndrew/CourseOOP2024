#pragma once
#include <map>
#include <string>
#include <vector>

#include "Subject.h"

class Student
{
public:
	Student(std::string const& name);

	void SetGrade(std::string const& subject, int grade);

	double GetAvarageGrade() const;

	double GetAvarageGradeBySubject(Subject const& subject) const;

	std::string GetStudentName() const;

	using Grades = std::map<std::string, std::vector<int>>;

	Grades GetStudentGrades() const;

private:
	std::string m_name;
	Grades m_grades;
};

