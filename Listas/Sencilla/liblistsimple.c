#include "ListSimple.h"
#include <Lists/Generic/List.h>
#include <lib/validate.h>

void
initListSimplePointer (Node_t * *list, size_t size)
{
  valSize (size);
  *list = newList (size, 1);
}
