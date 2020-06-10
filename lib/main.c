#include "util.h"
#include "validate.h"

#include <stdio.h>

int
main (void)
{
  printf ("Util.h - println\n");
  println;

  printf ("Util.h - printtb\n");
  printtb;

  println;
  printf ("Util.h - randomInRange: %i\n", randomInRange (-100, 100));

  int count = 0;
  countDigits (randomInRange (-100, 100), &count);
  printf ("Util.h - randomInRange: %i\n", count);

  char *str = 0x0;

  integerToString (count, &str, &count);
  printf ("Util.h - integerToString: %s\n", str);
  return 0;
}
