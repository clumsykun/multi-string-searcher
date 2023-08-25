#ifndef CD_UNICODE
#define CD_UNICODE
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "catdict.h"

PyObject *
db_u_set(database *db, PyObject *args);

PyObject *
db_u_get(database *db, PyObject *args);

#endif /* CD_UNICODE */
