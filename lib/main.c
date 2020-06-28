#include "util.h"
#include "validar.h"

#include <stdio.h>

int
main (void)
{
  printf ("Util.h - println\n");
  println;

  printf ("Util.h - printtb\n");
  printtb;

  println;
  printf ("Util.h - randomInRange: %i\n", aleatorio (-100, 100));

  return 0;
}
