#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <Python.h>
#include "catdict.h"


PyObject *
db_create(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    database* self;
    self = (database *) type->tp_alloc(type, 0);

    if (self != NULL) {
        self->dict_unicode = NULL;
        self->dict_long    = NULL;
        self->dict_float   = NULL;
        self->dict_list    = NULL;
        self->dict_dict    = NULL;
    }

    return (PyObject *) self;
}

int
db_init(database *self, PyObject *args, PyObject *kwds)
{
    return 0;
}

void
db_delete(database *self)
{
    Py_XDECREF(self->dict_unicode);
    Py_XDECREF(self->dict_long);
    Py_XDECREF(self->dict_float);
    Py_XDECREF(self->dict_list);
    Py_XDECREF(self->dict_dict);
    Py_XDECREF(self->dict_set);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
db_display(database *db, PyObject *Py_UNUSED(ignored))
{
    Py_ssize_t size;
    printf("Status of CatDict(%p):\n", db);

    if (db->dict_long) {
        size = PyDict_Size(db->dict_long);
        printf("    int   variables (%ld)\n", size);
    }

    if (db->dict_long) {
        size = PyDict_Size(db->dict_long);
        printf("    float variables (%ld)\n", size);
    }

    if (db->dict_unicode) {
        size = PyDict_Size(db->dict_unicode);
        printf("    str   variables (%ld)\n", size);
    }

    if (db->dict_list) {
        size = PyDict_Size(db->dict_list);
        printf("    list  variables (%ld)\n", size);
    }

    if (db->dict_set) {
        size = PyDict_Size(db->dict_set);
        printf("    set   variables (%ld)\n", size);
    }

    Py_RETURN_NONE;
}

PyObject *
db_as_dict(database *db, PyObject *Py_UNUSED(ignored))
{
    PyObject *ret = PyDict_New();

    if (ret == NULL)
        Py_RETURN_ERR;

    if (db->dict_long != NULL)
        if (PyDict_SetItemString(ret, "int", db->dict_long) < 0)
            Py_RETURN_ERR;

    if (db->dict_float != NULL)
        if (PyDict_SetItemString(ret, "float", db->dict_float) < 0)
            Py_RETURN_ERR;

    if (db->dict_unicode != NULL)
        if (PyDict_SetItemString(ret, "str", db->dict_unicode) < 0)
            Py_RETURN_ERR;

    if (db->dict_list != NULL)
        if (PyDict_SetItemString(ret, "list", db->dict_list) < 0)
            Py_RETURN_ERR;

    if (db->dict_set != NULL)
        if (PyDict_SetItemString(ret, "set", db->dict_set) < 0)
            Py_RETURN_ERR;

    return ret;
}
