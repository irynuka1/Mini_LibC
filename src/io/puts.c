#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int puts(const char *s) {
    const char *str = s;
    int len = 0;

    while (*str != '\0') {
        str++;
        len++;
    }

    int ret = write(1, s, len);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    write(1, "\n", 1);
    return ret;
}