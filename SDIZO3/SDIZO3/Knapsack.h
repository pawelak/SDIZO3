#pragma once
class Knapsack
{
	vector <int> help;
	vector < vector <int> > itemsTab;
	vector < vector <int> > result;

	int capacity, items;



public:
	Knapsack();
	~Knapsack();
	void readFromFile();
	void dynamic();
	void showResultTAB();
	void showResult();
};

