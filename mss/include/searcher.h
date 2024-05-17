#ifndef SEARCHER
#define SEARCHER
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "dtypes.h"

typedef struct {
    PyObject_HEAD
    targets *tgs;
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

PyObject *
Searcher_num_targets(Searcher *self);

PyObject *
Searcher_index_add(Searcher *self, PyObject *args);

PyObject *
Searcher_index_size(Searcher *self);

#endif /* SEARCHER */
