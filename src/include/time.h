#ifndef TIME_H
#define __TIME_H__ 1

#ifdef __cplusplus
extern "C"
{
#endif

#include <internal/types.h>

typedef long time_t;

struct timespec {
	time_t tv_sec;
	long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#ifdef __cplusplus
}
#endif

#endif
