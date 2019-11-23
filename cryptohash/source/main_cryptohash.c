#include "main_cryptohash.h"
#include "md5_py.h"

#define MODULE_NAME "cryptohashpy"
#define MODULE_DESC "Commonly used hash functions"

PyObject *cryptoHashError = NULL;

/* Module method table */
static PyMethodDef cryptohashFunctions[] =
{
	{"md5", cryptohashMd5, METH_VARARGS, "Calculates and returns md5 checksum"},
	{ NULL, NULL, 0, NULL}
};

/* Module structure */
#if PY_MAJOR_VERSION >= 3
	static struct PyModuleDef cryptohashModuleDef =
	{
		PyModuleDef_HEAD_INIT,
		MODULE_NAME, /* name of module */
		MODULE_DESC, /* Doc string (may be NULL) */
		-1,					/* Size of per-interpreter state or -1 */
		cryptohashFunctions, /* Method table */
		NULL,                /* m_reload */
		NULL,                /* m_traverse */
		NULL,                /* m_clear */
		NULL,                /* m_free */
	};
#endif

#if PY_MAJOR_VERSION >= 3
#define PY_INIT_ERR return NULL
#else
#define PY_INIT_ERR return
#endif

/* Module initialization function */
PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
PyInit_cryptohashpy()
#else
initcryptohashpy()
#endif
{
	PyObject *module = NULL;

#if PY_MAJOR_VERSION >= 3
	module = PyModule_Create(&cryptohashModuleDef);
#else
	module = Py_InitModule3(MODULE_NAME, cryptohashFunctions, MODULE_DESC);
#endif

	if (!module) {
		PY_INIT_ERR;
	}

	cryptoHashError = PyErr_NewException("cryptohashpy.error", NULL, NULL);

	Py_XINCREF(cryptoHashError);

	if (PyModule_AddObject(module, "error", cryptoHashError) < 0) {
		Py_XDECREF(cryptoHashError);
		Py_CLEAR(cryptoHashError);
		Py_DECREF(module);
		PY_INIT_ERR;
	}

#if PY_MAJOR_VERSION >= 3
	return module;
#endif
}
