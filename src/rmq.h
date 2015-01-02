#ifndef _RMQ_H_
#define _RMQ_H_

#include "esa.h"

size_t rmq_init( esa_t* C);
void rmq_free( esa_t* C);
size_t rmq( const esa_t* C, size_t, size_t);

#endif
