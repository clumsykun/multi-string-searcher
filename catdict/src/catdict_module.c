#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "catdict.h"
#include "cd_long.h"
#include "cd_float.h"
#include "cd_unicode.h"
#include "cd_list.h"
#include "cd_set.h"

#define CATDICT_VERSION "0.0.1"

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
 * Define type CatDict.
 **/

static PyMethodDef methods_catdict[] = {
    {"iSet", (PyCFunction) db_i_set, METH_VARARGS, "Assign 'int' value to database."},
    {"iGet", (PyCFunction) db_i_get, METH_VARARGS, "Access 'int' value from database."},
    {"fSet", (PyCFunction) db_f_set, METH_VARARGS, "Assign 'float' value to database."},
    {"fGet", (PyCFunction) db_f_get, METH_VARARGS, "Access 'float' value from database."},
    {"uSet", (PyCFunction) db_u_set, METH_VARARGS, "Assign 'unicode' to database."},
    {"uGet", (PyCFunction) db_u_get, METH_VARARGS, "Access 'unicode' from database."}, 
    {"lSet", (PyCFunction) db_l_set, METH_VARARGS, "Assign 'list' object to database."},
    {"lGet", (PyCFunction) db_l_get, METH_VARARGS, "Access 'list' object from database."}, 
    {"sSet", (PyCFunction) db_s_set, METH_VARARGS, "Assign 'set' object to database."},
    {"sGet", (PyCFunction) db_s_get, METH_VARARGS, "Access 'set' object from database."},
    {"display",  (PyCFunction) db_display, METH_NOARGS, "Get status of database."},
    {"as_dict",  (PyCFunction) db_as_dict, METH_NOARGS, "Convert database to Python Dict."},
    {NULL},
};

static PyTypeObject type_catdict = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "CatDict",
    .tp_doc = PyDoc_STR("Categorical dict."),
    .tp_basicsize = sizeof(database),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = db_create,
    .tp_init = (initproc) db_init,
    .tp_methods = methods_catdict,
    .tp_dealloc = (destructor)db_delete,
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
    .m_name    = "catdict",
    .m_doc     = "Package of organize temporary data.",
    .m_size    = -1,
    .m_methods = methods_module,
};

PyMODINIT_FUNC PyInit_catdict(void)
{
    PyObject *m;

    if (PyType_Ready(&type_catdict) < 0)
        return NULL;

    m = PyModule_Create(&module_catdict);

    if (m == NULL)
        return NULL;

    Py_INCREF(&type_catdict);
    if (PyModule_AddObject(m, "CatDict", (PyObject *) &type_catdict) < 0) {
        Py_DECREF(&type_catdict);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
