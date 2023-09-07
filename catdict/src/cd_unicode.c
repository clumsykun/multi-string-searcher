#include "dtypes.h"
#include "cd_unicode.h"


int
cd_u_set(catdict *cd, PyObject *key, PyObject *item)
{
    // support del operation
    if (item == NULL)
        return PyDict_DelItem(cd->dict_unicode, key);

    if (!PyUnicode_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'str' object");
        return -1;
    }

    return PyDict_SetItem(cd->dict_unicode, key, item);
}
