#include "catdict.h"
#include "cd_list.h"


PyObject *
db_l_set(database *db, PyObject *args)
{
    PyObject *key, *item;

    if (!PyArg_ParseTuple(args, "OO", &key, &item))
        return NULL;

    if (!PyList_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'list' object");
        return NULL;
    }

    if (db->dict_list == NULL) {
        db->dict_list = PyDict_New();

        // Error handling.
        if (db->dict_list == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(db->dict_list, key, item) < 0)
        return NULL;
    else 
        Py_RETURN_NONE;
}

PyObject *
db_l_get(database *db, PyObject *args)
{
    PyObject *key;

    if (!PyArg_ParseTuple(args, "O", &key))
        return NULL;

    PyObject *o = PyDict_GetItemWithError(db->dict_list, key);
    Py_INCREF(o);

    if (o == NULL) {
        PyErr_SetObject(PyExc_KeyError, key);
        return NULL;
    }

    return o;
}
