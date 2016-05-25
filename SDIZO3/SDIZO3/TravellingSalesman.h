#pragma once
class TravellingSalesman
{
	int towns;

	vector <vector <int> > neighborsTS;
	vector <int> listVisited;
	vector <int>  tmp;
	vector <int> forPermutation;
	vector <int> memBestWay;
	int totalCostG,startTop, memBestSUMCost;

public:
	TravellingSalesman(string a);
	~TravellingSalesman();

	void readFromFile(string a);

	void printNL();
	void greedy();
	void showResultG();
	void bruteForce(int k);
	void showResultB();
};

