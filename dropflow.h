#ifndef _DROPFLOW_H_
#define _DROPFLOW_H_

#include <cstdio>
#include <string>
#include <curses.h>

class DropFlow
{
public:
	DropFlow(WINDOW * win, int col, int row, const char *str);
	virtual ~DropFlow();
	void display();
	void move();
private:
	int _col, _row;
	std::string _str;
	WINDOW *_win;
};

#endif
