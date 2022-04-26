#ifndef __FILE_H
#define __FILE_H

struct __FILE
{
    int fd;
    int lock;
};

typedef struct __FILE FILE;

#endif /* __FILE_H */