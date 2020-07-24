/**
 * Code examples for File IO section of this video:
 * https://www.youtube.com/watch?v=6OSeJFo6GOc
 */

#include <stdio.h>
#include <stdlib.h>

int writingToTextFile() {
  int num;
  FILE* fptr;

  fptr = fopen("file1.txt", "w");
  if (fptr == NULL) {
    printf("ERROR!");
    exit(1);
  }

  printf("Enter num: ");
  scanf("%d", &num);
  fprintf(fptr, "%d", num);
  fclose(fptr);
}

int readingFromTextFile() {
  int num;
  FILE* fptr;

  if ((fptr = fopen("file1.txt", "r")) == NULL) {
    printf("ERROR in opening file!");
    exit(1);
  }

  fscanf(fptr, "%d", &num);
  printf("Value of n = %d.\n", num);

  fclose(fptr);
}

struct threeNumbers {
  int8_t num1, num2, num3;
};

int writingToBinaryFile() {
  FILE* fptr;
  struct threeNumbers numbers;
  int num;

  if ((fptr = fopen("program.bin", "wb")) == NULL) {
    printf("ERROR OPENING FILE!");
    exit(1);
  }

  printf("Size of struct: %d.\n", sizeof(struct threeNumbers));

  for (num = 1; num < 5; ++num) {
    numbers.num1 = num;
    numbers.num2 = 2 * num;
    numbers.num3 = 2 * num + 3;
    printf(
        "num1: %d\tnum2: %d\tnum3: %d.\n",
        numbers.num1,
        numbers.num2,
        numbers.num3);
    fwrite(&numbers, sizeof(struct threeNumbers), 1, fptr);
  }

  fclose(fptr);
}

int readingFromBinaryFile() {
  FILE* fptr;
  struct threeNumbers numbers;
  int num;

  if ((fptr = fopen("program.bin", "rb")) == NULL) {
    printf("ERROR OPENING FILE!");
    exit(1);
  }

  printf("Size of struct: %d.\n", sizeof(struct threeNumbers));

  for (num = 1; num < 5; ++num) {
    fread(&numbers, sizeof(struct threeNumbers), 1, fptr);
    printf(
        "num1: %d\tnum2: %d\tnum3: %d.\n",
        numbers.num1,
        numbers.num2,
        numbers.num3);
  }

  fclose(fptr);
}

int main() {
  // Run one method at a time.
  writingToTextFile();
  //   readingFromTextFile();
  //   writingToBinaryFile();
  //   readingFromBinaryFile();
}
