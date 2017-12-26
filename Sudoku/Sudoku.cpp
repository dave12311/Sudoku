#include "Sudoku.h"
#include "curses.h"

int main() {
	Board*sudoku_board = new Board;
	Table*sudoku_table = new Table;

	int state = sudoku_board->loop(sudoku_table);
	if (state == 1) {
		sudoku_table->solve();
	}
	else if (state == 0) {
		endwin();
		return 0;
	}
}