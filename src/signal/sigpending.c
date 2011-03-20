#include <signal.h>
#include "syscall.h"

int sigpending(sigset_t *set)
{
	return syscall(__NR_rt_sigpending, set, 8);
}
