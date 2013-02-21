#include "dropflow.h"

DropFlow::DropFlow(WINDOW *win, int index, int span, int indent)
{
	_win = win;
	_index = index;
	_span = span;
	_counter = 0;
	_fillspace = indent;
	_length = COLS;

	_str.resize(_length, ' ');
}

DropFlow::~DropFlow()
{
}

void DropFlow::setSpan(int span)
{
	_span = span;
}

void DropFlow::refresh()
{
	if (_counter++ < _span) return;
	this->display();
	_counter = 0;
}

void DropFlow::display()
{
	this->transform();
	this->move();

	wattron(_win, COLOR_PAIR(1));
	mvwprintw(_win, _index, 0, "%s", _str.c_str());

	wattron(_win, A_BOLD);
	for (std::vector<int>::iterator it = _headers.begin(); it != _headers.end(); it++) {
		chtype c = mvwinch(_win, _index, *it);
		mvwaddch(_win, _index, *it, c);
	}
	wattroff(_win, A_BOLD);
}

void DropFlow::move()
{
	char c = ' ' + rand() % 95; 
	if ( c == ' ' ) {
		_fillspace = rand() % (_length / 2);

		if (_fillspace > _length / 4)
			this->setSpan(rand() % 8);
	}

	if (_fillspace == 0 && _str.at(1) == ' ')
		_headers.insert(_headers.begin(), 0);

	_str.insert(_str.begin(), _fillspace && _fillspace--? ' ': c);
	_str.resize(_length, '*');

	for (std::vector<int>::iterator it = _headers.begin(); it != _headers.end(); ++it)
		(*it)++;

	if (_headers.size() && _headers.back() >= _length)
		_headers.pop_back();
}

void DropFlow::transform()
{
	int count = rand() % (_length / 8);

	while (count--) {
		int index = rand() % _length;

		if (_str.at(index) == ' ') continue;

		char c = '!' + rand() % 94; 
		_str.replace(index, 1, 1, c);
	}	
}
