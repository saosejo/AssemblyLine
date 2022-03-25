//Name: Santiago Osejo
//ID: 134962208
//Email: sosejo-zuluaga@myseneca.ca
//Date: 16/10/2021
//section NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LINEMANAGER
#define SDDS_LINEMANAGER
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <numeric>

#include "CustomerOrder.h"
#include "Workstation.h"
#include "Utilities.h"
#include "Station.h"

using namespace sdds;

namespace sdds {

	class LineManager {
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;

	public:
		LineManager();
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void linkStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};

}
#endif