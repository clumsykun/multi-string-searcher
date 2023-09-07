#include "dtypes.h"
#include "cd_float.h"


int
cd_f_set(catdict *cd, PyObject *key, PyObject *item)
{
    PyObject *o;

    // support del operation
    if (item == NULL)
        return PyDict_DelItem(cd->dict_float, key);

    if (PyBool_Check(item) || PyLong_CheckExact(item) || PyFloat_CheckExact(item)) {
        o = PyNumber_Float(item);

        if (o == NULL) {
            SET_DEFAULT_ERR;
            return -1;
        }
    }
    else {
        PyErr_SetString(PyExc_TypeError, "Except 'bool', 'int', or 'float' value.");
        return -1;
    };

    return PyDict_SetItem(cd->dict_float, key, o);
}
