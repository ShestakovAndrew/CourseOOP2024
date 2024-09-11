#pragma once
#include <map>
#include <string>
#include <vector>

class Student
{
public:
	Student(std::string const& name);

	double SetAvarageGrade() const;

	double GetAvarageGrade() const;

private:
	std::string m_name;
	std::map<std::string, std::vector<int>> m_grades;
};

