#include "dtypes.h"
#include "cd_tuple.h"


int
cd_t_set(catdict *cd, PyObject *key, PyObject *item)
{
    // support del operation
    if (item == NULL)
        return PyDict_DelItem(cd->dict_tuple, key);

    if (!PyTuple_CheckExact(item)) {
        PyErr_SetString(PyExc_TypeError, "Except 'tuple' object");
        return -1;
    }

    return PyDict_SetItem(cd->dict_tuple, key, item);
}
