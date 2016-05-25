#include "stdafx.h"
#include "Knapsack.h"


Knapsack::Knapsack(string a)
{
	
	readFromFile(a);
	for (int i = 0; i < items; i++)
	{
		forPermutation.push_back(0);
	}
}


Knapsack::~Knapsack()
{
}

void Knapsack::readFromFile(string a)
{


	fstream file(a, ios::in);
	int tmp, help2;

	if (file.is_open()) {
		file >> capacity;
		file >> items;

		if (file.fail())
			cout << "blad wczytywania pliku" << endl;

		for (int i = 0; i < items; i++)
		{
			file >> tmp;
			help.push_back(tmp);
			file >> tmp;
			help.push_back(tmp);
			itemsTab.push_back(help);
			help.clear();

		}
		help.clear();


		file.close();
	}
	else
		cout << "blad wczytywania pliku" << endl;
}

void Knapsack::dynamic() 
{
	help.clear();
	
	for (int i = 0; i < items +1; i++) 
	{
		result.push_back(vector<int>(capacity + 1, 0));
	}

	for (int i = 1; i < items + 1; i++) {

		for (int j = 0; j < capacity + 1; j++) 
		{
			if (itemsTab[i - 1][0] > j) 
			{
				result[i][j] = result[i - 1][j];
			}
			else 
			{
				if (result[i - 1][j] > result[i - 1][j - itemsTab[i - 1][0]] + itemsTab[i - 1][1])
					result[i][j] = result[i - 1][j];
				else
					result[i][j] = result[i - 1][j - itemsTab[i - 1][0]] + itemsTab[i - 1][1];
			}
		}
	}
	
}


void Knapsack::showResultTAB()
{
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < capacity + 1; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}


void Knapsack::showResultG()
{
	vector < vector<int> > whichItems;

	int w = capacity;
	int i = items;
	while (w>0 && i>0)
	{
		if (result[i][w] != result[i - 1][w])
		{
			help.clear();
			help.push_back(itemsTab[i-1][0]);
			help.push_back(itemsTab[i-1][1]);
			whichItems.push_back(help);
			w -= itemsTab[i-1][0];
			i--;
		}
		else
			i--;
	}
	

	cout << endl;
	cout << "waga bydla to " << result[items][capacity] << endl;
	for (int i = 0; i < whichItems.size(); i++) {
		cout << whichItems[i][0] << " " << whichItems[i][1] << endl;
	}
}


void Knapsack::bruteForce(int k)
{
	static int level = -1;
	level = level + 1;
	forPermutation[k] = level;

	if (level == items)
	{
		int h = 0;
		int b = 0;
		int i;
		for (i = 0; i < items; i++)
		{
			h += (itemsTab[forPermutation[i] - 1][0]);
			if (h < capacity)
			{
				b += itemsTab[forPermutation[i] - 1][1];
			}
			else
			{
				h -= itemsTab[forPermutation[i] - 1][0];
				break;
			}
		}
		if (b > totalBenefits)
		{

			totalBenefits = b;
			memBestSet.clear();
			help.clear();
			for (int j = 0; j < i; j++)
			{
				help.push_back(itemsTab[(forPermutation[j] - 1)][0]);
				help.push_back(itemsTab[(forPermutation[j] - 1)][1]);
				memBestSet.push_back(help);
				help.clear();

			}

		}
	}
	else 
	{
		for (int j = 0; j < forPermutation.size(); j++)
			if (forPermutation[j] == 0)
				bruteForce(j);
	}
		
	level = level - 1;
	forPermutation[k] = 0;
}



void Knapsack::showResultB()
{
	cout << "pomiesci sie: " << endl;
	for (int i = 0; i < memBestSet.size(); i++)
	{
		cout << memBestSet[i][0] << " " << memBestSet[i][1] << endl;
	}
}