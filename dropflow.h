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
	DropFlow(WINDOW * win, int index, int span = 1, int indent = 0);
	virtual ~DropFlow();

	void setSpan(int span);
	void transform();
	void refresh();
	
protected:
	virtual void display();
	void move();

	int _length;
	std::string _str;
	int _index;
	WINDOW *_win;
	std::vector<int> _headers;

private:
	int _span;
	int _counter;
	int _fillspace;
};

#endif
