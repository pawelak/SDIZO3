#pragma once
class Knapsack
{
	vector <int> help;
	vector < vector <int> > itemsTab;
	vector < vector <int> > result;
	int capacity, items;

	vector <int> forPermutation;
	vector <vector<int>> memBestSet;
	int totalBenefits;


public:
	Knapsack();
	~Knapsack();
	void readFromFile();
	void dynamic();
	void showResultTAB();
	void showResultG();
	void showResult();
	void bruteForce(int k);
	void showResultB();
};

