#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "dtypes.h"
#include "searcher.h"

/**
 * Multi-string Searcher
 */

PyObject *
Searcher_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Searcher *self = (Searcher *) type->tp_alloc(type, 0);

    if (self != NULL) {
        // self->name = PyUnicode_FromString("Multi-string Searcher");

        self->tgs = (targets *)malloc(sizeof(targets));
        self->tgs->num_targets = 0;

        // if (self->name == NULL) {
        //     Py_DECREF(self);
        //     return NULL;
        // }
    }

    return (PyObject *)self; 
}

int
Searcher_init(Searcher *self, PyObject *args, PyObject *kwds)
{
    return 0;
}

void
Searcher_dealloc(Searcher *self)
{
    // Py_DECREF(self->name);
    free(self->tgs);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

int
Searcher_ignore(Searcher *self, void *closure)
{
    return 0;
}

PyObject *
Searcher_num_targets(Searcher *self)
{
    return PyLong_FromSize_t(self->tgs->num_targets);
}

PyObject *
Searcher_index_add(Searcher *self, PyObject *args)
{
    int value;
    if (!PyArg_ParseTuple(args, "I", &value)) {
        return NULL;
    }
    // self->dict->size += value;
    Py_RETURN_NONE;
}

PyObject *
Searcher_index_size(Searcher *self)
{
    PyObject *size = PyLong_FromSize_t(0);
    Py_INCREF(size);
    return size;
}
