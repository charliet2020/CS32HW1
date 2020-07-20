

#include "newSet.h"
#include <iostream>
#include <cstdlib>
using namespace std;


Set::Set()
	: m_capacity(DEFAULT_MAX_ITEMS)
{
	m_set = new ItemType[DEFAULT_MAX_ITEMS];
	m_elements = 0;
	//m_elements = DEFAULT_MAX_ITEMS;
}

Set::Set(int n)
{
	if (n < 0)
	{
		std::cout << "input number must be at least some nonnegative value" << std::endl;
		std::exit(1);
	}
	m_elements = 0;
	m_set = new ItemType[n];
}

Set::~Set()
{
	delete [] m_set;

}

Set::Set(const Set& set) //copy constructor
{
	m_elements = set.m_elements;
	m_capacity = set.m_capacity;
	m_set = new ItemType[m_capacity];

	//we only care about number of valid elements, not necessarily all of capacity
	for (int i = 0; i < m_elements; i++)
		m_set[i] = set.m_set[i];
}

Set &Set::operator= (const Set& set) //assignment operator
{
	if (&set == this)
		return *this;
	delete [] m_set;
	m_elements = set.m_elements;
	m_capacity = set.m_capacity;
	m_set = new ItemType[m_capacity];
	for (int i = 0; i < m_elements; i++)
		m_set[i] = set.m_set[i];

	return *this;
}

bool Set::empty() const
{
	return (m_elements == 0);
}

int Set::size() const
{
	return m_elements;
}

bool Set::insert(const ItemType& value)
{
	if (m_elements == m_capacity)
		return false;

	for (int i = 0; i < m_elements; i++)
		if (value == m_set[i])
			return false;

	m_set[m_elements] = value;
	m_elements++;

	return true;
}

bool Set::erase(const ItemType& value)
{
	for (int i = 0; i < m_elements; i++)
		if (value == m_set[i])
		{
			for (int j = i; j + 1 < m_elements; j++)
				m_set[j] = m_set[j + 1];
			m_elements--;
			return true;
		}
	return false;
}

bool Set::contains(const ItemType& value) const
{
	for (int i = 0; i < m_elements; i++)
		if (value == m_set[i])
			return true;

	return false;
}

bool Set::get(int i, ItemType& value) const
{
	if (i >= 0 && i < size())
	{
		int counter = 0;
		for (int j = 0; j < m_elements; j++)
		{
			for (int k = 0; k < m_elements; k++)
			{
				if (m_set[j] > m_set[k])
					counter++;
			}
			if (counter == i)
			{
				value = m_set[j];
				return true;
			}
			else
				counter = 0;
		}
	}
	return false;
}

void Set::swap(Set& other) //let's just have the pointers point to different things
{
	ItemType* temp_p;
	int temp_cap;
	int temp_el;

	//swap pointers to objects
	temp_p = m_set;
	m_set = other.m_set;
	other.m_set = temp_p;

	//swap max capacity
	temp_cap = other.m_capacity;
	other.m_capacity = m_capacity;
	m_capacity = temp_cap;

	//swap sizes
	temp_el = m_elements;
	m_elements = other.m_elements;
	other.m_elements = temp_el;
}

