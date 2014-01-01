/*
 * sudoku.cpp
 *
 *  Created on: 22.10.2013
 *      Author: Sebastian
 */

#include <iostream>
#include <fstream>
#include <ctime>

#include "Board.h"

void printBoard(Sudoku::Board &b){
	int boardSize = b.getSize();
	for (int r = 0; r < boardSize; r++){
		for (int c = 0; c < boardSize; c++)
			std::cout << b.getFieldValue(r,c);
		std::cout << std::endl;
	}
}

int main(int argc, char* argv[]){

	Sudoku::Board sudoku;

	if (argc > 1){
		std::ifstream ifs(argv[1]);
		sudoku.load(ifs);
		}
	else
		sudoku.load(std::cin);

	std::cout << "Challenge:" << std::endl;
	printBoard(sudoku);
	std::cout << std::endl << std::endl;

	clock_t ticks = clock();

	sudoku.solve();

	ticks = clock() - ticks;

	std::cout << "Solution:" << std::endl;
	printBoard(sudoku);
	std::cout << "Duration: " << ((double) ticks) / CLOCKS_PER_SEC << "s (" << ticks << " ticks)" << std::endl;
	return 0;
}
