#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "searcher.h"

#define PLACEHOLDER "placeholder"

/* =================================================================================================
 * Get version
 **/

static PyObject *
placeholder(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    printf("(%s)\n", PLACEHOLDER);
    Py_RETURN_NONE;
}

/* =================================================================================================
 * Define type _CatDict.
 **/

// static PyMethodDef Searcher_methods[] = {
//     {"index_add",  (PyCFunction)Searcher_index_add,  METH_VARARGS, "Searcher_index_size"},
//     {NULL},
// };

// static PyMappingMethods Searcher_mapping = {
//     .mp_length = (lenfunc)Searcher_length,
// };

static PyGetSetDef Searcher_getset[] = {
    {"num_targets", (getter)Searcher_num_targets, (setter)Searcher_ignore, "Return number of targets.", NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject type_Searcher = {
    .ob_base      = PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name      = "mss.Searcher",
    .tp_doc       = PyDoc_STR("Multi-string searcher."),
    .tp_basicsize = sizeof(Searcher),
    .tp_itemsize  = 0,
    .tp_flags     = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new       =              Searcher_new,
    .tp_init      = (initproc)   Searcher_init,
    .tp_dealloc   = (destructor) Searcher_dealloc,
    .tp_getset    =              Searcher_getset,
    // .tp_str       = (reprfunc)   Searcher_str,
    // .tp_repr      = (reprfunc)   Searcher_str,
    // .tp_methods   =              Searcher_methods,
    // .tp_as_mapping =            &Searcher_mapping,
};

/* =================================================================================================
 * Define module.
 **/

static PyMethodDef methods_module[] = {
    {"placeholder", placeholder, METH_VARARGS, "placeholder"},
    {NULL},
};

static PyModuleDef module_mss = {
    PyModuleDef_HEAD_INIT,
    .m_name    = "mss",
    .m_doc     = "Multi-string searcher.",
    .m_size    = -1,
    .m_methods = methods_module,
};

PyMODINIT_FUNC PyInit__mss(void)
{
    PyObject *m;

    if (PyType_Ready(&type_Searcher) < 0)
        return NULL;

    m = PyModule_Create(&module_mss);

    if (m == NULL)
        return NULL;

    Py_INCREF(&type_Searcher);
    if (PyModule_AddObject(m, "Searcher", (PyObject *) &type_Searcher) < 0) {
        Py_DECREF(&type_Searcher);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
