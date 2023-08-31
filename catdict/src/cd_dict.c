#include "dtypes.h"
#include "cd_dict.h"


PyObject *
cd_d_set(catdict *cd, PyObject *key, PyObject *item)
{
    if (!PyDict_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'dict' object");
        return NULL;
    }

    if (cd->dict_dict == NULL) {
        cd->dict_dict = PyDict_New();

        // Error handling.
        if (cd->dict_dict == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(cd->dict_dict, key, item) < 0) {

        if (PyObject_Hash(key) == -1)
            Py_RETURN_HASH_ERR;

        Py_RETURN_ERR;
    }

    Py_RETURN_NONE;
}
