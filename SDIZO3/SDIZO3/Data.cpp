#include "stdafx.h"
#include "Data.h"


Data::Data()
{
	od = 1;
	ile = 9;
	towns = 5;
	capacity = 10;
	items = 5;
	weightMax = 6;
	profitMax = 6;
}

Data::~Data()
{
}

void Data::generateFileTS()		//dla komiwojażera
{
	srand(time(NULL));
	vector <vector < int> > tmp;

	for (int i = 0; i < towns; i++)			 //zapełnia zerami macierz
	{			
		for (int j = i; j < towns; j++) 
		{
			tmp.push_back(vector<int>(towns, 0));
		}
	}

	for (int i = 0; i < towns; i++)			//losuje do macierzy
	{
		for (int j = 0; j < i; j++) 
		{	
			tmp[i][j] = rand() % ile + od;
			tmp[j][i] = tmp[i][j];
		}
	}

	fstream file("plikTS.txt", ios::out);
	if (file.good()) 
	{
		file << towns << "\n";
		for (int i = 0; i < towns; i++)
		{
			for (int j = 0; j < towns; j++) 
				file << tmp[i][j] << " ";
			file << "\n";
		}
		file.close();
	}

	tmp.clear();
}


	
void Data::generateFileK() 
{
	srand(time(NULL));
	int weight, profit;

	fstream file("plikK.txt", ios::out);
	file << capacity << "\n";
	if (file.good())
	{
		for (int i = 0; i < items; i++)
		{
			file << (rand() % weightMax + 1) << " " << (rand() % profitMax + 1) << "\n";

		}
		file.close();
	}

}
	



