#ifndef DEF_H
#define DEF_H

#include <stddef.h>
#include<stdint.h>
#include <inttypes.h>
#define INT_TYPE_EXT(A,B) A ## B ## _t
#define INT_TYPE(N) INT_TYPE_EXT(uint,N)

#define INT_FORMAT_TYPE_EXT(A,B) A ## B
#define INT_FORMAT_TYPE(N) INT_FORMAT_TYPE_EXT(PRId,N)

#endif
