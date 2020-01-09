#include "../inc/libmx.h"

static int check_fd(const char *file) {
    int fd = open(file, O_RDONLY);

    if (!errno) {
        close(fd);
        fd = open(file, O_RDONLY, O_DIRECTORY);
        if (errno)
            return fd;
    }
    return -1;
}

char *mx_file_to_str(const char *file) {
    int fd = check_fd(file);
    char c = 0;
    int len = 0;
    char *s = NULL;

    if (fd < 0)
        return NULL;
    while ((c = read(fd, &c, 1)))
        len++;
    close(fd);
    s = mx_strnew(len);
    fd = open(file, O_RDONLY);
    for (int i = 0; i < len; i++) 
        read(fd, s + i, 1); 
    close(fd);
    if (!errno && *s)
        return s;
    return NULL;
}

