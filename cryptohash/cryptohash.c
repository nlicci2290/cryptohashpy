#define PY_SSIZE_T_CLEAN size_t

#include <Python.h>
#include "md5.h"

static PyObject *cryptoHashError;
#define MODULE_NAME "cryptohashpy"
#define MODULE_DESC "Commonly used hash functions"

static unsigned char toStr(unsigned char input) {
	if (input < 10) {
		input += 48;
	}
	else {
		input += 55;
	}

	return input;
}

static PyObject *cryptohashMd5(PyObject *self, PyObject *args)
{
	PyObject *retval = NULL;
	const char *inputStr = NULL;
	Py_ssize_t size = 0;
	struct MD5Context md5Context;
	unsigned char retbuf[33];
	unsigned char checksum[16];
	int i, j;

	if (!PyArg_ParseTuple(args, "s#", &inputStr, &size)) {
		return retval;
	}
	
	memset(checksum, 0, sizeof(checksum));
	memset(retbuf, 0, sizeof(retbuf));

	MD5Init(&md5Context);
	MD5Update(&md5Context, (const unsigned char *) inputStr, strlen(inputStr));
	MD5Final(checksum, &md5Context);

	// Convert hex value to a char
	// For example, if we have 0x9 we convert that to the char '9'
	for (i = 0, j = 0; (j < 16 && i < 32); j++, i += 2) {
		retbuf[i] = toStr((checksum[j] & 0xf0) >> 4);

		if (i + 1 < 32) {
			retbuf[i + 1] = toStr(checksum[j] & 0x0f);
		}
		else {
			break;
		}
	}

	retval = Py_BuildValue("s", retbuf);

	return retval;
}

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
