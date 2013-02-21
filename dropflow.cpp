#include "dropflow.h"

DropFlow::DropFlow(WINDOW *win, int row, int span, int indent)
{
	_win = win;
	_row = row;
	_span = span;
	_counter = 0;
	_fillspace = indent;
	
	_str.resize(COLS, ' ');
}

DropFlow::~DropFlow()
{
}

void DropFlow::setSpan(int span)
{
	_span = span;
}

void DropFlow::display()
{
	if (_counter++ < _span) return;

	this->transform();
	this->move();
	mvwprintw(_win, _row, 0, "%s", _str.c_str());
	_counter = 0;
}

void DropFlow::move()
{
	char c = ' ' + rand() % 94; 
	if ( c == ' ' )
		_fillspace = rand() % COLS;

	_str.insert(_str.begin(), _fillspace && _fillspace--? ' ': c);
	_str.resize(COLS, '*');
}

void DropFlow::transform()
{
	int count = rand() % (COLS / 2);

	while (count--) {
		int index = rand() % COLS;
		
		if (_str.c_str()[index] == ' ') continue;
		
		char c = '!' + rand() % 94; 
		_str.replace(index, 1, 1, c);
	}	
}
