#ifndef CD_FLOAT
#define CD_FLOAT
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "catdict.h"

PyObject *
db_f_set(database *db, PyObject *args);

PyObject *
db_f_get(database *db, PyObject *args);

#endif /* CD_FLOAT */
