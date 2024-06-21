#ifndef MINESWEEPER_H
# define MINESWEEPER_H

# include <termios.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define WIDTH 10
# define HEIGHT 15
# define MINES 30

extern int	g_x;
extern int	g_y;
extern int	g_map[HEIGHT][WIDTH];
extern int	g_flags[HEIGHT][WIDTH];
extern int	g_revealed[HEIGHT][WIDTH];
extern int	g_lost;
extern int	g_remaining;

void	init();
void	deinit();
void	perform_action(char key);
void	move_cursor(int x, int y);
void	reveal_tile();
void	print_remaining();
void	generate_map();
void	perform_action(char key);

#endif