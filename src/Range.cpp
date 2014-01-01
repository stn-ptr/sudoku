/*
 * Range.cpp
 *
 *  Created on: 22.10.2013
 *      Author: Sebastian
 */

#include "Range.h"

namespace Sudoku {

Range::Range() {
	s = 9;
	f = new int*[s];
}

Range::~Range() {
	delete[] f;
}

void Range::setFieldPtr(int index, int* address){
	*(f+index) = address;
}

int *Range::getFieldPtr(int index){
	return *(f+index);
}

/**
 * Verifies the range
 * The range is valid if every possible value appears only once or not at all.
 * returns true, if the range is valid
 * returns false, if the range is not valid
 */
bool Range::verify(){
	bool res = true;
	for (int i = 1; i <= s; i++)
		res = res && (countValue(i) <= 1);

	return res;
}

/**
 * returns how many times the value appears in a range
 */
int Range::countValue(int value){
	int res = 0;
	for (int i = 0; i < s; i++)
		if (**(f+i) == value) res++;

	return res;
}

} /* namespace Sudoku */
