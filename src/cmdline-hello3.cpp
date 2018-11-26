#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <functional>
#include <cstdbool>

#include "jump.h"

void lambdaWhile(std::function<bool()> predicate,
                 std::function<void()> block)
{
 loopBegin:
  // test to see if the predicate (i.e., a procedure which
  // evaluates to true of false) is true
  JE(false,predicate(), exit);  /* if it's false, end the loop
                                   by going to exit */
  block();   // otherwise, evaluate the block
  goto loopBegin; // and then repeat
 exit:
  return;
}

int main(int argc, char* argv[])
{
  int count = 0;

  lambdaWhile([&](){
      // notice that the scope of buf can be lessened
      char buf[1000];
      fgets(buf, 1000, stdin);
      return 'q' != buf[0];
    },
    [&](){
      count++;
      printf("Hit enter  %d times\n", count);
    });

}
