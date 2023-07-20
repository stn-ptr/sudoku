#ifndef BOARD_H_
#define BOARD_H_

#include <istream>
#include <cmath>
#include "Range.h"
#include "Field.h"

namespace Sudoku {


typedef Range ROW;
typedef Range COLUMN;
typedef Range BLOCK;

class Board {
	int s;	// board size
	int n;	// block size
	int m;	// number of fields

	Field	*fields;
	ROW		**rows;
	COLUMN	**columns;
	BLOCK	**blocks;

	Field 	**getField(int, int);
	ROW		*getRow(int);
	COLUMN	*getColumn(int);
	BLOCK	*getBlock(int, int);

	int getRowIdx(int);
	int getColumnIdx(int);
	int getBlockIdx(int);

	int guess_brute(int);
	int guess_smart(int);

	friend class BoardTest;

public:
	Board(void);	//creates an empty board of default size;
	Board(std::istream &);
	virtual ~Board();

	int getSize(void);
	int getFieldValue(int);
	int getFieldValue(int, int);

	void load(std::istream &);
	void solve(void);
};

} /* namespace Sudoku */
#endif /* BOARD_H_ */
