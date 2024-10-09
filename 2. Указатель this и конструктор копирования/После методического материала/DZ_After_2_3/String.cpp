#include "String.h"

String::String(const char* str)
{
	m_size = std::strlen(str);
	m_string = new char[m_size + 1];
	strcpy_s(m_string, m_size + 1, str);
}

String::String(size_t size)
	: m_size{ size }
{
	m_string = new char[m_size + 1];
	m_string[0] = '\0';
}

String::String(const String& other)
{
	m_size = other.m_size;
	m_string = new char[m_size + 1];
	strcpy_s(m_string, m_size + 1, other.m_string);
}

void String::Display() const
{
	std::cout << m_string << std::endl;
}

void String::SetString(const char* str)
{
	size_t newSize = strlen(str);

	if (newSize >= m_size)
	{
		delete[] m_string;
		m_size = newSize;
		m_string = new char[m_size + 1];
	}

	strcpy_s(m_string, m_size, str);
}

size_t String::GetSize() const
{
	return m_size;
}

String::~String()
{
	delete[] m_string;
}
