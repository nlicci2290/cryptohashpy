/*
* https://opensource.apple.com/source/cvs/cvs-19/cvs/lib/md5.h
*/

#ifndef MD5_H
#define MD5_H

#include <string.h>

/* Unlike previous versions of this code, uint32 need not be exactly
   32 bits, merely 32 bits or more.  Choosing a data type which is 32
   bits instead of 64 is not important; speed is considerably more
   important.  ANSI guarantees that "unsigned long" will be big enough,
   and always using it seems to have few disadvantages.  */
typedef unsigned long uint32;

struct MD5Context {
	uint32 buf[4];
	uint32 bits[2];
	unsigned char in[64];
};

void MD5Init(struct MD5Context *context);
void MD5Update(struct MD5Context *context, unsigned char const *buf, size_t len);
void MD5Final(unsigned char digest[16], struct MD5Context *context);
void MD5Transform(uint32 buf[4], const unsigned char in[64]);

/*
 * This is needed to make RSAREF happy on some MS-DOS compilers.
 */
typedef struct MD5Context MD5_CTX;

#endif /* !MD5_H */