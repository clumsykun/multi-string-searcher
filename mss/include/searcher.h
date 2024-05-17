#ifndef SEARCHER
#define SEARCHER
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "dtypes.h"

typedef struct {
    PyObject_HEAD
    size_t size_targets;
    // dict    *dict;
} Searcher;

/** ================================================================================================
 *  Function definition
 */

PyObject *
Searcher_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

int
Searcher_init(Searcher *self, PyObject *args, PyObject *kwds);

void
Searcher_dealloc(Searcher *self);

int
Searcher_ignore(Searcher *self, void *closure);

Py_ssize_t
Searcher_length(Searcher *self);

PyObject *
Searcher_str(Searcher *cd);

PyObject *
Searcher_index_add(Searcher *self, PyObject *args);

PyObject *
Searcher_index_size(Searcher *self);

#endif /* SEARCHER */
