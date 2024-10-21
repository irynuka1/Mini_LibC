#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    long ret = syscall(35, req, rem);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}