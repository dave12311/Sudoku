#include "Sudoku.h"
#include "curses.h"
#include <iostream>

Board::Board() {
	init();
	drawBoard();
}

int Board::loop(Table*table) {
	int in;
	int y = 1, x = 2;
	move(y, x);
	while (true) {
		if (in = getch()) {
			if (in == KEY_RIGHT && x < 33) {
				x += 4;
			}
			else if (in == KEY_LEFT && x > 2) {
				x -= 4;
			}
			else if (in == KEY_DOWN && y < 17) {
				y += 2;
			}
			else if (in == KEY_UP && y > 1) {
				y -= 2;
			}
			else if (in >= 49 && in <= 57) {
				addch(in);
				table->addValue((y - 1) / 2, (x - 2) / 4, in - 48);
			}
			else if (in == 8) { //DEL
				addch(' ');
				table->addValue((y - 1) / 2, (x - 2) / 4, 0);
			}
			else if (in == 114) { //RESET
				drawBoard();
				table->reset();
			}
			else if (in == 115) { //SOLVE
				return 1;
			}
			else if (in == 120) { //EXIT
				return 0;
			}
			else {
				//std::cout << in;
			}
			move(y, x);
		}
	}
}

void Board::init() {
	initscr();
	keypad(stdscr, true);
	noecho();
}

void Board::drawBoard() {
	for (int i = 0; i < 19; i++) {
		move(i, 0);
		for (int j = 0; j < 37; j++) {
			addch(table[i][j]);
		}
	}
	move(20, 0);
	printw("S: Solve");
	move(21, 0);
	printw("R: Reset");
	move(22, 0);
	printw("X: Exit");
}