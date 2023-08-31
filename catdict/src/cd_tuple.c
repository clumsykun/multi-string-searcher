#include "dtypes.h"
#include "cd_tuple.h"


PyObject *
cd_t_set(catdict *cd, PyObject *key, PyObject *item)
{
    if (!PyTuple_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'tuple' object");
        return NULL;
    }

    if (cd->dict_tuple == NULL) {
        cd->dict_tuple = PyDict_New();

        // Error handling.
        if (cd->dict_tuple == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(cd->dict_tuple, key, item) < 0) {

        if (PyObject_Hash(key) == -1)
            Py_RETURN_HASH_ERR;

        Py_RETURN_ERR;
    }

    Py_RETURN_NONE;
}
