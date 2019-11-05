#include <stdio.h>
#include <string.h>

/* Таблица частот */
unsigned Freq[256];

void main( void )
{
  char Name[12];
  FILE *F;
  int i;

  printf("Введите имя файла > ");
  scanf("%s", Name);
  if ((F = fopen(Name, "rt")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для чтения файл '%s'\n", Name);
    return;
  }

  /* Обнуление таблицы частот */
  memset(Freq, 0, 256 * sizeof(unsigned));

  /* Заполнение таблицы частот */
  while (!feof(F))
    Freq[fgetc(F)] ++;

  /* Вывод результата */
  printf("Частоты появления символов:\n");
  for (i = 0; i < 256; i ++)
    if (Freq[i])
      printf("Символ %c : %5u раз\n", i, Freq[i]);
} /* Ens of 'main' function */

/* End of 'task_1_4.c' file */