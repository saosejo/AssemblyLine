
//Name: Santiago Osejo
//ID: 134962208
//Email: sosejo-zuluaga@myseneca.ca
//Date: 16/10/2021
//section NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Utilities.h"

using namespace std;

namespace sdds {
	char Utilities::m_delimiter{};

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
  		return this->m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		string temp = str.substr(next_pos);
		size_t pos = temp.find(m_delimiter);
		
		temp = temp.substr(0, pos);
		temp.length() > m_widthField ? setFieldWidth(temp.length()) : setFieldWidth(m_widthField);
		if (!temp.empty())
		{
			bool findS = str.find(m_delimiter, next_pos) != std::string::npos;
			if (findS)
			{	next_pos += pos + 1;
				more = true;
				return temp;
			}
			else
			{	more = false;
				return temp;
			}
		}
		else
		{
			more = false;
			throw ("Exception");
		}
		

		
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		
		m_delimiter=newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}
