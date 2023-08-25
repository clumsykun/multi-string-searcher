#ifndef CATDICT
#define CATDICT
#define PY_SSIZE_T_CLEAN
#include <Python.h>

/** ================================================================================================
 *  Database definition
 */

typedef struct Database {
    PyObject_HEAD
    PyObject *dict_unicode;
    PyObject *dict_long;
    PyObject *dict_float;
    PyObject *dict_list;
    PyObject *dict_dict;
    PyObject *dict_set;
} database;

/** ================================================================================================
 *  Function definition
 */

PyObject *
db_create(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
db_init(database *self, PyObject *args, PyObject *kwds);

void
db_delete(database *self);

PyObject *
db_display(database *db, PyObject *Py_UNUSED(ignored));

PyObject *
db_as_dict(database *db, PyObject *Py_UNUSED(ignored));

#define abs(x) ((x)> 0 ? (x) : -(x))
#define find_pnode(hash, table) ( \
    (void **)(table->nodes) + ((size_t)(hash) % (size_t)(table->size)) \
)

#define Py_RETURN_ERR { \
    PyErr_SetString(PyExc_ValueError, "Unexpected ERROR occurred!"); \
    return NULL; \
}

#define SET_DEFAULT_ERR PyErr_SetString(PyExc_ValueError, "Unexpected ERROR occurred!")

#endif /* CATDICT */
