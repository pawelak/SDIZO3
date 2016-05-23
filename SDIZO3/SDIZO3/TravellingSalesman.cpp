#include "stdafx.h"
#include "TravellingSalesman.h"


TravellingSalesman::TravellingSalesman()
{
	readFromFile();
	startTop = 0;
	memBestSUMCost = 2147483647;
	for (int i = 0; i < towns; i++)
	{
		forPermutation.push_back(0);
		memBestWay.push_back(0);
	}

}


TravellingSalesman::~TravellingSalesman()
{
}


void TravellingSalesman::readFromFile()			// czyta z pliku
{
	fstream file("plikTS.txt", ios::in);
	int help;
	if (file.is_open()) 
	{
		file >> towns;
		if (file.fail())
			cout << "blad wczytywania pliku" << endl;

		for (int i = 0; i < towns; i++) 
		{
			for (int j = 0; j < towns; j++) 
			{
				file >> help;
				tmp.push_back(help);
			}
			neighborsTS.push_back(tmp);
			tmp.clear();
		}
		file.close();
	}
	else
		cout << "blad wczytywania" << endl;
}


void TravellingSalesman::printNL()			//printuje macierz s¹siedztwa
{
	for (int i = 0; i < towns; i++) 
	{
		for (int j = 0; j < towns; j++) 
		{
			cout << neighborsTS[i][j] << " ";
		}
		cout << endl;
	}
}



void TravellingSalesman::greedy()		//algorytm zach³anny dla problemu komiwoja¿era
{
	int cost = 0;
	int currentT;
	int help;
	int nextT = startTop;
	totalCostG = 0;

	bool *visited = new bool[towns];
	for (int i = 0; i < towns; i++) 
		visited[i] = false;

	for (int i = 0; i < towns; i++) 
	{
		totalCostG += cost;
		cost = 2147483647;

		currentT = nextT;
		visited[currentT] = true;
		listVisited.push_back(currentT);
		for (int j = 0; j < towns; j++) 
		{
			if (neighborsTS[currentT][j] < cost)
			{
				help = j;
				if (visited[help] == true)
					continue;
				else
				{
					cost = neighborsTS[currentT][j];
					nextT = help;
				}
			}
		}
	}
	delete[] visited;
}


void TravellingSalesman::showResultG()		//printuje wyniki dla algorytmu zach³annego 
{
	cout << "koszt przejscia: " << totalCostG << endl;
	for (int i = 0; i < listVisited.size(); i++) 
		cout << listVisited[i] << endl;
	
}


void TravellingSalesman::bruteForce(int k)		//algorytm bruteforce (rekurencyjny)
{
	static int level = 0;
	level = level + 1;
	forPermutation[k] = level;
	if (level == towns)
	{
		int h=0;
		for (int i = 0; i < towns - 1; i++)
			h += neighborsTS[(forPermutation[i])-1][(forPermutation[i+1])-1];

		if (h<memBestSUMCost)
		{
			memBestSUMCost = h;
			for (int i = 0; i < towns; i++)
				memBestWay[i] = forPermutation[i]-1;
		}
	}
	else
		for (int i = 0; i < towns; i++)
			if (forPermutation[i] == 0)
				bruteForce(i);
	level = level - 1;
	forPermutation[k] = 0;
}

void TravellingSalesman::showResultB()			//pringje wyniki dla algorytmu zach³annego
{
	cout << "koszt przejscia przy uzyciu metody brutforce: " << memBestSUMCost << endl;
	for (int i = 0; i < memBestWay.size(); i++)
		cout << memBestWay[i] << endl;

}