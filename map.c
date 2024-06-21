#include "minesweeper.h"

static void	calc_tile_value(int x, int y)
{
	int	value;

	if (g_map[y][x] == -1)
		return ;
	value = 0;
	if (x > 0)
	{
		if (y > 0)
			value += g_map[y - 1][x - 1] == -1;
		value += g_map[y][x - 1] == -1;
		if (y < HEIGHT - 1)
			value += g_map[y + 1][x - 1] == -1;
	}
	if (y > 0)
		value += g_map[y - 1][x] == -1;
	if (y < HEIGHT - 1)
		value += g_map[y + 1][x] == -1;

	if (x < WIDTH - 1)
	{
		if (y > 0)
			value += g_map[y - 1][x + 1] == -1;
		value += g_map[y][x + 1] == -1;
		if (y < HEIGHT - 1)
			value += g_map[y + 1][x + 1] == -1;
	}
	g_map[y][x] = value;
}

void	generate_map()
{
	int	count;
	int	x;
	int	y;

	count = 0;
	while (count < MINES)
	{
		x = rand() % WIDTH;
		y = rand() % HEIGHT;
		if (g_map[y][x] == -1)
			continue;
		g_map[y][x] = -1;
		count++;
	}
	
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++)
			calc_tile_value(i, j);
}
