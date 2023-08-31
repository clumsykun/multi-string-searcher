#include "dtypes.h"
#include "cd_list.h"


PyObject *
cd_l_set(catdict *cd, PyObject *key, PyObject *item)
{
    if (!PyList_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'list' object");
        return NULL;
    }

    if (cd->dict_list == NULL) {
        cd->dict_list = PyDict_New();

        // Error handling.
        if (cd->dict_list == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(cd->dict_list, key, item) < 0) {

        if (PyObject_Hash(key) == -1)
            Py_RETURN_HASH_ERR;

        Py_RETURN_ERR;
    }

    Py_RETURN_NONE;
}
