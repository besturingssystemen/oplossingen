#include "user/user.h"

struct memlayout {
  void* text;
  int* data;
  int* stack;
  int* heap;
};

int data_var;

void print_mem(const struct memlayout* layout) {
    printf("stack:%p\n", layout->stack);
    printf("heap:%p\n", layout->heap);
    printf("data:%p\n", layout->data);
    printf("text:%p\n", layout->text);
}

int main() {
  struct memlayout layout;

  // Stack address
  int stack_var;
  layout.stack = &stack_var;

  // Heap address
  int* heap_var = sbrk(sizeof(int));
  layout.heap = heap_var;

  // Text address
  layout.text = (void*)main;

  // Data address
  layout.data = &data_var;

  print_mem(&layout);

  exit(0);
}
