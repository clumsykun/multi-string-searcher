#ifndef TARGETS
#define TARGETS

#include "dtypes.h"

targets *tgs_new();
void     tgs_del(targets *tgs);
int      tgs_add_target(targets *tgs, const char *target);

#endif /* TARGETS */
