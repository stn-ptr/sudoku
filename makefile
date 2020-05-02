all: sudoku

sudoku: src/sudoku.cpp src/Board.h src/Board.cpp src/Range.h src/Range.cpp src/Field.h
	g++ src/sudoku.cpp src/Board.h src/Board.cpp src/Range.h src/Range.cpp src/Field.h -o sudoku

clean:
	rm -f sudoku
