#include "cd_unicode.h"
#include "cd_bool.h"
#include "cd_long.h"
#include "cd_float.h"
#include "cd_list.h"
#include "cd_tuple.h"
#include "cd_dict.h"
#include "cd_set.h"
#include "catdict.h"


/** ================================================================================================
 *  dict-like functions
 */

int
cd_ass_subscript(catdict *cd, PyObject *key, PyObject *item)
{
    switch (cd->cursor) {
        case CR_NULL:
            SET_CR_NULL;
            return -1;

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
            SET_CR_ERR;
            return -1;
    }
}

PyObject *
cd_subscript(catdict *cd, PyObject *key)
{
    PyObject *dict, *item;

    switch (cd->cursor) {
        case CR_NULL:
            SET_CR_NULL;
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
            SET_CR_ERR;
            return NULL;
    }

    item = PyDict_GetItemWithError(dict, key);

    if (item == NULL) {
        if (PyErr_Occurred() == NULL)  // key error
            PyErr_SetObject(PyExc_KeyError, key);

        return NULL;
    }

    Py_INCREF(item);
    return item;
}

PyObject *
cd_keys(catdict *cd)
{
    switch (cd->cursor) {

        case CR_NULL:
            SET_CR_NULL;
            return NULL;

        case CR_unicode:
            return PyDict_Keys(cd->dict_unicode);

        case CR_bool:
            return PyDict_Keys(cd->dict_bool);

        case CR_long:
            return PyDict_Keys(cd->dict_long);

        case CR_float:
            return PyDict_Keys(cd->dict_float);

        case CR_list:
            return PyDict_Keys(cd->dict_list);

        case CR_tuple:
            return PyDict_Keys(cd->dict_tuple);

        case CR_dict:
            return PyDict_Keys(cd->dict_dict);

        case CR_set:
            return PyDict_Keys(cd->dict_set);

        default:
            SET_CR_ERR;
            return NULL;
    }
}

PyObject *
cd_values(catdict *cd)
{
    switch (cd->cursor) {

        case CR_NULL:
            SET_CR_NULL;
            return NULL;

        case CR_unicode:
            return PyDict_Values(cd->dict_unicode);

        case CR_bool:
            return PyDict_Values(cd->dict_bool);

        case CR_long:
            return PyDict_Values(cd->dict_long);

        case CR_float:
            return PyDict_Values(cd->dict_float);

        case CR_list:
            return PyDict_Values(cd->dict_list);

        case CR_tuple:
            return PyDict_Values(cd->dict_tuple);

        case CR_dict:
            return PyDict_Values(cd->dict_dict);

        case CR_set:
            return PyDict_Values(cd->dict_set);

        default:
            SET_CR_ERR;
            return NULL;
    }
}

Py_ssize_t
cd_length(catdict *cd)
{
    switch (cd->cursor) {
        case CR_NULL:
            SET_CR_NULL;
            return -1;

        case CR_unicode:
            return PyDict_Size(cd->dict_unicode);

        case CR_bool:
            return PyDict_Size(cd->dict_bool);

        case CR_long:
            return PyDict_Size(cd->dict_long);

        case CR_float:
            return PyDict_Size(cd->dict_float);

        case CR_list:
            return PyDict_Size(cd->dict_list);

        case CR_tuple:
            return PyDict_Size(cd->dict_tuple);

        case CR_dict:
            return PyDict_Size(cd->dict_dict);

        case CR_set:
            return PyDict_Size(cd->dict_set);

        default:
            SET_CR_ERR;
            return -1;
    }
}

/** ================================================================================================
 *  basic tools
 */

PyObject *
cd_to_dict(catdict *cd)
{
    PyObject *o, *ret = PyDict_New();

    if (ret == NULL) {
        SET_DEFAULT_ERR;
        return NULL;
    }

    if (PyDict_Size(cd->dict_unicode) > 0) {
        o = PyDict_Copy(cd->dict_unicode);
        if (PyDict_SetItemString(ret, "str", o) < 0) {
            Py_XDECREF(o);
            SET_DEFAULT_ERR;
            return NULL;
        }
        Py_DECREF(o);
    }

    if (PyDict_Size(cd->dict_bool) > 0) {
        o = PyDict_Copy(cd->dict_bool);
        if (PyDict_SetItemString(ret, "bool", o) < 0) {
            Py_XDECREF(o);
            SET_DEFAULT_ERR;
            return NULL;
        }
        Py_DECREF(o);
    }

    if (PyDict_Size(cd->dict_long) > 0) {
        o = PyDict_Copy(cd->dict_long);
        if (PyDict_SetItemString(ret, "int", o) < 0) {
            Py_XDECREF(o);
            SET_DEFAULT_ERR;
            return NULL;
        }
        Py_DECREF(o);
    }

    if (PyDict_Size(cd->dict_float) > 0) {
        o = PyDict_Copy(cd->dict_float);
        if (PyDict_SetItemString(ret, "float", o) < 0) {
            Py_XDECREF(o);
            SET_DEFAULT_ERR;
            return NULL;
        }
        Py_DECREF(o);
    }

    if (PyDict_Size(cd->dict_list) > 0) {
        o = PyDict_Copy(cd->dict_list);
        if (PyDict_SetItemString(ret, "list", o) < 0) {
            Py_XDECREF(o);
            SET_DEFAULT_ERR;
            return NULL;
        }
        Py_DECREF(o);
    }

    if (PyDict_Size(cd->dict_tuple) > 0) {
        o = PyDict_Copy(cd->dict_tuple);
        if (PyDict_SetItemString(ret, "tuple", o) < 0) {
            Py_XDECREF(o);
            SET_DEFAULT_ERR;
            return NULL;
        }
        Py_DECREF(o);
    }

    if (PyDict_Size(cd->dict_dict) > 0) {
        o = PyDict_Copy(cd->dict_dict);
        if (PyDict_SetItemString(ret, "dict", o) < 0) {
            Py_XDECREF(o);
            SET_DEFAULT_ERR;
            return NULL;
        }
        Py_DECREF(o);
    }

    if (PyDict_Size(cd->dict_set) > 0) {
        o = PyDict_Copy(cd->dict_set);
        if (PyDict_SetItemString(ret, "set", o) < 0) {
            Py_XDECREF(o);
            SET_DEFAULT_ERR;
            return NULL;
        }
        Py_DECREF(o);
    }

    return ret;
}

PyObject *
cd_status(catdict *cd)
{
    printf("Status of CatDict(%p):\n", cd);

    if (PyDict_Size(cd->dict_unicode) > 0)
        printf("    str   variables (%ld)\n", PyDict_Size(cd->dict_unicode));

    if (PyDict_Size(cd->dict_bool) > 0)
        printf("    bool  variables (%ld)\n", PyDict_Size(cd->dict_bool));

    if (PyDict_Size(cd->dict_long) > 0)
        printf("    int   variables (%ld)\n", PyDict_Size(cd->dict_long));

    if (PyDict_Size(cd->dict_float) > 0)
        printf("    float variables (%ld)\n", PyDict_Size(cd->dict_float));

    if (PyDict_Size(cd->dict_list) > 0)
        printf("    list  variables (%ld)\n", PyDict_Size(cd->dict_list));

    if (PyDict_Size(cd->dict_tuple) > 0)
        printf("    tuple variables (%ld)\n", PyDict_Size(cd->dict_tuple));

    if (PyDict_Size(cd->dict_dict) > 0)
        printf("    dict  variables (%ld)\n", PyDict_Size(cd->dict_dict));

    if (PyDict_Size(cd->dict_set) > 0)
        printf("    set   variables (%ld)\n", PyDict_Size(cd->dict_set));

    Py_RETURN_NONE;
}

int
cd_ignore(catdict *self, PyObject *value, void *closure)
{
    return 0;
}

/** ================================================================================================
 *  switch cursor
 */

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
