/**
 * Code examples for Memory Allocation section of this video:
 * https://www.youtube.com/watch?v=6OSeJFo6GOc
 */

#include <stdio.h>
#include <stdlib.h>

int useMalloc() {
  int* ptr;
  int num, sum = 0, i;

  num = 8;
  printf("We have %d elements to allocate memory to.\n", num);

  ptr = (int*)malloc(num * sizeof(int));
  if (ptr == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  } else {
    printf("Memory allocation successful using malloc()!\n");
  }

  for (i = 0; i < num; i++) {
    ptr[i] = i + 1;
  }

  printf("Inserted %d elements in the block are as follows:\n", num);
  for (i = 0; i < num; i++) {
    printf("%d\n", ptr[i]);
  }
}

int useCalloc() {
  int* ptr;
  int num, sum = 0, i;

  num = 8;
  printf("We have %d elements to allocate memory to.\n", num);

  ptr = (int*)calloc(num, sizeof(int));
  if (ptr == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  } else {
    printf("Memory allocation successful using calloc()!\n");
  }

  for (i = 0; i < num; i++) {
    ptr[i] = i + 1;
  }

  printf("Inserted %d elements in the block are as follows:\n", num);
  for (i = 0; i < num; i++) {
    printf("%d\n", ptr[i]);
  }
}

int useFree() {
  int* ptr;
  int num, sum = 0, i;

  num = 8;
  printf("We have %d elements to allocate memory to.\n", num);

  ptr = (int*)calloc(num, sizeof(int));
  if (ptr == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  } else {
    printf("Memory allocation successful using calloc()!\n");
  }

  free(ptr);
  printf("Calloc or contiguous memory has been freed or de-allocated!\n");
}

int useRealloc() {
  int* ptr;
  int num, sum = 0, i;

  num = 8;
  printf("We have %d elements to allocate memory to.\n", num);

  ptr = (int*)calloc(num, sizeof(int));
  if (ptr == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  } else {
    printf("Memory allocation successful using calloc()!\n");
  }

  for (i = 0; i < num; i++) {
    ptr[i] = i + 1;
  }

  printf("Inserted %d elements in the block are as follows:\n", num);
  for (i = 0; i < num; i++) {
    printf("%d\n", ptr[i]);
  }

  ptr = realloc(ptr, 16 * sizeof(int));
  printf("Memory has been re-allocated!");
}

int main() {
  // Run one method at a time.
  useMalloc();
  //   useCalloc();
  //   useFree();
  //   useRealloc();
}
