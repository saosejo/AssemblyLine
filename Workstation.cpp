
//Name: Santiago Osejo
//ID: 134962208
//Email: sosejo-zuluaga@myseneca.ca
//Date: 16/10/2021
//section NHH
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS



#include "Workstation.h"

using namespace std;



namespace sdds {

	deque <CustomerOrder> pending{};
	deque <CustomerOrder> completed{};
	deque <CustomerOrder> incomplete{};
	
	Workstation::Workstation(){
		m_pnextstation = nullptr;
	}

	Workstation::Workstation(const std::string str):Station(str){
		m_pnextstation = nullptr;
	}

	void Workstation::fill(std::ostream& os){
		if (!m_orders.empty()){
			m_orders.front().fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder(){
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity()==0 ) {
				if (m_pnextstation != nullptr)
				{
					(*m_pnextstation) += std::move(m_orders.front());
					m_orders.pop_front();
					return true;
				}
				else
				{
					//if(getQuantity()!=0)
					if (m_orders.front().isFilled())
					{
						completed.push_back(std::move(m_orders.front()));
						m_orders.pop_front();
					}
					else
					{

						incomplete.push_back(std::move(m_orders.front()));
						m_orders.pop_front();
						return true;
					}

				}
			}
		}
			
		return false;
	}
	void Workstation::setNextStation(Workstation* station){
		if (station)
		{
			m_pnextstation = station;
		}
		else
		{
			m_pnextstation = nullptr;
		}
	}
	Workstation* Workstation::getNextStation() const{
		return m_pnextstation;
	}
	void Workstation::display(std::ostream& os) const{
		if (m_pnextstation==nullptr){
			os << getItemName() << " --> End of Line" << endl;
		}
		else{
			os << getItemName() << " --> " << m_pnextstation->getItemName() << endl;
		}
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder){
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
	int Workstation::getId2() const
	{
		return this->getId();
	}
}
