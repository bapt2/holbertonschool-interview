#include "sandpiles.h"

/**
 * is_stable - verify if the sandpiles is stable or not
 * @grid: sandpiles to check
 * Return: return an int
 */
 int is_stable(int grid[3][3])
 {
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if(grid[i][j] > 3)
{
return 1;
}
}
}
return 0;
}

/**
 * topple - topple a sandpiles
 * @grid: grid to topple
 */
void topple(int grid[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
{
grid[i][j] -= 4;
if (i - 1 >= 0)
{
grid[i - 1][j]++;
}
if (i + 1 < 3)
{
grid[i + 1][j]++;
}
if (j - 1 >= 0)
{
grid[i][j - 1]++;
}
if (j + 1 < 3)
{
grid[i][j + 1]++;
}
}
}
}
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: first grid to add
 * @grid2: second grid to add
 **/
 void sandpiles_sum(int grid1[3][3], int grid2[3][3])
 {
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
grid1[i][j] += grid2[i][j];
}
}

while(is_stable(grid1))
{
printf("=\n");
for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
{
printf(" ");
}
printf("%d", grid1[i][j]);
}
printf("\n");
}
topple(grid1);
}
}