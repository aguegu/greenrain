#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <vector>
#include "dropflow.h"

int main(int argc, char ** argv)
{
	initscr();
	cbreak();
	noecho();
	//curs_set(0);
	timeout(20);

	std::vector<DropFlow> flows;
	flows.reserve(LINES);

	for (int i=0; i<LINES; i++)
		flows.push_back(DropFlow(stdscr, i, rand() % 10));

	DropFlow df(stdscr, 0, 5);
	DropFlow df2(stdscr, 1, 3);

	while(getch() != 'q') {
		for (std::vector<DropFlow>::iterator it = flows.begin() ; it != flows.end(); ++it)
			(*it).display();
		refresh();
	}
	endwin();
	exit(EXIT_SUCCESS);
}
