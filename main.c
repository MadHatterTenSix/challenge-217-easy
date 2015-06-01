    /**
     *
     * @author __MadHatter (alias used on https://www.reddit.com/r/dailyprogrammer)
     *
     * http://www.reddit.com/r/dailyprogrammer/comments/3840rp/20150601_challenge_217_easy_lumberjack_pile/
     *
     * Edited/optimized/improved by:
     *   AnkePluff
     *
     * Other notable mentions:
     *   downiedowndown
     *   Hopip2
     */

    #include <stdio.h>
    #include <stdlib.h>

    int findMinIndex (int *grid, int size, int *diff);

    int main (void)
    {
      int i;
      int index;
      int diff;
      int len;   /* length of grid */
      int size;  /* size of grid = length * length */
      int nLogs; /* number of logs */
      int *grid; /* pile locations array */
      
      /* Read grid size and number of logs. */
      scanf ("%d %d", &len, &nLogs);
      size = len * len;
      
      /* Allocate grid array. */
      grid = (int *) malloc (sizeof (int) * size);
      
      /* Read log pile locations. */
      for (i = 0; i < size; i++) {
        scanf ("%d", &grid[i]);
      }
      
      /* Place logs. */
      while (nLogs > 0) {
        index = findMinIndex (grid, size, &diff);
        /* If the minimum difference is zero, add 1 rod, not 0. */
        if (diff == 0) {
          diff = 1; 
        }
        grid[index] += diff;
        nLogs -= diff;
      }
      
      /* Print grid. */
      for (i = 0; i < size; i++) {
        printf ("%d ", grid[i]);
        if ((i+1) % len == 0) {
          printf ("\n");
        }
      }
      
      /* Clean up. */
      free (grid);
      
      return 0;
    }

    /* Find the index of the pile with the least number of logs. */
    int
    findMinIndex (int *grid, int size, int *diff)
    {
      int min;
      int i;
      min = 0;
      *diff = 0;
      for (i = 1; i < size; i++) {
        if (grid[i] < grid[min]) {
          *diff = grid[min] - grid[i];
          min = i;
        }
      }
      return min;
    }
