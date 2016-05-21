// SDIZO3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Data.h"
#include "TravellingSalesman.h"
#include "Knapsack.h"


int main()
{
	Data d;
	//d.generateFileTS();
	d.generateFileK();
	/*TravellingSalesman ts;

	ts.printNL();
	ts.greedy();
	ts.showResultG();
	ts.bruteForce(0);
	ts.showResultB();
*/
	Knapsack k;
	k.dynamic();
	k.showResultTAB();
	k.showResult();

    return 0;
}

