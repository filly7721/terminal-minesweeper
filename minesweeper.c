#include "minesweeper.h"

void	print_remaining()
{
	printf("\e[s");
	printf("\e[99A");
	printf("\e[0G");
	printf("\e[2K");
	printf("remaining: %i", g_remaining);
	printf("\e[u");
}

int main()
{
	char	key;

	init();
	do
	{
		key = getchar();
		perform_action(key);
	} while (key != ' ' && g_lost == 0 && g_remaining != 0);

	printf("\e[%iE", g_y + 1);
	if (g_lost)
		printf("\n lmao loser\n");
	else
		printf("\n beginners luck\n");
	getchar();
	deinit();
}
