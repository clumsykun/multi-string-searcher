#include "catdict.h"

#define CATDICT_VERSION "0.4.3"

/* =================================================================================================
 * Get version
 **/

static PyObject *
version(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    printf("CatDict version: %s.\n", CATDICT_VERSION);
    Py_RETURN_NONE;
}

/* =================================================================================================
 * Define type _CatDict.
 **/

static PyMethodDef cd_methods[] = {
    {"status",  (PyCFunction) cd_status,  METH_NOARGS, "Get status of catdict."},
    {"keys",    (PyCFunction) cd_keys,    METH_NOARGS, "Get keys of catdict."},
    {"values",  (PyCFunction) cd_values,  METH_NOARGS, "Get values of catdict."},
    {"to_dict", (PyCFunction) cd_to_dict, METH_NOARGS, "Convert catdict to Python dict."},
    {NULL},
};

static PyMappingMethods cd_mapping = {
    .mp_subscript     = (binaryfunc)    cd_subscript,
    .mp_ass_subscript = (objobjargproc) cd_ass_subscript,
    .mp_length        = (lenfunc)       cd_length,
};

static PyGetSetDef cd_getset[] = {
    {"str",   (getter) cd_switch_unicode, (setter) cd_ignore, "Switched to str.", NULL},
    {"bool",  (getter) cd_switch_bool,    (setter) cd_ignore, "Switched to bool.", NULL},
    {"int",   (getter) cd_switch_long,    (setter) cd_ignore, "Switched to int.", NULL},
    {"float", (getter) cd_switch_float,   (setter) cd_ignore, "Switched to float.", NULL},
    {"list",  (getter) cd_switch_list,    (setter) cd_ignore, "Switched to list.", NULL},
    {"tuple", (getter) cd_switch_tuple,   (setter) cd_ignore, "Switched to tuple.", NULL},
    {"dict",  (getter) cd_switch_dict,    (setter) cd_ignore, "Switched to dict.", NULL},
    {"set",   (getter) cd_switch_set,     (setter) cd_ignore, "Switched to set.", NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject type_catdict = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name      = "_CatDict",
    .tp_doc       = PyDoc_STR("C implementation of categorical dict."),
    .tp_basicsize = sizeof(catdict),
    .tp_itemsize  = 0,
    .tp_flags     = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new       =              cd_new,
    .tp_init      = (initproc)   cd_init,
    .tp_dealloc   = (destructor) cd_dealloc,
    .tp_str       = (reprfunc)   cd_str,
    .tp_repr      = (reprfunc)   cd_str,
    .tp_methods   =              cd_methods,
    .tp_getset    =              cd_getset,
    .tp_as_mapping =            &cd_mapping,
};

/* =================================================================================================
 * Define module.
 **/

static PyMethodDef methods_module[] = {
    {"version", version, METH_VARARGS, "Get version."},
    {NULL},
};

static PyModuleDef module_catdict = {
    PyModuleDef_HEAD_INIT,
    .m_name    = "_catdict",
    .m_doc     = "Package of organize temporary data.",
    .m_size    = -1,
    .m_methods = methods_module,
};

PyMODINIT_FUNC PyInit_ext(void)
{
    PyObject *m;

    if (PyType_Ready(&type_catdict) < 0)
        return NULL;

    m = PyModule_Create(&module_catdict);

    if (m == NULL)
        return NULL;

    Py_INCREF(&type_catdict);
    if (PyModule_AddObject(m, "_CatDict", (PyObject *) &type_catdict) < 0) {
        Py_DECREF(&type_catdict);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
