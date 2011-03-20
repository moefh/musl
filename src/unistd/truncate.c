#include <unistd.h>
#include "syscall.h"
#include "libc.h"

int truncate(const char *path, off_t length)
{
	return syscall(__NR_truncate, path, __SYSCALL_LL(length));
}

LFS64(truncate);
