#include "catdict.h"
#include "cd_unicode.h"


PyObject *
db_u_set(database *db, PyObject *args)
{
    PyObject *key, *item;

    if (!PyArg_ParseTuple(args, "OO", &key, &item))
        return NULL;

    if (!PyUnicode_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'str' object");
        return NULL;
    }

    if (db->dict_unicode == NULL) {
        db->dict_unicode = PyDict_New();

        // Error handling.
        if (db->dict_unicode == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(db->dict_unicode, key, item) < 0)
        return NULL;
    else 
        Py_RETURN_NONE;
}

PyObject *
db_u_get(database *db, PyObject *args)
{
    PyObject *key;

    if (!PyArg_ParseTuple(args, "O", &key))
        return NULL;

    if (db->dict_unicode == NULL)
        Py_RETURN_ERR;
    
    PyObject *o = PyDict_GetItemWithError(db->dict_unicode, key);
    Py_INCREF(o);

    if (o == NULL)
        PyErr_SetObject(PyExc_KeyError, key);

    return o;
}
