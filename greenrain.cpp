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
	curs_set(0);

	start_color();

	timeout(20);

	std::vector<DropFlow> flows;

	init_pair(1, COLOR_GREEN, 0);

	for (int i=0; i<LINES; i++)
		flows.push_back(DropFlow(stdscr, i, false, rand() % 8));

	while(getch() != 'q') {
		for (std::vector<DropFlow>::iterator it = flows.begin() ; it != flows.end(); ++it)
			(*it).display();
		refresh();
	}

//	sleep(10);

	endwin();
	exit(EXIT_SUCCESS);
}
