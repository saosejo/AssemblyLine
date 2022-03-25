
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
#include <vector>
#include "Utilities.h"
#include "Station.h"

using namespace std;

namespace sdds {

	size_t Station::id_generator = 0;

	size_t Station::m_widthField = 0;

	Station::Station(std::string inputFile)
	{
		try{
			string temp = inputFile;
			Utilities* utility = new Utilities;
			size_t next_pos = 0;
			bool more=true;
			id=++id_generator;
			stationName = utility->extractToken(temp, next_pos, more);
			serial = stoi(utility->extractToken(temp, next_pos, more));
			numItems = stoi(utility->extractToken(temp, next_pos, more));
			utility->setFieldWidth(stationName.length());
			if (utility->getFieldWidth() > m_widthField) { m_widthField = utility->getFieldWidth(); }
			stationDesc = utility->extractToken(temp, next_pos, more);
			delete utility;
		}
		catch (const std::exception&){
			
		}
	}
	Station::Station()
	{

	}
	const std::string& Station::getItemName() const{
		return this->stationName;
	}

	size_t Station::getNextSerialNumber(){
		return this->serial++;
	}
	int Station::getId() const{
		return this->id;
	}
	size_t Station::getQuantity() const{
		return this->numItems;
	}
	void Station::updateQuantity(){
		if (numItems > 0){
			--this->numItems;
		}
	}
	void Station::display(std::ostream& os, bool full) const{
		if (full==false){
			os << "[" << setfill('0') <<setw(3)<< right <<id << "] Item: " << setw(m_widthField)<<setfill(' ')<< left << stationName << " [" << setw(6) << setfill('0') << right << serial << "]"<<endl;
		}
		else{
			os << "[" << setfill('0') << setw(3) << right << id << "] Item: " << setw(m_widthField) << setfill(' ') << left << stationName << " [" << setw(6) << setfill('0') <<right << serial << "] Quantity: " << setw(m_widthField) << setfill(' ') << left << numItems << " Description: " << stationDesc << endl;
		}
	}
}
