/*
 * Range.h
 *
 *  Created on: 22.10.2013
 *      Author: Sebastian
 */

#ifndef RANGE_H_
#define RANGE_H_

namespace Sudoku {
typedef int FIELD;

class Range {
	int s;		// size: number of fields
	int **f;	// pointers to fields in this range

	int countValue(int);

public:
	Range();
	virtual ~Range();

	void setFieldPtr(int, int*);
	int* getFieldPtr(int);

	bool verify(void);
};

} /* namespace sudoku */
#endif /* RANGE_H_ */
