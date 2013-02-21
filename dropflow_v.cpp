#include "dropflow_v.h"

DropFlowV::DropFlowV(WINDOW * win, int index, int span, int indent)
	:DropFlow(win, index, span, indent)
{
	_length = LINES;
	_str.resize(_length, ' ');
}

DropFlowV::~DropFlowV()
{

}

void DropFlowV::display()
{
	this->transform();
	this->move();

	wattron(_win, COLOR_PAIR(1));
	for (unsigned int i = 0; i<_str.length(); i++)
		mvwaddch(_win, i, _index, _str.at(i));

	wattron(_win, A_BOLD);
	for (std::vector<int>::iterator it = _headers.begin(); it != _headers.end(); it++) {
		chtype c = mvwinch(_win, *it, _index);
		mvwaddch(_win, *it, _index, c);
	}
	wattroff(_win, A_BOLD);
}
