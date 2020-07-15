#include "util.h"
#include "validar.h"

#include <stdio.h>
#include <stdlib.h>

int
aleatorio (int lower, int upper)
{
  if (lower > upper)
    {
      fprintf (stderr, "%s(): lower bigger than upper %i > %i\n",
	       __FUNCTION__, lower, upper);
      exit (EXIT_FAILURE);
    }
  return (rand () % (upper - lower + 1)) + lower;
}

int
mod (int a, int b)
{
  int r = a % b;
  return r < 0 ? r + b : r;
}
