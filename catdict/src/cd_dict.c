#include "dtypes.h"
#include "cd_dict.h"


int
cd_d_set(catdict *cd, PyObject *key, PyObject *item)
{
    // support del operation
    if (item == NULL)
        return PyDict_DelItem(cd->dict_dict, key);

    if (!PyDict_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'dict' object");
        return -1;
    }

    return PyDict_SetItem(cd->dict_dict, key, item);
}
