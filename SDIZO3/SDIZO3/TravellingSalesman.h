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
	TravellingSalesman();
	~TravellingSalesman();

	void readFromFile();
	void printNL();
	void greedy();
	void showResultG();
	void showResult();
	void bruteForce(int k);
	void showResultB();
	void bruteForce();
};

