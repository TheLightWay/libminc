#ifndef __UNISTD_H
#define __UNISTD_H

typedef unsigned long size_t;
typedef long ssize_t;

/* make a system call */
long syscall(long number, ...);

/* read from a file descriptor */
ssize_t read(int fd, void *buf, size_t count);

/* write to a file descriptor */
ssize_t write(int fd, const void *buf, size_t count);

/* close a file */
int close(int fd);

#endif /* __UNISTD_H */
