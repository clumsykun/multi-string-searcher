#ifndef CD_LONG
#define CD_LONG
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "catdict.h"

PyObject *
db_i_set(database *db, PyObject *args);

PyObject *
db_i_get(database *db, PyObject *args);

#endif /* CD_LONG */
