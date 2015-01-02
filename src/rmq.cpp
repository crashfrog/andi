#include "rmq.h"
#include <RMQ.hpp>
#include <RMQ_n_1_improved.hpp>

size_t rmq_init( esa_t* C ){
	C->rmq_lcp = (void*)(new RMQ_n_1_improved(C->LCP, C->len));
	return 0;
}

void rmq_free( esa_t* C){
	RMQ* ptr = (RMQ*)C->rmq_lcp;
	delete ptr;
}

size_t rmq( const esa_t* C, size_t i, size_t j){

	if(i >= j) return i;

	size_t n = j - i;

	if( n <= 16) {
		int* LCP = C->LCP;
		size_t m = i;
		size_t v = LCP[i];

		i++;
		LCP += i;

		for(;i <= j; LCP++, i++){
			if( *LCP < v){
				v = *LCP;
				m = i;
			}
		}
		return m;
	}

	RMQ* ptr = (RMQ*)C->rmq_lcp;
	return ptr->query(i,j);
}
