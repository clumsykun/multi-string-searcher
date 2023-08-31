#include "dtypes.h"
#include "cd_set.h"


PyObject *
cd_s_set(catdict *cd, PyObject *key, PyObject *item)
{
    if (!PySet_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'set' object");
        return NULL;
    }

    if (cd->dict_set == NULL) {
        cd->dict_set = PyDict_New();

        // Error handling.
        if (cd->dict_set == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(cd->dict_set, key, item) < 0) {

        if (PyObject_Hash(key) == -1)
            Py_RETURN_HASH_ERR;

        Py_RETURN_ERR;
    }

    Py_RETURN_NONE;
}
