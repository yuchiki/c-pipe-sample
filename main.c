#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LENGTH 10

void validate(int length) {
  if (length > MAX_LENGTH) {
    fprintf(stderr, "引数が%d個渡されています。10個以上の引数は渡せません。",
            length);
    exit(1);
  }
}

// 数字列をparseする。
void parse_numbers(int length, char *args[], int numbers[]) {
  for (int i = 0; i < length; i++) numbers[i] = atoi(args[i]);
}

// 昇順にsortする。
void sort(int length, int *numbers) {
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (numbers[i] > numbers[j]) {
        int tmp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = tmp;
      }
    }
  }
}

void print_raw_numbers(int length, int *numbers) {
  for (int i = 0; i < length; i++) {
    printf("%d ", numbers[i]);
  }

  puts("");
}

void print_numbers_pretty(int length, int numbers[]) {
  puts("ソートされた結果は以下の通りです。");

  for (int i = 0; i < length; i++) {
    printf("%2d位: %10d\n", i + 1, numbers[i]);
  }
  printf("以上%d件のデータをsortしました。\n", length);
}

int main(int argc, char *argv[]) {
  int numbers[MAX_LENGTH];
  int length = argc - 1;

  validate(length);
  parse_numbers(length, argv + 1, numbers);
  sort(length, numbers);

  if (isatty(fileno(stdout))) {
    print_numbers_pretty(length, numbers);
  } else {
    print_raw_numbers(length, numbers);
  }
  return 0;
}
