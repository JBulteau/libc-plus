#ifndef __ASYNCHRONOUS_H
#define __ASYNCHRONOUS_H

#include <pthread.h>
#include "utils.h"

#define async	{														\
					void *__routine(void *task);						\
					pthread_t thread_id;								\
					pthread_create(&thread_id, NULL, &__routine, NULL);	\
					pthread_detach(thread_id);							\
				}														\
				void *__routine(void *task) {							\
						void __DECL(__LINE__)();						\
						__DECL(__LINE__)();								\
					}													\
				void __DECL(__LINE__)()

#pragma GCC poison __routine

#endif