#include <ncurses.h>
#include <string.h>

/* server information */
char host[128];
char port[128];

/* stores our menu items */
char *main_menu_items[] = {
	"setup",
	"connect",
	"disconnect",
	"presets",
	"exit",
};

char *setup_menu_items[] = {
	"host",
	"port",
	"back",
};

/* windows */
WINDOW *menuwindow; /* main menu window */
WINDOW *setupwindow; /* setup window */

/* store the number of items in the menus */
int total_main_items = sizeof(main_menu_items) / sizeof(char *);
int total_setup_items = sizeof(setup_menu_items) / sizeof(char *);

/* menu functions */
void mainmenu(int index);
void setupmenu(int index);

/* normal menu print function */
void print_menu(WINDOW *win, int index, char *items[], int itemsize);


int main(int argc, char *argv[])
{
	/* ncurses setup */
	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0);
	mvprintw(0, 0, "RGB controller");
	mvprintw(1, 0, "use the arrow keys to navigate the menu, enter to select");
	clrtoeol();
	refresh();
	/* menus */
	mainmenu(1);
	/* end ncurses */
	endwin();
	return 0;
}

void mainmenu(int index)
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
	wclear(menuwindow); /* causes flashes, fix */
	wrefresh(menuwindow);
	delwin(menuwindow);
	if (selected - 1 == 0)
		setupmenu(1);
}

void setupmenu(int index)
{
	setupwindow = newwin(total_setup_items + 4, 16, LINES / 2 - total_setup_items, (COLS - 16) / 2);
	int menuindex = index; /* store menu index */
	int selected = 0; /* stores the menu item selected */
	int in; /* stores user input */
	keypad(setupwindow, TRUE);
	print_menu(setupwindow, menuindex, setup_menu_items, total_setup_items);
	/* input loop */
	while (1)
	{
		in = wgetch(setupwindow);
		switch (in)
		{
			case KEY_UP:
				if (menuindex == 1)
					menuindex = total_setup_items;
				else
					menuindex--;
				break;
			case KEY_DOWN:
				if (menuindex == total_setup_items)
					menuindex = 1;
				else
					menuindex++;
				break;
			case 10:
				selected = menuindex;
				break;
		}
		print_menu(setupwindow, menuindex, setup_menu_items, total_setup_items);
		if (selected != 0)
			break;
	}
	if (selected == 1)
	{
		move(3, 0);
		clrtoeol();
		mvprintw(3, 0, "Enter a server address: ");
		echo();
		getstr(host);
		noecho();
		move(3, 0);
		clrtoeol();
		mvprintw(3, 0, "host set to: %s", host);
		refresh();
		setupmenu(selected);
	}
	if (selected == 2)
	{
		move(3, 0);
		clrtoeol();
		mvprintw(3, 0, "Enter a server port: ");
		echo();
		getstr(port);
		noecho();
		move(3, 0);
		clrtoeol();
		mvprintw(3, 0, "port set to: %s", port);
		refresh();
		setupmenu(selected);
	}

	wclear(setupwindow);
	wrefresh(setupwindow);
	delwin(setupwindow);
	if (selected - 1 == 2)
		mainmenu(1);
}

void print_menu(WINDOW *win, int index, char *items[], int itemsize)
{
	int x = 2;
	int y = 2;
	box(win, 0, 0); /* draw our border */
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






