#include "dropflow.h"

DropFlow::DropFlow(WINDOW *win, int col, int row, const char * str)
{
	_win = win;
	_col = col;
	_row = row;

	_str = str;
}

DropFlow::~DropFlow()
{
}

void DropFlow::display()
{
	int start = _col;
	int end = _col + _str.length();

	if (end < 0) return;
	if (start > COLS) return;

	if (start < 0) start = 0;
	if (end > COLS) end = COLS;

	int length = end - start;

	int index = _col < 0? - _col : 0;

	mvwprintw(_win, _row, start, "%.*s", length, _str.c_str()  + index);
}

void DropFlow::move()
{
	_col--;
}
