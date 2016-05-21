

#pragma once
class Data
{
	vector <vector <int> > distance;
	//vector <int>  row;
	vector <int> listOfVisitedTowns;
	int od, ile, towns;

	int capacity, items, weightMax, profitMax;


public:
	Data();
	~Data();

	void generateFileTS();
	void generateFileK();
	
	
};

