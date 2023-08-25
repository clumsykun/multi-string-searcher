#ifndef CD_LIST
#define CD_LIST
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "catdict.h"

PyObject *
db_l_set(database *db, PyObject *args);

PyObject *
db_l_get(database *db, PyObject *args);

#endif /* CD_LIST */
