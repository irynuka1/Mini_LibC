#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
// #include <time.h>

unsigned int sleep(unsigned int seconds)
{
    // struct timespec t1, t2;
    // t1.tv_sec = seconds;
    // t1.tv_nsec = NULL;

    // int ret = syscall(35, &t1, &t2);

    // if (ret < 0) {
    //     errno = -ret;
    //     return -1;
    // }

    return 0;
}