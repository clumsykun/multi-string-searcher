#include "catdict.h"
#include "cd_set.h"


PyObject *
db_s_set(database *db, PyObject *args)
{
    PyObject *key, *item;

    if (!PyArg_ParseTuple(args, "OO", &key, &item))
        return NULL;

    if (!PySet_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'set' object");
        return NULL;
    }

    if (db->dict_set == NULL) {
        db->dict_set = PyDict_New();

        // Error handling.
        if (db->dict_set == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(db->dict_set, key, item) < 0)
        return NULL;
    else 
        Py_RETURN_NONE;
}

PyObject *
db_s_get(database *db, PyObject *args)
{
    PyObject *key;

    if (!PyArg_ParseTuple(args, "O", &key))
        return NULL;

    PyObject *o = PyDict_GetItemWithError(db->dict_set, key);
    Py_INCREF(o);

    if (o == NULL) {
        PyErr_SetObject(PyExc_KeyError, key);
        return NULL;
    }

    return o;
}
