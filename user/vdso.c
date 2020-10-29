#include "user/user.h"
#include "kernel/memlayout.h"

int fastuptime()
{
  return *(int*)VDSO;
}
