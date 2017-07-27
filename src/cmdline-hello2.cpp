#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <functional>

#include "jump.h"

int main(int argc, char* argv[])
{
  // the number of lines entered
  int count = 0;

  // a buffer into which the read data will be stored
  char buf[1000];

 loopBegin:
  // get a line from the command line
  fgets(buf, 1000, stdin);
  // JE means JUMP-IF-EQUAL.
  // if 'q' is the first character in buf, then
  // the program-counter is set to the instruction
  // immediately following the exit: block tag.
  JE('q', buf[0], exit);
  // otherwise, the program counter is incremented
  // as usual, which means the instruction on the
  // next line is executed.

  //increment the count
  count++;
  // print the count to the screen
  printf("Hit enter  %d times\n", count);
  // repeat until q is entered
  goto loopBegin;

 exit:
  return 0;
}
