#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
	struct timespec req, rem;

	// Setting the time to sleep
	req.tv_sec = seconds;
	req.tv_nsec = 0;

	if (nanosleep(&req, &rem) == 0) {
		return 0;
	}

	return rem.tv_sec;
}