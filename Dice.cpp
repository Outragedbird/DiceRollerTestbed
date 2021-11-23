#include "Dice.h"



Die::Die(int n, bool die3, bool die6)
{
	setN(n);
	setd3(die3);
	setd6(die6);
}

Die::~Die()
{

}

void Die::roll(Die d)
{
	d.retrieve();
	if (d.d3 == true && d.d3 != d.d6)	//if d3
	{	
		std::vector<int> d3box;
		int roll = 0; 
		int result = 0;
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	//grab system time, count to epoch, plant as seed
		std::default_random_engine generator(seed);										//seed generator with above 
		std::uniform_int_distribution<int> distribution(1, 3);							//set uniform int distribution to be range 1 to 3
		for (int i = 0; i < d.nD; i++)		//for i less than number of die 
		{
			roll = distribution(generator);		//int from generator in range set by distribution
			distribution.reset();				//clear random numbers 
			result = roll + result;				//add roll to running total 
			d3box.push_back(roll);
			roll = 0;							//reset roll 
		}
		std::sort(d3box.begin(),d3box.end());		//sort bector into order 
		std::reverse(d3box.begin(), d3box.end());	//reverse order so read out largest first 
		for (std::vector<int>::iterator it = d3box.begin(); it != d3box.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << "|| From " << d.nD << "d3: " << result << std::endl;
	}

	if (d.d3 == false && d.d3 != d.d6)	//if d6
	{
		std::vector<int> d6box;
		int roll = 0;
		int result = 0;
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine generator(seed);
		std::uniform_int_distribution<int> distribution(1, 6);
		for (int i = 0; i < d.nD; i++)
		{
			roll = distribution(generator);
			distribution.reset();
			result = roll + result;
			d6box.push_back(roll);
			roll = 0;
		}

		std::sort(d6box.begin(), d6box.end());		
		std::reverse(d6box.begin(), d6box.end());	
		for (std::vector<int>::iterator it = d6box.begin(); it != d6box.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << "|| From " << d.nD << "d6: " << result << std::endl;
	}

	if (d.d3 == true && d.d6 == true)
	{
		std::cout << "Nope, stop it, can't have both a d3 AND a d6. That's just silly." << std::endl;
	}

}

void Die::display(Die d)
{
	d.retrieve();
	std::string dX = {NULL};

	if (d.d3 == true && d.d6 == false)
	{
		std::string dX = "d3";
		std::cout << d.nD << dX << std::endl;
	}
	if (d.d3 == false && d.d6 == true)
	{
		std::string dX = "d6";
		std::cout << d.nD << dX << std::endl;
	}
	if (d.d3 == false && d.d6 == false)
	{
		std::string dX = "";
		std::cout << d.nD << dX << std::endl;
	}
	if (d.d3 == true && d.d6 == true)
	{
		std::string dX = "ERROR: Cannot be both d3 & d6";
		std::cout << dX << std::endl;
	}
}

float Die::averageScores(Die d, int cutoff)
{
	d.retrieve();		//get die 
	if (d.d3 == true && d.d3 != d.d6)		//if d3
	{
		float d3chanch = ((cutoff - 1) / static_cast<float>(3));		//population of die vals that aren't sucessful 
		float prescore = d.nD * d3chanch;								//number of die multiplied by that fraction (MAKE SMALLER)
		float scores = d.nD - prescore;									//take these failed die away from the total number of die rolled 

		std::cout << "Average scores: "<< scores << " at " << cutoff << "+" << std::endl;
		std::cout << std::endl;
		return scores;

	}

	if (d.d3 == false && d.d3 != d.d6)
	{
		float d6chance = ((cutoff-1) / static_cast<float>(6));
		float prescore = d.nD * d6chance;
		float scores = d.nD - prescore;

		std::cout << "Average scores: " << scores << " at " << cutoff << "+" << std::endl;
		std::cout << std::endl;
		return scores;

	}

	if (d.d3 == true && d.d6 == true)
	{
		std::cout << "ERROR: cannot have both d3 & d6" << std::endl;
		std::cout << std::endl;
	}
}
