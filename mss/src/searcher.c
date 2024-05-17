#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "dtypes.h"
#include "targets.h"
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
Searcher_add_target(Searcher *self, PyObject *args)
{
    const char *target;
    if (!PyArg_ParseTuple(args, "s", &target)) {
        return NULL;
    }
    if (tgs_add_target(self->tgs, target)) {
        PyErr_Format(PyExc_ValueError, "failed to add target '%s'.\n", target);
        return NULL;
    }

    Py_RETURN_NONE;
}

PyObject *
Searcher_extend_targets(Searcher *self, PyObject *args)
{
    PyObject *iterable, *iterator, *item;
    if (!PyArg_ParseTuple(args, "O", &iterable)) {
        return NULL;
    }

    if (PyUnicode_Check(iterable)) {
        PyErr_Format(
            PyExc_ValueError,
            "'%s' is a string.",
            PyUnicode_AsUTF8AndSize(iterable, NULL)
        );
        return NULL;
    }

    iterator = PyObject_GetIter(iterable);
    if (iterator == NULL) {
        PyErr_Format(
            PyExc_ValueError,
            "'%s' is not iterable.",
            PyUnicode_AsUTF8AndSize(PyObject_Str(iterable), NULL)
        );
        return NULL;
    }

    while ((item = PyIter_Next(iterator))) {

        if (PyUnicode_Check(item)) {
            tgs_add_target(self->tgs, PyUnicode_AsUTF8AndSize(item, NULL));
        }
        else {
            printf("omit non-string target: %s\n", PyUnicode_AsUTF8AndSize(PyObject_Str(item), NULL));
        }

        Py_DECREF(item);
    }



    Py_RETURN_NONE;
}


PyObject *
Searcher_index_size(Searcher *self)
{
    PyObject *size = PyLong_FromSize_t(0);
    Py_INCREF(size);
    return size;
}
