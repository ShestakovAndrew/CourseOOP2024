#include "Subject.h"

Subject::Subject(std::string const& name)
	: m_name{name}
{
}

std::string Subject::GetSubjectName() const
{
	return m_name;
}
