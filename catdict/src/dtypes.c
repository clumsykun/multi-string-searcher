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
        cd->dict_unicode = NULL;
        cd->dict_bool    = NULL;
        cd->dict_long    = NULL;
        cd->dict_float   = NULL;
        cd->dict_list    = NULL;
        cd->dict_tuple   = NULL;
        cd->dict_dict    = NULL;
        cd->dict_set     = NULL;
        cd->cursor       = 0;
    }

    return (PyObject *) cd;
}

int
cd_init(catdict *cd, PyObject *args, PyObject *kwds)
{
    return 0;
}

void
cd_dealloc(catdict *cd)
{
    Py_XDECREF(cd->dict_unicode);
    Py_XDECREF(cd->dict_bool);
    Py_XDECREF(cd->dict_long);
    Py_XDECREF(cd->dict_float);
    Py_XDECREF(cd->dict_list);
    Py_XDECREF(cd->dict_tuple);
    Py_XDECREF(cd->dict_dict);
    Py_XDECREF(cd->dict_set);
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
            Py_RETURN_ERR;
    }
}
