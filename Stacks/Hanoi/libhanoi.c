#include "Hanoi.h"

// Include local
#include <lib/validate.h>
#include <lib/util.h>
#include <Stacks/Vector/StackVector.h>

// Include standar
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

Hanoi_t *
newHanoi (size_t length)
{
  valSize (length);
  Hanoi_t *hanoi = (Hanoi_t *) calloc (1, sizeof (Hanoi_t));
  valMem (hanoi);
  hanoi->length = length;
  hanoi->rv = 0x0;
  hanoi->mv = 0x0;
  hanoi->lv = newVector (length);
  for (size_t i = 0, j = length; i < length; i++, j--)
    writeOnVector (hanoi->lv, i, j);
  return hanoi;
}

Hanoi_t *
destroyHanoi (Hanoi_t * hanoi)
{
  if (hanoi == 0x0)
    return 0x0;
  hanoi->lv = destroyVector (hanoi->lv);
  hanoi->mv = destroyVector (hanoi->mv);
  hanoi->rv = destroyVector (hanoi->rv);
  free (hanoi);
  return 0x0;
}

void
printHanoi (Hanoi_t * hanoi)
{
  if (hanoi == 0x0)
    {
      printf ("(nil)");
      return;
    }

  printf ("{ length: %i\n", (int) hanoi->length);
  printtb;
  printVector (hanoi->lv);
  println;
  printtb;
  printVector (hanoi->mv);
  println;
  printtb;
  printVector (hanoi->rv);
  println;
  printf ("}");
}


static void
solve_hanoi_recursive (Hanoi_t * hanoi, size_t discs, Vector_t * *origin,
		       Vector_t * *meta, Vector_t * *aux)
{
  if (discs == 0)
    return;
  solve_hanoi_recursive (hanoi, discs - 1, origin, aux, meta);
  *meta = stackVectorPush (*meta, stackVectorPop (origin));
  printHanoi (hanoi);
  println;
  solve_hanoi_recursive (hanoi, discs - 1, aux, meta, origin);
}

void
solveHanoi (Hanoi_t * hanoi)
{
  valPtr (hanoi);
  solve_hanoi_recursive (hanoi, hanoi->length, &(hanoi->lv), &(hanoi->rv),
			 &(hanoi->mv));
}
