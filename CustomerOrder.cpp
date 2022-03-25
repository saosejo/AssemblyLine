

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
#include <vector>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"

using namespace std;

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;



	CustomerOrder::CustomerOrder()
	{
		m_cntItem = 0;
		m_lstItem = nullptr;
	}

	sdds::CustomerOrder::CustomerOrder(const std::string& str)
	{
		string temp = str;
		Utilities* util = new Utilities;
		vector<Item*> items;
		size_t next_pos = 0;
		bool more = true;
		if (temp.empty()) {
			m_name = "";
			m_product = "";
			m_cntItem = 0;
			m_lstItem = nullptr;
		}
		else{
			m_name = util->extractToken(temp, next_pos, more);
			m_product = util->extractToken(temp, next_pos, more);
			m_cntItem = std::count(temp.begin(), temp.end(), util->getDelimiter())-1;
			m_lstItem = new Item * [m_cntItem];
			for (size_t i = 0; i < m_cntItem; i++)
			{
				m_lstItem[i] = new Item(util->extractToken(temp, next_pos, more));
			}
			m_widthField = util->getFieldWidth() > m_widthField ? util->getFieldWidth() : m_widthField;
		}
		
	
		delete util;

	}

	CustomerOrder::CustomerOrder(const CustomerOrder& customerOrder)
	{
		throw "ERROR: Copy is not allowed";
	}
	
	sdds::CustomerOrder::CustomerOrder(CustomerOrder&& customerOrder) noexcept
	{
		m_cntItem = 0;
		m_lstItem = nullptr;
		*this = move(customerOrder);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& customerOrder) noexcept
	{
		if (this != &customerOrder)
		{
			m_name = customerOrder.m_name;
			m_product = customerOrder.m_product;

			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;

			m_cntItem = customerOrder.m_cntItem;
			m_lstItem = customerOrder.m_lstItem;
			customerOrder.m_name = "";
			customerOrder.m_product = "";
			customerOrder.m_cntItem = 0;

			customerOrder.m_lstItem = nullptr;
		}
		return *this;
	}

	sdds::CustomerOrder::~CustomerOrder()
	{
		
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}

	bool sdds::CustomerOrder::isFilled() const
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{

			if (m_lstItem[i]->m_isFilled==false) { return false; };
		}
		return true;
	}

	bool sdds::CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		

		for (size_t i = 0; i < m_cntItem; i++)
		{

			if (m_lstItem[i]->m_itemName == itemName) { return m_lstItem[i]->m_isFilled; };
		}
		return true;
	}

	void sdds::CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName==station.getItemName())
			{
				if (station.getQuantity()>0)
				{
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				
			}
		} 
	}

	void sdds::CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] " << left << setw(m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled){
				os << "FILLED" << endl;
			}
			else {
				os << "TO BE FILLED" << endl;
			}
		}
	}
}