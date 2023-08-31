#include "cd_unicode.h"
#include "cd_bool.h"
#include "cd_long.h"
#include "cd_float.h"
#include "cd_list.h"
#include "cd_tuple.h"
#include "cd_dict.h"
#include "cd_set.h"
#include "catdict.h"


PyObject *
cd_assign(catdict *cd, PyObject *args)
{
    PyObject *key, *item;

    if (!PyArg_ParseTuple(args, "OO", &key, &item))
        return NULL;

    switch (cd->cursor) {
        case CR_NULL:
            PyErr_SetString(
                PyExc_ValueError,
                "Specify data type before assign!\n"
                "For example, assign float value 3.14 to CatDict instance 'd' with key 'pi', "
                "use code:\n"
                ">>> d.float.assign('pi', 3.14)"
            );
            return NULL;

        case CR_unicode:
            return cd_u_set(cd, key, item);

        case CR_bool:
            return cd_b_set(cd, key, item);

        case CR_long:
            return cd_i_set(cd, key, item);

        case CR_float:
            return cd_f_set(cd, key, item);

        case CR_list:
            return cd_l_set(cd, key, item);

        case CR_tuple:
            return cd_t_set(cd, key, item);

        case CR_dict:
            return cd_d_set(cd, key, item);

        case CR_set:
            return cd_s_set(cd, key, item);

        default:
            Py_RETURN_CR_ERR;
    }
}

PyObject *
cd_access(catdict *cd, PyObject *args)
{
    PyObject *dict, *key, *item;

    if (!PyArg_ParseTuple(args, "O", &key))
        return NULL;

    switch (cd->cursor) {
        case CR_NULL:
            PyErr_SetString(PyExc_ValueError, "No data available!");
            return NULL;

        case CR_unicode:
            dict = cd->dict_unicode;
            break;

        case CR_bool:
            dict = cd->dict_bool;
            break;

        case CR_long:
            dict = cd->dict_long;
            break;

        case CR_float:
            dict = cd->dict_float;
            break;

        case CR_list:
            dict = cd->dict_list;
            break;

        case CR_tuple:
            dict = cd->dict_tuple;
            break;

        case CR_dict:
            dict = cd->dict_dict;
            break;

        case CR_set:
            dict = cd->dict_set;
            break;

        default:
            Py_RETURN_CR_ERR;
    }

    if (dict == NULL) {
        PyErr_SetObject(PyExc_KeyError, key);
        return NULL;
    }

    item = PyDict_GetItemWithError(dict, key);
    Py_XINCREF(item);
    return item;
}

PyObject *
cd_status(catdict *cd, PyObject *Py_UNUSED(ignored))
{
    printf("Status of CatDict(%p):\n", cd);

    if (cd->dict_unicode)
        printf("    str   variables (%ld)\n", PyDict_Size(cd->dict_unicode));

    if (cd->dict_bool)
        printf("    bool  variables (%ld)\n", PyDict_Size(cd->dict_bool));

    if (cd->dict_long)
        printf("    int   variables (%ld)\n", PyDict_Size(cd->dict_long));

    if (cd->dict_float)
        printf("    float variables (%ld)\n", PyDict_Size(cd->dict_float));

    if (cd->dict_list)
        printf("    list  variables (%ld)\n", PyDict_Size(cd->dict_list));

    if (cd->dict_tuple)
        printf("    tuple variables (%ld)\n", PyDict_Size(cd->dict_tuple));

    if (cd->dict_dict)
        printf("    dict  variables (%ld)\n", PyDict_Size(cd->dict_dict));

    if (cd->dict_set)
        printf("    set   variables (%ld)\n", PyDict_Size(cd->dict_set));

    Py_RETURN_NONE;
}

PyObject *
cd_to_dict(catdict *cd, PyObject *Py_UNUSED(ignored))
{
    PyObject *o, *ret = PyDict_New();

    if (ret == NULL)
        Py_RETURN_ERR;

    if (cd->dict_unicode) {
        o = PyDict_Copy(cd->dict_unicode);
        if (PyDict_SetItemString(ret, "str", o) < 0) {
            Py_XDECREF(o);
            Py_RETURN_ERR;
        }
        Py_DECREF(o);
    }

    if (cd->dict_bool) {
        o = PyDict_Copy(cd->dict_bool);
        if (PyDict_SetItemString(ret, "bool", o) < 0) {
            Py_XDECREF(o);
            Py_RETURN_ERR;
        }
        Py_DECREF(o);
    }

    if (cd->dict_long) {
        o = PyDict_Copy(cd->dict_long);
        if (PyDict_SetItemString(ret, "int", o) < 0) {
            Py_XDECREF(o);
            Py_RETURN_ERR;
        }
        Py_DECREF(o);
    }

    if (cd->dict_float) {
        o = PyDict_Copy(cd->dict_float);
        if (PyDict_SetItemString(ret, "float", o) < 0) {
            Py_XDECREF(o);
            Py_RETURN_ERR;
        }
        Py_DECREF(o);
    }

    if (cd->dict_list) {
        o = PyDict_Copy(cd->dict_list);
        if (PyDict_SetItemString(ret, "list", o) < 0) {
            Py_XDECREF(o);
            Py_RETURN_ERR;
        }
        Py_DECREF(o);
    }

    if (cd->dict_tuple) {
        o = PyDict_Copy(cd->dict_tuple);
        if (PyDict_SetItemString(ret, "tuple", o) < 0) {
            Py_XDECREF(o);
            Py_RETURN_ERR;
        }
        Py_DECREF(o);
    }

    if (cd->dict_dict) {
        o = PyDict_Copy(cd->dict_dict);
        if (PyDict_SetItemString(ret, "dict", o) < 0) {
            Py_XDECREF(o);
            Py_RETURN_ERR;
        }
        Py_DECREF(o);
    }

    if (cd->dict_set) {
        o = PyDict_Copy(cd->dict_set);
        if (PyDict_SetItemString(ret, "set", o) < 0) {
            Py_XDECREF(o);
            Py_RETURN_ERR;
        }
        Py_DECREF(o);
    }

    return ret;
}

PyObject *
cd_switch_unicode(catdict *cd, void *closure)
{
    Py_INCREF(cd);
    cd->cursor = CR_unicode;
    return (PyObject *) cd;
}

PyObject *
cd_switch_bool(catdict *cd, void *closure)
{
    Py_INCREF(cd);
    cd->cursor = CR_bool;
    return (PyObject *) cd;
}

PyObject *
cd_switch_long(catdict *cd, void *closure)
{
    Py_INCREF(cd);
    cd->cursor = CR_long;
    return (PyObject *) cd;
}

PyObject *
cd_switch_float(catdict *cd, void *closure)
{
    Py_INCREF(cd);
    cd->cursor = CR_float;
    return (PyObject *) cd;
}

PyObject *
cd_switch_list(catdict *cd, void *closure)
{
    Py_INCREF(cd);
    cd->cursor = CR_list;
    return (PyObject *) cd;
}

PyObject *
cd_switch_tuple(catdict *cd, void *closure)
{
    Py_INCREF(cd);
    cd->cursor = CR_tuple;
    return (PyObject *) cd;
}

PyObject *
cd_switch_dict(catdict *cd, void *closure)
{
    Py_INCREF(cd);
    cd->cursor = CR_dict;
    return (PyObject *) cd;
}

PyObject *
cd_switch_set(catdict *cd, void *closure)
{
    Py_INCREF(cd);
    cd->cursor = CR_set;
    return (PyObject *) cd;
}

int
cd_ignore(catdict *self, PyObject *value, void *closure)
{
    return 0;
}
