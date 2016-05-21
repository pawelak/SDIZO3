#include "stdafx.h"
#include "TravellingSalesman.h"


TravellingSalesman::TravellingSalesman()
{
	startTop = 0;
}


TravellingSalesman::~TravellingSalesman()
{
}


void TravellingSalesman::readFromFile() 
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


void TravellingSalesman::printNL() 
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



void TravellingSalesman::greedy() 
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


void TravellingSalesman::showResult() 
{
	cout << "koszt przejscia: " << totalCostG << endl;
	for (int i = 0; i < listVisited.size(); i++) 
		cout << listVisited[i] << endl;
	
}