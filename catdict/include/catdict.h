#ifndef CATDICT
#define CATDICT
#include "dtypes.h"

/** ================================================================================================
 *  dict-like functions
 */

int
cd_ass_subscript(catdict *cd, PyObject *key, PyObject *item);

PyObject *
cd_subscript(catdict *cd, PyObject *key);

PyObject *
cd_keys(catdict *cd);

PyObject *
cd_values(catdict *cd);

Py_ssize_t
cd_length(catdict *cd);

/** ================================================================================================
 *  basic tools
 */

PyObject *
cd_to_dict(catdict *cd);

PyObject *
cd_status(catdict *cd);

int
cd_ignore(catdict *self, PyObject *value, void *closure);

/** ================================================================================================
 *  switch cursor
 */

PyObject *
cd_switch_unicode(catdict *cd, void *closure);

PyObject *
cd_switch_bool(catdict *cd, void *closure);

PyObject *
cd_switch_long(catdict *cd, void *closure);

PyObject *
cd_switch_float(catdict *cd, void *closure);

PyObject *
cd_switch_list(catdict *cd, void *closure);

PyObject *
cd_switch_tuple(catdict *cd, void *closure);

PyObject *
cd_switch_dict(catdict *cd, void *closure);

PyObject *
cd_switch_set(catdict *cd, void *closure);

#endif /* CATDICT */
