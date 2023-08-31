#include "dtypes.h"
#include "cd_long.h"


PyObject *
cd_i_set(catdict *cd, PyObject *key, PyObject *item)
{
    PyObject *o;

    if (PyBool_Check(item) || PyLong_CheckExact(item) || PyFloat_CheckExact(item)) {
        o = PyNumber_Long(item);

        if (o == NULL)
            Py_RETURN_ERR;
    }
    else {
        PyErr_SetString(PyExc_TypeError, "Except 'bool', 'int', or 'float' value.");
        return NULL;
    };

    if (cd->dict_long == NULL) {
        cd->dict_long = PyDict_New();

        // Error handling.
        if (cd->dict_long == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(cd->dict_long, key, o) < 0) {

        if (PyObject_Hash(key) == -1)
            Py_RETURN_HASH_ERR;

        Py_RETURN_ERR;
    }

    Py_RETURN_NONE;
}
