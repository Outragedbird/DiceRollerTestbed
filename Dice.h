#ifndef DICE_H
#define DICE_H
#include <iostream>
#include <random>			//used for linear_congruential_engine for random die rolls
#include <chrono>			//used for grabing system time as seed for linear_congruential_engine
#include <vector>			//for sorting individual die results 

//#include <time.h>

struct Die
{
	Die(int n, bool die3, bool die6);
	~Die();

	//setting
	void setN(int n) { nD = n; }
	void setd3(bool die3) { d3 = die3; }
	void setd6(bool die6) { d6 = die6; }

	//data members
	int nD{};			//number of die for that roll i.e. 2d6 or 3d3
	bool d3{};
	bool d6{};
	
	//functions
	void roll(Die d);					//uses <chrono> to seed random number generator, params set by Die (2d6, 4d3, etc)
	Die& retrieve() { return *this; }	//returns die being called 
	void display(Die d);				//displays Die values, simple viewing function
	float averageScores(Die d, int cutoff);	//takes die, and integer for what values are counted, i.e, 10d6, hits on 5+, thus only rolls of 5 are taken
};



#endif // !DICE_H

