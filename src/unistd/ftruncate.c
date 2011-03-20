#include <unistd.h>
#include "syscall.h"
#include "libc.h"

int ftruncate(int fd, off_t length)
{
	return syscall(__NR_ftruncate, fd, __SYSCALL_LL(length));
}

LFS64(ftruncate);
