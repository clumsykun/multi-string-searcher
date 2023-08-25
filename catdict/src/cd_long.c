#include "catdict.h"
#include "cd_long.h"


PyObject *
db_i_set(database *db, PyObject *args)
{
    PyObject *key;
    long item;

    if (!PyArg_ParseTuple(args, "Ol", &key, &item))
        return NULL;

    if (db->dict_long == NULL) {
        db->dict_long = PyDict_New();

        // Error handling.
        if (db->dict_long == NULL)
            Py_RETURN_ERR;
    }

    PyObject *o = PyLong_FromLong(item);
    if (o == NULL) 
        Py_RETURN_ERR;

    if (PyDict_SetItem(db->dict_long, key, o) < 0)
        return NULL;
    else 
        Py_RETURN_NONE;
}

PyObject *
db_i_get(database *db, PyObject *args)
{
    PyObject *key;

    if (!PyArg_ParseTuple(args, "O", &key))
        return NULL;

    PyObject *o = PyDict_GetItemWithError(db->dict_long, key);
    Py_INCREF(o);

    if (o == NULL)
        PyErr_SetObject(PyExc_KeyError, key);

    return o;
}
