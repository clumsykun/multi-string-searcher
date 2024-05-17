#include <stdio.h>
#include <stdlib.h>
#include "targets.h"


targets *
tgs_new()
{
    targets *tgs = (targets *)malloc(sizeof(targets));
    tgs->num_targets = 0;
    return tgs;
}

void
tgs_del(targets *tgs)
{
    free(tgs);
}

int
tgs_add_target(targets *tgs, const char *target)
{
    printf("add target:%s \n", target);
    tgs->num_targets += 1;

    return 0;
}
