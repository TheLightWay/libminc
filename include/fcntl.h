#ifndef __FCNTL_H
#define __FCNTL_H

#define O_RDONLY    0x0
#define O_WRONLY    0x1
#define O_RDWR      0x2
#define O_APPEND    0x400
#define O_ASYNC     0x2000
#define O_CLOEXEC   0x80000
#define O_CREAT     0x40
#define O_DIRECTORY 0x10000
#define O_DSYNC     0x1000
#define O_EXCL      0x80
#define O_NOCTTY    0x100
#define O_NOFOLLOW  0x20000
#define O_NONBLOCK  0x800
#define O_NDELAY    0x800
#define O_SYNC      0x101000
#define O_TRUNC     0x200

#define S_IRWXU     0x1c0
#define S_IRUSR     0x100
#define S_IWUSR     0x80
#define S_IXUSR     0x40
#define S_IRGRP     0x20
#define S_IWGRP     0x10
#define S_IXGRP     0x8
#define S_IRWXO     0x7
#define S_IROTH     0x4
#define S_IWOTH     0x2
#define S_IXOTH     0x1
#define S_ISUID     0x800
#define S_ISGID     0x400
#define S_ISVTX     0x200

int open(const char *pathname, int flags, ...);

#endif /* __FCNTL_H */
