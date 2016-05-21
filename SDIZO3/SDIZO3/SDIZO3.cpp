// SDIZO3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Data.h"
#include "TravellingSalesman.h"


int main()
{
	Data d;
	//d.generateFileTS();
	//d.generateFileK();
	TravellingSalesman ts;
	ts.readFromFile();
	ts.printNL();
	ts.greedy();
	ts.showResult();


    return 0;
}

