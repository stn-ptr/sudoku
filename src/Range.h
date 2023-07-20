#ifndef RANGE_H_
#define RANGE_H_

#include "Field.h"

namespace Sudoku {

class Range {
	int s;		// size: number of fields
	Field **f;	// pointers to fields in this range

	int countValue(int);

public:
	Range();
	virtual ~Range();

	void setFieldPtr(int, Field*);
	Field* getFieldPtr(int);

	bool verify(void);
};

} /* namespace sudoku */
#endif /* RANGE_H_ */
