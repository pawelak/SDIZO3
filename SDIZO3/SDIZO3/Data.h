

#pragma once
class Data
{
	vector <vector <int> > distance;
	vector <int> listOfVisitedTowns;
	int od, ile, towns;

	int capacity, items, weightMax, profitMax;


public:
	Data();
	~Data();

	void generateFileTS(int miast);

	void generateFileK(int it, int c);

	
	
};

