#ifndef CD_SET
#define CD_SET
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "catdict.h"

PyObject *
db_s_set(database *db, PyObject *args);

PyObject *
db_s_get(database *db, PyObject *args);

#endif /* CD_SET */
