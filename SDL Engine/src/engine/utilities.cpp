#include "utilities.h"

int Utilities::randAboveNum(int startNum) {

	srand((unsigned)time(NULL)); //srand(unsigned(time(NULL)));

	int rng = 0;

	do {

		rng = rand();

	} while (rng < startNum);

	return rng;

}

int Utilities::randAboveNum(int startNum, int notMore) {

	srand((unsigned)time(NULL)); //srand(unsigned(time(NULL)));

	int rng = 0;

	do {

		rng = rand() % notMore;

	} while (rng < startNum);

	return rng;

}