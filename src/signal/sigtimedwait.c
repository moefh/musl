#include <signal.h>
#include <errno.h>
#include "syscall.h"
#include "libc.h"

int sigtimedwait(const sigset_t *mask, siginfo_t *si, const struct timespec *timeout)
{
	int ret;
	CANCELPT_BEGIN;
	do {
		ret = syscall(__NR_rt_sigtimedwait, mask, si, timeout, 8);
	} while (ret<0 && errno==EINTR);
	CANCELPT_END;
	return ret;
}
