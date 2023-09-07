#include "dtypes.h"
#include "cd_set.h"


int
cd_s_set(catdict *cd, PyObject *key, PyObject *item)
{
    // support del operation
    if (item == NULL)
        return PyDict_DelItem(cd->dict_set, key);

    if (!PySet_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'set' object");
        return -1;
    }

    return PyDict_SetItem(cd->dict_set, key, item);
}
