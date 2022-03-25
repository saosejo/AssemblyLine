//Name: Santiago Osejo
//ID: 134962208
//Email: sosejo-zuluaga@myseneca.ca
//Date: 16/10/2021
//section NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_WORKSTATION
#define SDDS_WORKSTATION
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <deque>
#include "Utilities.h"
#include "Station.h"
#include "CustomerOrder.h"

using namespace std;

namespace sdds {


	extern deque <CustomerOrder> pending;
	extern deque <CustomerOrder> completed;
	extern deque <CustomerOrder> incomplete;

	class Workstation : public Station {
		deque <CustomerOrder> m_orders;
		Workstation* m_pnextstation;
	public:
		Workstation();
		//~Workstation();
		Workstation(const Workstation&)=delete;
		Workstation operator=(Workstation&)=delete;
		Workstation(const Workstation&&)=delete;
		Workstation operator=(Workstation&&)=delete;
		Workstation(const std::string str);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
		int getId2() const;
	};

}
#endif