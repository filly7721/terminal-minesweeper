#include "minesweeper.h"

int	g_x;
int	g_y;
int g_map[HEIGHT][WIDTH];
int g_revealed[HEIGHT][WIDTH];
int g_flags[HEIGHT][WIDTH];
int g_lost;
int g_remaining;

static void print_line(int width, char start, char mid, char end)
{
	printf("%c", start);
	while (width-- > 0)
		printf("%c", mid);
	printf("%c", end);
}

static void print_canvas(int width, int height)
{
	print_line(width, '/', '-', '\\');
	printf("\n");
	while (height-- > 0)
	{
		print_line(width, '|', ' ', '|');
		printf("\n");
	}
	print_line(width, '\\', '-', '/');
	printf("\r");
}

void init()
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag &= ~ECHO;
	t.c_lflag &= ~ICANON;
	tcsetattr(0, 0, &t);
	printf("\e[1;1H");
	printf("\e[2J");
	printf("\e[2 q");
	g_x = 0;
	g_y = 0;
	g_lost = 0;
	g_remaining = WIDTH * HEIGHT - MINES;
	srand(time(0));
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++)
			{
				g_map[j][i] = 0;
				g_flags[j][i] = 0;
				g_revealed[j][i] = 0;
			}
	generate_map();

	printf("\n");
	print_canvas(WIDTH, HEIGHT);
	move_cursor(1, 1);
	print_remaining();
}

void	deinit()
{
	struct termios	t;

	tcgetattr(0, &t);
	t.c_lflag |= ECHO;
	t.c_lflag |= ICANON;
	tcsetattr(0, 0, &t);
	printf("\e[1;1H");
	printf("\e[2J");
}