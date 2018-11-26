#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

int main(int argc, char* argv[])
{
  // the number of lines entered
  int count = 0;

  // a buffer into which the read data will be stored
  char buf[1000];
  // get a line from the command line
  while (fgets(buf, 1000, stdin),'q' != buf[0])
    {
      //and as long as the line doesn't start with q

      //increment the count
      count++;
      // print the count to the screen
      printf("Hit enter  %d times\n", count);
    }

  // when the user entered a q, quit
  return 0;
}
