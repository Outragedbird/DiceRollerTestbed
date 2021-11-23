#include <iostream>
#include <string>
#include <random>
#include <stdlib.h>
#include <time.h>
#include "Dice.h"

int main()
{

	Die die1(10, true, false);
	die1.retrieve();
	die1.display(die1);
	die1.roll(die1);
	die1.averageScores(die1,2);
	
	Die die2(60, false, true);

	die2.retrieve();
	die2.display(die2);
	die2.roll(die2);
	die2.averageScores(die2, 5);

	Die dieBroke(69, true, true);
	dieBroke.retrieve();
	dieBroke.display(dieBroke);
	dieBroke.roll(dieBroke);
	dieBroke.averageScores(dieBroke, 1);
}

