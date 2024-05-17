#include <stdio.h>
#include "targets.h"

int
tgs_add_target(targets *tgs, const char *target)
{
    printf("add target:%s \n", target);
    tgs->num_targets += 1;

    return 0;
}
