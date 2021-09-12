#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "iostream"

void handler(int sig) {
  void *array[10];
  size_t size;
  char **bt_syms;

  // get void*'s for all entries on the stack
  size = backtrace(array, 10);
  bt_syms = backtrace_symbols(array, size);

  // print out all the frames to stderr
  fprintf(stderr, "Error: signal %d:\n", sig);
  for (int i = 0; i < size; i++)
      std::cout << bt_syms[i] << std::endl;
  //backtrace_symbols_fd(array, size, STDERR_FILENO);
  exit(1);
}

void baz() {
 int *foo = (int*)-1; // make a bad pointer
  printf("%d\n", *foo);       // causes segfault
}

void bar() { baz(); }
void foo() { bar(); }


int main(int argc, char **argv) {
  signal(SIGSEGV, handler);   // install our handler
  signal(SIGTERM, handler);   // install our handler
  signal(SIGKILL, handler);   // install our handler
  signal(SIGABRT, handler);   // install our handler
  throw "Hello";
  //foo(); // this will call foo, bar, and baz.  baz segfaults.
}
