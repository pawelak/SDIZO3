#include "stdafx.h"
#include "Knapsack.h"


Knapsack::Knapsack()
{
	readFromFile();
}


Knapsack::~Knapsack()
{
}

void Knapsack::readFromFile() 
{

	fstream file("plikK.txt", ios::in);
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

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < capacity + 1; j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
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


void Knapsack::showResult()
{
	vector < vector<int> > whichItems;
	//row.clear();


	int y = capacity;
	int x = items;
	int tmp;
	int localCapacity = capacity;
	while (true) {
		if (x >= 1) {
			if (result[x][y] != result[x - 1][y]) {
				tmp = itemsTab[x - 1][0];
				help.push_back(itemsTab[x - 1][0]);
				help.push_back(itemsTab[x - 1][1]);
				whichItems.push_back(help);
				help.clear();


				if (x == items && y == capacity)
					break;

				x--;

				if (x == 0 && y == 0)
					break;

			}
			else {
				x--;
				while (result[x][y] == result[x - 1][y])
					x--;

				x--;
				tmp = itemsTab[x - 1][0];
				y -= tmp;

				help.push_back(itemsTab[x][0]);
				help.push_back(itemsTab[x][1]);
				whichItems.push_back(help);
				help.clear();

			}
		}
		else
			break;
	}

	cout << endl;
	cout << "waga bydla to " << result[items][capacity] << endl;
	for (int i = 0; i < whichItems.size(); i++) {
		cout << whichItems[i][0] << " " << whichItems[i][1] << endl;
	}
}