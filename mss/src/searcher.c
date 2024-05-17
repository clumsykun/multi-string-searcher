#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "searcher.h"

/**
 * Multi-string Searcher
 */

PyObject *
Searcher_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Searcher* ser = (Searcher *) type->tp_alloc(type, 0);

    if (ser != NULL) {
        ser->name = Py_BuildValue("Multi-string Searcher");

        if (ser->name == NULL) {
            goto error;
        }
    }

    return (PyObject *) ser;

    error:
        Py_XDECREF(ser->name);
        return NULL;
}

int
Searcher_init(Searcher *self, PyObject *args, PyObject *kwds)
{
    self->dict->size = 0;
    return 0;
}

void
Searcher_dealloc(Searcher *self)
{
    Py_DECREF(self->name);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

int
Searcher_ignore(Searcher *self, void *closure)
{
    return 0;
}

Py_ssize_t
Searcher_length(Searcher *self)
{
    if (self->dict->size > (size_t)PY_SSIZE_T_MAX) {
        PyErr_SetString(PyExc_TypeError, "Something with index size?");
        return -1;
    }

    return (Py_ssize_t)self->dict->size;
}

PyObject *
Searcher_str(Searcher *self)
{
    return self->name;
}

PyObject *
Searcher_index_add(Searcher *self, PyObject *args)
{
    int value;
    if (!PyArg_ParseTuple(args, "I", &value)) {
        return NULL;
    }
    self->dict->size += value;
    Py_RETURN_NONE;
}

PyObject *
Searcher_index_size(Searcher *self, void *closure)
{
    PyObject *size = PyLong_FromSize_t(self->dict->size);
    Py_INCREF(size);
    return size;
}
