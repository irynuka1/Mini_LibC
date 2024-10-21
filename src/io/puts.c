#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int puts(const char *s) {
    int ret = syscall(1, 1, s, strlen(s));

    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    
    return ret;
}