/**
 * Code examples for Processes section of this video:
 * https://www.youtube.com/watch?v=6OSeJFo6GOc
 */

#include <stdio.h>
#include <unistd.h>

int main() {
  int procId, parentProcId;
  procId = getpid();
  parentProcId = getppid();
  printf("PROCESS ID: %d\n", procId);
  printf("Parent PROCESS ID: %d\n", parentProcId);
}
