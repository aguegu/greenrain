#include "dropflow.h"

DropFlow::DropFlow(WINDOW *win)
{
	_win = win;
	_c = 0;
	_r = 0;

	_str = "Hello, world.";
}

DropFlow::~DropFlow()
{
}

void DropFlow::display()
{
	mvwprintw(_win, _r, _c, "%s", _str.c_str());
}
