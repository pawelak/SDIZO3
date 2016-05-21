#pragma once
class TravellingSalesman
{
	int towns;

	vector <vector <int> > neighborsTS;
	vector <int> listVisited;
	vector <int>  tmp;
	int totalCostG,startTop;

public:
	TravellingSalesman();
	~TravellingSalesman();

	void readFromFile();
	void printNL();
	void greedy();
	void showResult();
};

