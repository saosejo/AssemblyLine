//Name: Santiago Osejo
//ID: 134962208
//Email: sosejo-zuluaga@myseneca.ca
//Date: 16/10/2021
//section NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_STATION
#define SDDS_STATION
#include <iostream>

namespace sdds {

	class Station {
		int id;
		std::string stationName;
		std::string stationDesc;
		unsigned int serial;
		unsigned int numItems;
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station();
		Station(std::string file);
		const std::string& getItemName() const;
		int getId() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};


};

#endif
