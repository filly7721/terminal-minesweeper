#include "minesweeper.h"

void	move_cursor(int x, int y)
{
	//move left
	while (x < 0)
	{
		printf("\e[0D");
		x++;
	}
	//move right
	while (x > 0)
	{
		printf("\e[0C");
		x--;
	}
	//move down
	while (y < 0)
	{
		printf("\e[0B");
		y++;
	}
	//move up
	while (y > 0)
	{
		printf("\e[0A");
		y--;
	}
}
static void	rec_reveal_tile(int x, int y)
{
	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	if(g_revealed[y][x] == 1)
		return ;
	g_revealed[y][x] = 1;
	g_remaining--;
	printf("%i", g_map[y][x]);
	move_cursor(-1, 0);
	if (g_map[y][x] == 0)
	{
		printf("\e[0D");
		rec_reveal_tile(x - 1, y);
		printf("\e[0A");
		rec_reveal_tile(x - 1, y + 1);
		printf("\e[0C");
		rec_reveal_tile(x, y + 1);
		printf("\e[0C");
		rec_reveal_tile(x + 1, y + 1);
		printf("\e[0B");
		rec_reveal_tile(x + 1, y);
		printf("\e[0B");
		rec_reveal_tile(x + 1, y - 1);
		printf("\e[0D");
		rec_reveal_tile(x, y - 1);
		printf("\e[0D");
		rec_reveal_tile(x - 1, y - 1);
		printf("\e[0A\e[0C");
	}
}

void	reveal_tile()
{
	if (g_x < 0 || g_y < 0 || g_x > WIDTH || g_y > HEIGHT)
		return ;
	if (g_flags[g_y][g_x] == 1)
		return ;
	if (g_map[g_y][g_x] == -1)
	{
		g_lost = 1;
		return ;
	}
	if (g_revealed[g_y][g_x] == 0)
	{
		rec_reveal_tile(g_x, g_y);
		print_remaining();
	}
}

void	place_flag()
{
	if (g_revealed[g_y][g_x] == 1)
		return ;
	if (g_flags[g_y][g_x] == 1)
	{
		g_flags[g_y][g_x] = 0;
		printf(" ");
		move_cursor(-1, 0);
	}
	else
	{
		g_flags[g_y][g_x] = 1;
		printf("-");
		move_cursor(-1, 0);
	}
}

void	perform_action(char key)
{
	switch (key)
	{
	case 'w':
	case 'W':
		if(g_y < HEIGHT - 1)
		{
			move_cursor(0, 1);	
			g_y++;
		}
		break;
	
	case 'a':
	case 'A':
		if(g_x > 0)
		{
			move_cursor(-1, 0);
			g_x--;
		}
		break;
	case 's':
	case 'S':
		if(g_y > 0)
		{
			move_cursor(0, -1);
			g_y--;
		}
		break;
	case 'd':
	case 'D':
		if(g_x < WIDTH - 1)
		{
			move_cursor(1, 0);
			g_x++;
		}
		break;
	case 'q':
	case 'Q':
		place_flag();
		break;
	
	case 'e':
	case 'E':
		reveal_tile();
		break;

	default:
		break;
	}
}