#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include "dropflow.h"

int main(int argc, char ** argv)
{
	initscr();
	cbreak();
	noecho();
	timeout(200);

	DropFlow df(stdscr, COLS, 0, "hi");

	while(getch() != 'q') {
//		display();
		clear();
		df.display();
		df.move();
		refresh();
	}
	endwin();
	exit(EXIT_SUCCESS);
}
