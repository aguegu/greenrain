#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <vector>
#include "dropflow.h"
#include "dropflow_v.h"

int main(int argc, char ** argv)
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);

	start_color();

	timeout(20);

	std::vector<DropFlow*> flows;

	init_pair(1, COLOR_GREEN, 0);

	for (int i=0; i<3; i++) {
		flows.push_back(new DropFlowV(stdscr, 132 + i, rand() % 8));
		flows.push_back(new DropFlow(stdscr, 32 + i, rand() % 4));
	}

	while(getch() != 'q') {
		for (std::vector<DropFlow *>::iterator it = flows.begin() ; it != flows.end(); ++it)
			(*(*it)).refresh();
		refresh();
	}

	endwin();
	exit(EXIT_SUCCESS);
}
