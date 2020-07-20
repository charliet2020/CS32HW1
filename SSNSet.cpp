#include "Set.h"
#include "SSNSet.h"
#include <iostream>
using namespace std;

SSNSet::SSNSet()
{
	//m_count = 0;
}

bool SSNSet::add(unsigned long ssn)
{
	//if (ssn < 0)
		//return false; //new case
	return m_ssnset.insert(ssn);
}

int SSNSet::size() const
{
	return m_ssnset.size();
}

void SSNSet::print() const
{
	int i;
	unsigned long t;
	for (i = 0; i < m_ssnset.size(); i++)
	{
		m_ssnset.get(i, t);
		cout << t << endl;
	}
}