#include "main_cryptohash.h"
#include "md5.h"

#ifdef WIN32
static __inline unsigned char to_str(unsigned char input) {
#else
static inline unsigned char to_str(unsigned char input) {
#endif
	if (input < 10) {
		input += 48;
	}
	else {
		input += 55;
	}

	return input;
}

PyObject *cryptohashMd5(PyObject *self, PyObject *args)
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

	if (!size) {
		retval = Py_BuildValue("s", "D41D8CD98F00B204E9800998ECF8427E");

		return retval;
	}

	memset(checksum, 0, sizeof(checksum));
	memset(retbuf, 0, sizeof(retbuf));

	MD5Init(&md5Context);
	MD5Update(&md5Context, (const unsigned char *) inputStr, size);
	MD5Final(checksum, &md5Context);

	// Convert hex value to a char
	// For example, if we have 0x9 we convert that to the char '9'
	for (i = 0, j = 0; (j < 16 && i < 32); j++, i += 2) {
		retbuf[i] = to_str((checksum[j] & 0xf0) >> 4);

		if (i + 1 < 32) {
			retbuf[i + 1] = to_str(checksum[j] & 0x0f);
		}
		else {
			break;
		}
	}

	retval = Py_BuildValue("s", retbuf);

	return retval;
}