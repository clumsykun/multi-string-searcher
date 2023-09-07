#include "dtypes.h"
#include "cd_list.h"


int
cd_l_set(catdict *cd, PyObject *key, PyObject *item)
{
    // support del operation
    if (item == NULL)
        return PyDict_DelItem(cd->dict_list, key);

    if (!PyList_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'list' object");
        return -1;
    }

    return PyDict_SetItem(cd->dict_list, key, item);
}
