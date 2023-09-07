#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "dtypes.h"


PyObject *
cd_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    catdict* cd;
    cd = (catdict *) type->tp_alloc(type, 0);

    if (cd != NULL) {
        cd->dict_unicode = PyDict_New();
        cd->dict_bool    = PyDict_New();
        cd->dict_long    = PyDict_New();
        cd->dict_float   = PyDict_New();
        cd->dict_list    = PyDict_New();
        cd->dict_tuple   = PyDict_New();
        cd->dict_dict    = PyDict_New();
        cd->dict_set     = PyDict_New();
        cd->cursor       = 0;

        if (cd->dict_unicode == NULL)
            goto error;

        if (cd->dict_bool == NULL)
            goto error;

        if (cd->dict_long == NULL)
            goto error;

        if (cd->dict_float == NULL)
            goto error;

        if (cd->dict_list == NULL)
            goto error;

        if (cd->dict_tuple == NULL)
            goto error;

        if (cd->dict_dict == NULL)
            goto error;

        if (cd->dict_set == NULL)
            goto error;
    }

    return (PyObject *) cd;

    error:
        Py_XDECREF(cd->dict_unicode);
        Py_XDECREF(cd->dict_bool);
        Py_XDECREF(cd->dict_long);
        Py_XDECREF(cd->dict_float);
        Py_XDECREF(cd->dict_list);
        Py_XDECREF(cd->dict_tuple);
        Py_XDECREF(cd->dict_dict);
        Py_XDECREF(cd->dict_set);
        return NULL;
}

int
cd_init(catdict *cd, PyObject *args, PyObject *kwds)
{
    return 0;
}

void
cd_dealloc(catdict *cd)
{
    Py_DECREF(cd->dict_unicode);
    Py_DECREF(cd->dict_bool);
    Py_DECREF(cd->dict_long);
    Py_DECREF(cd->dict_float);
    Py_DECREF(cd->dict_list);
    Py_DECREF(cd->dict_tuple);
    Py_DECREF(cd->dict_dict);
    Py_DECREF(cd->dict_set);
    Py_TYPE(cd)->tp_free((PyObject *) cd);
}

PyObject *
cd_str(catdict *cd)
{

    switch (cd->cursor) {

        case CR_NULL:
            return PyUnicode_FromString("<CatDict>");

        case CR_unicode:
            return PyUnicode_FromString("<CatDict, of str>");

        case CR_bool:
            return PyUnicode_FromString("<CatDict, of bool>");

        case CR_long:
            return PyUnicode_FromString("<CatDict, of int>");

        case CR_float:
            return PyUnicode_FromString("<CatDict, of float>");

        case CR_list:
            return PyUnicode_FromString("<CatDict, of list>");

        case CR_tuple:
            return PyUnicode_FromString("<CatDict, of tuple>");

        case CR_dict:
            return PyUnicode_FromString("<CatDict, of dict>");

        case CR_set:
            return PyUnicode_FromString("<CatDict, of set>");

        default:
            SET_DEFAULT_ERR;
            return NULL;
    }
}
