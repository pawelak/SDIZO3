

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

	void generateFileTS(int miast);

	void generateFileK(int it, int c);

	void generateFileTS(string a, int miast);

	void generateFileK(string a, int i, int c);

	void generateFileTS(string a);

	void generateFileK(string a, int i);

	void generateFileTS();
	void generateFileK(string a);
	void generateFileK();
	
	
};

