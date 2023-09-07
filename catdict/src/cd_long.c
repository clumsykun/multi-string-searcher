#include "dtypes.h"
#include "cd_long.h"


int
cd_i_set(catdict *cd, PyObject *key, PyObject *item)
{
    PyObject *o;

    // support del operation
    if (item == NULL)
        return PyDict_DelItem(cd->dict_long, key);

    if (PyBool_Check(item) || PyLong_CheckExact(item) || PyFloat_CheckExact(item)) {
        o = PyNumber_Long(item);

        if (o == NULL) {
            SET_DEFAULT_ERR;
            return -1;
        };
    }
    else {
        PyErr_SetString(PyExc_TypeError, "Except 'bool', 'int', or 'float' value.");
        return -1;
    };

    return PyDict_SetItem(cd->dict_long, key, o);
}
