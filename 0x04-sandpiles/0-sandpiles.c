#include "sandpiles.h"

/**
 * is_stable - Function that sum check the values in sandpile
 * @grid: sandpile to check
 * Return: 1 is not stable
 */
int is_stable(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			if (grid[x][y] > 3)
				return (0);
	return (1);
}

/**
 * top_stable - Function that looking for stability
 * @grid: inestable sandpile
 * Return: Non return
 */
void top_stable(int grid[3][3])
{
	int x, y;
	int three_grid[3][3];

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			three_grid[x][y] = 0;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] >= 4)
			{
				grid[x][y] -= 4;
				if ((x - 1 >= 0) && (x - 1 < 3))
					three_grid[x - 1][y] += 1;
				if ((y - 1 >= 0) && (y - 1 < 3))
					three_grid[x][y - 1] += 1;
				if ((x + 1 >= 0) && (x + 1 < 3))
					three_grid[x + 1][y] += 1;
				if ((y + 1 >= 0) && (y + 1 < 3))
					three_grid[x][y + 1] += 1;
			}
		}
	}
	sum_2_sand(grid, three_grid);
}


/**
 * sum_2_sand - Function that sum 2 sandpiles
 * @grid1: first stable sandpile
 * @grid2: second stable sandpile
 * Return: Non return
 */
void sum_2_sand(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];
}

/**
 * print_sandpile - Function prints the sandpile
 * @grid: Sandpile
 * Return: Non return
 */
void print_sandpile(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (y)
				printf(" ");
			printf("%d", grid[x][y]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Complete sum 2 sandpiles
 * @grid1: first stable sandpile
 * @grid2: second stable sandpile
 * Return: Non return
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_2_sand(grid1, grid2);

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_sandpile(grid1);
		top_stable(grid1);
	}
}
