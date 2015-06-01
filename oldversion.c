#include <stdio.h>

#define MAX_GRID 100

int findMinIndex (int *grid, int size);

int main (void)
{
  int i;
  int min;
  int size;
  int grid[MAX_GRID * MAX_GRID];
  int nLogs;

  /* Read grid size and number of logs. */
  scanf ("%d %d", &size, &nLogs);

  /* Read log pile locations. */
  for (i = 0; i < size * size; i++) {
    scanf ("%d", &grid[i]);
  }

  /* Place logs. */
  while (nLogs > 0) {
    grid[findMinIndex (grid, size)]++;
    nLogs--;
  }

  /* Print grid. */
  for (i = 0; i < size * size; i++) {
    printf ("%d ", grid[i]);
    if ((i+1) % size == 0) {
      printf ("\n");
    }
  }

  return 0;
}

/* Find the index of the pile with the least number of logs. */
int
findMinIndex (int *grid, int size)
{
  int min;
  int i;
  min = 0;
  for (i = 1; i < size * size; i++) {
    if (grid[i] < grid[min]) {
      min = i;
    }
  }
  return min;
}
