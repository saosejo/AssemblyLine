//Name: Santiago Osejo
//ID: 134962208
//Email: sosejo-zuluaga@myseneca.ca
//Date: 16/10/2021
//section NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_UTILITIES
#define SDDS_UTILITIES
#include <iostream>

namespace sdds {

	class Utilities {
		size_t m_widthField = 0;
		static char m_delimiter;
	public:
		Utilities() {};
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
};

#endif
