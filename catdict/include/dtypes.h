#ifndef DTYPES
#define DTYPES
#define PY_SSIZE_T_CLEAN
#include <Python.h>

#define Py_RETURN_ERR do {                                           \
    PyErr_SetString(PyExc_ValueError, "unexpected error occurred!"); \
    return NULL;                                                     \
} while (0)

#define Py_RETURN_CR_ERR do {                                        \
    PyErr_SetString(PyExc_ValueError, "unexpected cursor!");         \
    return NULL;                                                     \
} while (0)

#define Py_RETURN_HASH_ERR do {                                      \
    PyErr_SetString(PyExc_TypeError, "unhashable key!");             \
    return NULL;                                                     \
} while (0)


/** ================================================================================================
 *  catdict definition
 */

typedef enum Cursor {
    CR_NULL = 0,
    CR_unicode,
    CR_bool,
    CR_long,
    CR_float,
    CR_list,
    CR_tuple,
    CR_dict,
    CR_set
} cursor;

typedef struct Catdict {
    PyObject_HEAD
    PyObject *dict_unicode;
    PyObject *dict_bool;
    PyObject *dict_long;
    PyObject *dict_float;
    PyObject *dict_list;
    PyObject *dict_tuple;
    PyObject *dict_dict;
    PyObject *dict_set;
    cursor cursor;
} catdict;

/** ================================================================================================
 *  Function definition
 */

PyObject *
cd_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
cd_init(catdict *self, PyObject *args, PyObject *kwds);

void
cd_dealloc(catdict *self);

PyObject *
cd_str(catdict *cd);

#endif /* DTYPES */
