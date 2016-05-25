#include "stdafx.h"
#include "Data.h"


Data::Data()
{
	od = 1;
	ile = 9;
	towns = 5;
	weightMax = 6;
	profitMax = 6;
}

Data::~Data()
{
}

void Data::generateFileTS(int miast)		//dla komiwoja¿era
{
	towns = miast;
	srand(time(NULL));
	vector <vector < int> > tmp;

	for (int i = 0; i < towns; i++)			 //zape³nia zerami macierz
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

	fstream file("plikTS.txt", ios::out);			//u tu spisuje do pliku 
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
	cout << "wygenerowano plikTS.txt" << endl;
	tmp.clear();
}


	
void Data::generateFileK(int it, int c) 
{
	items = it;
	capacity = c;
	srand(time(NULL));
	int weight, profit;

	fstream file("plikK.txt", ios::out);
	file << capacity << " " << items << "\n";		
	if (file.good())
	{		
		for (int i = 0; i < items; i++)			//zwykle losowanie po 2
		{
			file << (rand() % weightMax + 1) << " " << (rand() % profitMax + 1) << "\n";
		}
		file.close();
	}
	cout << "wygenerowano plikK.txt" << endl;

}
	



