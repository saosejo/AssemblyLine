

//Name: Santiago Osejo
//ID: 134962208
//Email: sosejo-zuluaga@myseneca.ca
//Date: 16/10/2021
//section NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS


#include "LineManager.h"


using namespace std;

namespace sdds {
	LineManager::LineManager()
	{
		m_cntCustomerOrder = 0;
		m_firstStation = nullptr;
	}
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations){
		m_cntCustomerOrder = pending.size();
		m_firstStation = nullptr;
		ifstream inFile(file);
		if (!inFile.is_open())
		{
			string error = "ERROR: Failed to open file [" + file + "].";
		}
		while (inFile){
			
			size_t next = 0;
			string temp;
			bool more = true;
			getline(inFile, temp);
			Utilities util;
			if (temp!="")
			{
				string current = util.extractToken(temp, next, more);
				string nextSt = more ? util.extractToken(temp, next, more) : "";

				std::for_each(stations.begin(), stations.end(), [&](Workstation* station) {
					
					if (station->getItemName() == current) {
						
						std::for_each(stations.begin(), stations.end(), [&](Workstation* nextStation) {
							if (nextStation->getItemName() == nextSt) {
								station->setNextStation(nextStation);
							}
						});
						activeLine.push_back(station);
					}
				});
				if (m_firstStation == nullptr) {
					m_firstStation = activeLine.front();
				}
			}
			
		}
		inFile.close();
	}
	void LineManager::linkStations() {
		vector<Workstation*> sorted;
		sorted.push_back(m_firstStation);
		for_each(activeLine.begin(), activeLine.end(), [&](Workstation* now) {
			for_each(activeLine.begin(), activeLine.end(), [&](Workstation* next) {
				if (sorted.back()->getNextStation() && sorted.back()->getNextStation()->getItemName()==next->getItemName()){
					sorted.push_back(next);
				}
			});
		});
		activeLine = sorted;
	}
	bool LineManager::run(std::ostream& os){
		static size_t count = 0;
		count++;
		
		os << "Line Manager Iteration: " << count << endl;
		if (!pending.empty()){

			(*m_firstStation) += move(pending.front());
			pending.pop_front();
		}
		std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* wSt) {
			wSt->fill(os);
		});
		std::for_each(activeLine.begin(), activeLine.end(), [&](Workstation* wSt) {
			wSt->attemptToMoveOrder();
		});
		if (completed.size()+incomplete.size()==m_cntCustomerOrder)
		{
			return true;
		}
		return false;
	}
	void LineManager::display(std::ostream& os) const
	{
		std::for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* ws) { ws->display(os); });
	}
}