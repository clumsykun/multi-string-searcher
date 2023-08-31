#include "dtypes.h"
#include "cd_float.h"


PyObject *
cd_f_set(catdict *cd, PyObject *key, PyObject *item)
{
    PyObject *o;
    if (PyBool_Check(item) || PyLong_CheckExact(item) || PyFloat_CheckExact(item)) {
        o = PyNumber_Float(item);

        if (o == NULL)
            Py_RETURN_ERR;
    }
    else {
        PyErr_SetString(PyExc_TypeError, "Except 'bool', 'int', or 'float' value.");
        return NULL;
    };

    if (cd->dict_float == NULL) {
        cd->dict_float = PyDict_New();

        // Error handling.
        if (cd->dict_float == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(cd->dict_float, key, o) < 0) {

        if (PyObject_Hash(key) == -1)
            Py_RETURN_HASH_ERR;

        Py_RETURN_ERR;
    }

    Py_RETURN_NONE;
}
