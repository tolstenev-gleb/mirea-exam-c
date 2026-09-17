#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Открытие файла чтения
  FILE *in = fopen(argv[1], "r");
  if (in == NULL) {
    return 1;
  }
  // Открытие файла записи
  FILE *out = fopen("out.txt", "w");
  if (out == NULL) {
    fclose(in);
    return 1;
  }
  
  char str[7] = {0};
  // Цикл по числам
  // Чтение содержимого
  while (fscanf(in, "%s", str) != EOF) {
    //   "123204" -> 1 2 3 2 0 4 -> сумма первых и последних трёх 
    int a = str[0] - '0';
    int b = str[1] - '0';
    int c = str[2] - '0';
    int d = str[3] - '0';
    int e = str[4] - '0';
    int f = str[5] - '0';

    if (a + b + c == d + e + f) {
      // счастливый, вывод в файл
      fprintf(out, "%s true\n", str);
    } else {
      // НЕ счастливый, вывод в файл
      fprintf(out, "%s false\n", str);
    }
  }

  fclose(in);
  fclose(out);
  return 0;
}