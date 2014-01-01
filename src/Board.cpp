/*
 * Board.cpp
 *
 *  Created on: 22.10.2013
 *      Author: Sebastian
 */

#include "Board.h"

using namespace Sudoku;

namespace Sudoku {

Board::Board(void){
	s = 9;
	n = int(sqrt(double(s)));
	m = s * s;

	fields = new int[m];
	rows = new ROW*[s];
	columns = new COLUMN*[s];
	blocks = new BLOCK*[s];

	int i;
	for (i = 0; i < s; i++){
		rows[i] = getRow(i);
		columns[i] = getColumn(i);
	}

	i = 0;
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			blocks[i++] = getBlock(r,c);
}

Board::Board(std::istream &is) {
	s = 9;
	n = int(sqrt(double(s)));
	m = s * s;

	fields = new int[m];


	rows = new ROW*[s];
	columns = new COLUMN*[s];
	blocks = new BLOCK*[s];

	int i;
	for (i = 0; i < s; i++){
		rows[i] = getRow(i);
		columns[i] = getColumn(i);
	}

	i = 0;
	for (int r = 0; r < n; r++)
		for (int c = 0; c < n; c++)
			blocks[i++] = getBlock(r,c);

	load(is);
}

Board::~Board() {
	delete[] rows;
	delete[] columns;
	delete[] blocks;

	delete[] fields;
}

int Board::getSize(void){
	return s;
}

int Board::getFieldValue(int index){
	return fields[index];
}

int Board::getFieldValue(int row, int column){
	return fields[row * s + column];
}

void Board::load(std::istream &is){
	for (int i = 0; i < m; i++)
		is >> fields[i];
}

void Board::solve(){
	// selects solution algorithm and starts it
	guess_brute(0);
}

// From here: private members

int Board::guess_brute(int idx){
	// cancel condition
	if (idx >= m)
		return s + 1;

	if (fields[idx] == 0){
		int orgval = fields[idx];
		int guess = 1;

		do{
			fields[idx] = guess;
			if (rows[getRowIdx(idx)]->verify() && columns[getColumnIdx(idx)]->verify() && blocks[getBlockIdx(idx)]->verify() && guess_brute(idx + 1) > 0)
				return guess;
		} while (guess++ < s);

		fields[idx] = orgval;
		return 0;

	} else {
		if (guess_brute(idx + 1) > 0)
			return fields[idx];
		else
			return 0;
	}
}

ROW *Board::getRow(int index){
	ROW *res = new ROW[s];
	for(int i = 0; i < s; i++)
		res->setFieldPtr(i, fields+(index*s+i));
	return res;
}

int Board::getRowIdx(int fieldindex){
	return floor(fieldindex/s);
}

COLUMN *Board::getColumn(int index){
	COLUMN *res = new COLUMN[s];
	for (int i = 0; i < s; i++)
		res->setFieldPtr(i, fields+(i*s+index));
	return res;
}

BLOCK *Board::getBlock(int ridx, int cidx){
	BLOCK *res = new BLOCK[s];
	int i = 0;

	for(int r = 0; r < n; r++)
		for(int c = 0; c < n; c++)
			res->setFieldPtr(i++, fields+((ridx*n+r)*s + cidx*n+c));
	return res;
}

int Board::getColumnIdx(int fieldindex){
	return fieldindex % s;
}

int Board::getBlockIdx(int fieldindex){
	return (getColumnIdx(fieldindex) % n) + floor(getRowIdx(fieldindex) / n) * n;
}

} /* namespace Sudoku */
