#include "Subject.h"

Subject::Subject(std::string const& name)
	: m_name{name}
{
}

std::string Subject::GetSubjectName()
{
	return m_name;
}
