#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include "dropflow.h"

void display()
{
	static int c=140, r=0;
	clear();
	move(r, c++);
	printw("(%d, %d)", c, r);
	refresh();
}

int main(int argc, char ** argv)
{
	initscr();
	cbreak();
	noecho();
	timeout(1000);

	DropFlow df(stdscr);

	while(getch() != 'q') {
//		display();
		df.display();
		refresh();
	}
	endwin();
	exit(EXIT_SUCCESS);
}
