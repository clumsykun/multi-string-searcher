#include "dtypes.h"
#include "cd_unicode.h"


PyObject *
cd_u_set(catdict *cd, PyObject *key, PyObject *item)
{
    if (!PyUnicode_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'str' object");
        return NULL;
    }

    if (cd->dict_unicode == NULL) {
        cd->dict_unicode = PyDict_New();

        // Error handling.
        if (cd->dict_unicode == NULL)
            Py_RETURN_ERR;
    }

    if (PyDict_SetItem(cd->dict_unicode, key, item) < 0) {

        if (PyObject_Hash(key) == -1)
            Py_RETURN_HASH_ERR;

        Py_RETURN_ERR;
    }

    Py_RETURN_NONE;
}
