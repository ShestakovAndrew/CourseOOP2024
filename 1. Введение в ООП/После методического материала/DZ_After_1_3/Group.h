#pragma once
#include <string>
#include <vector>

#include "Student.h"

class Group
{
private:
	std::string m_groupName;
	std::vector<Student> m_students;
	std::vector<Subject> m_subjects;

public:
	Group(std::string const& groupName);

	void AddSubject(Subject const& subjectName);

	void AddStudent(Student const& student);

	std::vector<Subject> GetSubjects() const;

	void PrintGradesTable() const;

	void PrintStudentAverage() const;

	void PrintSubjectAverage() const;

	void PrintGroupAverage() const;

	void PrintMinMaxGrades() const;
};

