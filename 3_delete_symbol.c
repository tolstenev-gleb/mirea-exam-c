/*
Билет №3

Через аргументы командной строки задается строка символов и символ для удаления.
Реализовать функцию удаления заданного символа из строки без выделения
дополнительной памяти и использования дополнительных строк. Вывести в файл
out.txt исходную строку и результат работы функции над исходной строкой.

Пример:
Ввод: ./a.out "Hello, my dear friends!" е
Вывод (файл): Неllо, my dear friends!
Hllo, my dar frinds!
*/

#include <stdio.h>
#include <stdlib.h>

void remove_char(char *str, char del);
void remove_char_ptr(char *str, char del);

void remove_char(char *str, char del) {
  // Создаём индекс для позиции записи
  int write = 0;
  
  // Создаём индекс для позиции чтения
  // Цикл от первого символа до конца строки
  for (int read = 0; str[read] != '\0'; read++) {
    // Если текущий символ НЕ является символом для удаления
    if (str[read] != del) {
      //   то "удаляем"
      //   по индексу записи ставим текущий (считанный) символ
      str[write] = str[read];
      //   сдвигаем индекс записи
      write++;
    }
  }
  // Ставим конец строки по индексу записи
  str[write] = '\0';
}

int main(int argc, char *argv[]) {
  char *str = argv[1];
  char del = argv[2][0];

  FILE *out = fopen("out.txt", "w");
  if (out == NULL) {
    return 1;
  }

  fprintf(out, "%s\n", str);
  remove_char_ptr(str, del);
  fprintf(out, "%s\n", str);

  fclose(out);
  return 0;
}

// Версия на указателях
void remove_char_ptr(char *str, char del) {
  char* write = str;
  
  for (char* read = str; *read != '\0'; read++) {
    if (*read != del) {
      *write = *read;
      write++;
    }
  }
  // Ставим конец строки по индексу записи
  *write = '\0';
}