#pragma once
#include <string>

class Subject
{
public:
	Subject(std::string const& name);

	std::string GetSubjectName() const;

private:
	std::string m_name;
};

