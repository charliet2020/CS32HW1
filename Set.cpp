#include "Set.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

Set::Set()
{
	m_elements = 0;
	
}

bool Set::empty() const
{
	if (m_elements != 0)
		return false;
	
	return true;
	//return (m_elements == 0);
}

int Set::size() const
{ 
	return m_elements;
}

bool Set::insert(const ItemType& value)
{
	if (m_elements == DEFAULT_MAX_ITEMS)
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

void Set::swap(Set& other)
{
	int temp_elements;
	ItemType temp;

	int border = other.m_elements;

	if (m_elements > other.m_elements)
		border = m_elements;

	for (int i = 0; i < border; i++)
	{
		temp = other.m_set[i];
		other.m_set[i] = m_set[i];
		m_set[i] = temp;
	}

	temp_elements = m_elements;
	m_elements = other.m_elements;
	other.m_elements = temp_elements;
}
