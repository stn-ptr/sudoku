/*
 * Field.h
 *
 *  Created on: 30.05.2014
 *      Author: sebastian
 */

#ifndef FIELD_H_
#define FIELD_H_

namespace Sudoku {

struct Field {
	int value;
	int row;
	int column;
	int block;
};

} /* namespace Sudoku */

#endif /* FSIELD_H_ */
