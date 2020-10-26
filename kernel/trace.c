#include "trace.h"
#include "types.h"
#include "riscv.h"
#include "types.h"
#include "defs.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "param.h"
#include "proc.h"

uint64
sys_traceme(void)
{
  int tracefd;

  if(argint(0, &tracefd) < 0) {
    return -1;
  }

  struct proc* p = myproc();

  if (tracefd < 0) {
    p->tracefd = -1;
    return 0;
  }

  if (tracefd >= NOFILE ||
      !p->ofile[tracefd] ||
      p->ofile[tracefd]->type != FD_PIPE ||
      !p->ofile[tracefd]->writable) {
    p->tracefd = -1;
    return -1;
  }

  p->tracefd = tracefd;
  return 0;
}

void
trace_syscall()
{
  struct proc* p = myproc();

  if (p->tracefd < 0) {
    return;
  }

  struct tracemsg msg;
  msg.pid = p->pid;
  msg.syscall = p->trapframe->a7;

  struct pipe* pipe = p->ofile[p->tracefd]->pipe;
  pipewrite(pipe, /*user_src=*/0, (uint64)&msg, sizeof(msg));
}
