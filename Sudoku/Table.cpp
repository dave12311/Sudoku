#include "Sudoku.h"

int Table::count_unknowns()
{
	int num = 0;
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			if (table[x][y] == 0) {
				num++;
			}
		}
	}
	return num;
}

bool Table::quick_solve()
{
	bool list[9];
	int count;
	int empty;

	for (int lines = 0; lines < 9; lines++) {
		for (int i = 0; i < 9; i++) { list[i] = false; }
		count = 0;

		for (int cells = 0; cells < 9; cells++) {
			if (table[lines][cells] != 0) {
				list[cells] = true;
				count++;
			}
			else {
				empty = cells;
			}
		}
	}
}

Table::Table()
{
	reset();
}

void Table::addValue(int y, int x, int val)
{
	table[y][x] = val;
}

void Table::reset()
{
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			table[x][y] = 0;
		}
	}
}

void Table::solve()
{
	unknowns = count_unknowns();
	if (quick_solve() == false) {

	}
}