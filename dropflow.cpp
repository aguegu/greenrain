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

	attron(A_BOLD);
	for (std::vector<int>::iterator it = _headers.begin(); it != _headers.end(); it++) {
		chtype c = mvwinch(_win, _row, *it);
		mvwaddch(_win, _row, *it, c);
	}
	attroff(A_BOLD);

	_counter = 0;
}

void DropFlow::move()
{
	char c = ' ' + rand() % 95; 
	if ( c == ' ' ) {
		_fillspace = rand() % (COLS / 2);

		if (_fillspace > COLS / 4)
			this->setSpan(rand() % 8);
	}

	if (_fillspace == 0 && _str.at(1) == ' ')
		_headers.insert(_headers.begin(), 0);

	_str.insert(_str.begin(), _fillspace && _fillspace--? ' ': c);
	_str.resize(COLS, '*');

	for (std::vector<int>::iterator it = _headers.begin(); it != _headers.end(); ++it)
		(*it)++;

	if (_headers.size() && _headers.back() >= COLS)
		_headers.pop_back();
}

void DropFlow::transform()
{
	int count = rand() % (COLS / 2);

	while (count--) {
		int index = rand() % COLS;

		if (_str.at(index) == ' ') continue;

		char c = '!' + rand() % 94; 
		_str.replace(index, 1, 1, c);
	}	
}
