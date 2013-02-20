#ifndef _DROPFLOW_H_
#define _DROPFLOW_H_

#include <cstdio>
#include <string>
#include <curses.h>

class DropFlow
{
public:
	DropFlow(WINDOW * win);
	virtual ~DropFlow();
	void display();
private:
	int _c, _r;
	std::string _str;
	WINDOW *_win;
};

#endif
