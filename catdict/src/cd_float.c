#include "catdict.h"
#include "cd_float.h"


PyObject *
db_f_set(database *db, PyObject *args)
{
    PyObject *key;
    double item;

    if (!PyArg_ParseTuple(args, "Od", &key, &item))
        return NULL;

    if (db->dict_float == NULL) {
        db->dict_float = PyDict_New();

        // Error handling.
        if (db->dict_float == NULL) {
            SET_DEFAULT_ERR;
            return NULL;
        }
    }

    PyObject *o = PyFloat_FromDouble(item);
    if (o == NULL) {
        SET_DEFAULT_ERR;
        return NULL;
    }

    if (PyDict_SetItem(db->dict_float, key, o) < 0)
        return NULL;
    else 
        Py_RETURN_NONE;
}

PyObject *
db_f_get(database *db, PyObject *args)
{
    PyObject *key;

    if (!PyArg_ParseTuple(args, "O", &key))
        return NULL;

    PyObject *o = PyDict_GetItemWithError(db->dict_float, key);
    Py_INCREF(o);

    if (o == NULL) {
        PyErr_SetObject(PyExc_KeyError, key);
        return NULL;
    }

    return o;
}
