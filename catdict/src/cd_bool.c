#include "dtypes.h"
#include "cd_bool.h"


PyObject *
cd_b_set(catdict *cd, PyObject *key, PyObject *item)
{
    PyObject *o;

    if (PyBool_Check(item) || PyLong_CheckExact(item) || PyFloat_CheckExact(item)) {

        switch (PyObject_Not(item)) {
            case 0:
                o = Py_True;
                Py_INCREF(o);
                break;

            case 1:
                o = Py_False;
                Py_INCREF(o);
                break;

            default:
                Py_RETURN_ERR;
        }
    }
    else {
        PyErr_SetString(PyExc_TypeError, "Except 'bool', 'int', or 'float' value.");
        return NULL;
    };

    if (cd->dict_bool == NULL) {
        cd->dict_bool = PyDict_New();

        // Error handling.
        if (cd->dict_bool == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(cd->dict_bool, key, o) < 0) {

        if (PyObject_Hash(key) == -1)
            Py_RETURN_HASH_ERR;

        Py_RETURN_ERR;
    }

    Py_RETURN_NONE;
}
