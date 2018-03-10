/*
 * Copyright Daniel Jones 2016-2018
 *
 * This file is part of RGBController.
 *
 * RGBController is free software: you can redistribute it and/or modifiy
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RGBController is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RGBController.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <ncurses.h>

int open_port();
void write_port(int fd, char *str);

int fd;

char *main_menu_items[] = {
	"color",
	"fade",
	"presets",
	"raw",
	"exit",
};
int total_main_items = sizeof(main_menu_items) / sizeof(char *);

WINDOW *menuwindow;
WINDOW *fadewindow;
WINDOW *presetswindow;

void main_menu(int index);

void print_menu(WINDOW *win, int index, char *items[], int itemsize);

int main(int argc, char *argv[])
{
	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0);
	mvprintw(0, 0, "RGB Controller");
	mvprintw(1, 0, "Use the arrow keys to navigate, enter to select");
	clrtoeol();
	refresh();
	fd = open_port();
	//sleep(2); /* let the arduino wake up */
	write_port(fd, "off\n");
	main_menu(1);
	close(fd);
	endwin();
	delwin(menuwindow);
	delwin(fadewindow);
	delwin(presetswindow);
	return 0;
}

int open_port()
{
	int fd;
	fd = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd == -1)
	{
		mvprintw(3, 0, "port error: unable to open port\n");
	}
	else
	{
		fcntl(fd, F_SETFL, 0);
	}
	return fd;
}

void write_port(int fd, char *str)
{
	int n;
	n = write(fd, str, strlen(str));
	if (n < 0)
		fputs("writing error:\n", stderr);
}

void main_menu(int index)
{
	menuwindow = newwin(total_main_items + 4, 16, LINES / 2 - total_main_items, (COLS - 16) / 2);
	int menuindex = index; /* store menu index */
	int selected = 0; /* stores the menu item selected */
	int in; /* stores user input */
	keypad(menuwindow, TRUE);
	print_menu(menuwindow, menuindex, main_menu_items, total_main_items);
	/* input loop */
	while (1)
	{
		in = wgetch(menuwindow);
		switch (in)
		{
			case KEY_UP:
				if (menuindex == 1)
					menuindex = total_main_items;
				else
					menuindex--;
				break;
			case KEY_DOWN:
				if (menuindex == total_main_items)
					menuindex = 1;
				else
					menuindex++;
				break;
			case 10:
				selected = menuindex;
				break;
		}
		print_menu(menuwindow, menuindex, main_menu_items, total_main_items);
		if (selected != 0)
			break;
	}
	if (selected - 1 == 0)
	{
		mvprintw(3, 0, "option 1");
		refresh();
		main_menu(1);
	}
	if (selected - 1 == 3)
	{
		move(3, 0);
		clrtoeol();
		mvprintw(3, 0, "Enter string to send: ");
		refresh();
		echo();
		char str[128];
		getstr(str);
		write_port(fd, "redfade\n");
		main_menu(4);
	}
	wclear(menuwindow); /* causes flashes, fix by only clearing lines below x */
	wrefresh(menuwindow);
	}


void print_menu(WINDOW *win, int index, char *items[], int itemsize)
{
	int x = 2;
	int y = 2;
	wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');	

	for (int i = 0; i < itemsize; i++)
	{
		if (index == i + 1)
		{
			wattron(win, A_REVERSE);
			mvwprintw(win, y, x, "%s", items[i]);
			wattroff(win, A_REVERSE);
		}
		else 
			mvwprintw(win, y, x, "%s", items[i]);
		y++;
		wrefresh(win);
	}
}
