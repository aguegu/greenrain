#ifndef _DROPFLOW_H_
#define _DROPFLOW_H_

#include <cstdio>
#include <cstdlib>
#include <string>
#include <curses.h>
#include <vector>

class DropFlow
{
public:
	DropFlow(WINDOW * win, int index, bool is_vertial = false, 
			int span = 1, int indent = 0);
	virtual ~DropFlow();
	void setSpan(int span);
	void display();
	void move();
	void transform();
private:
	int _index;
	int _length;
	std::string _str;
	WINDOW *_win;
	int _span;
	int _counter;
	int _fillspace;
	std::vector<int> _headers;
};

#endif
