#ifndef _DROPFLOW_H_
#define _DROPFLOW_H_

#include <cstdio>
#include <cstdlib>
#include <string>
#include <curses.h>

class DropFlow
{
public:
	DropFlow(WINDOW * win, int row, int span = 1, int indent = 0);
	virtual ~DropFlow();
	void setSpan(int span);
	void display();
	void move();
	void transform();
private:
	int _row;
	std::string _str;
	WINDOW *_win;
	int _span;
	int _counter;
	int _fillspace;
};

#endif
