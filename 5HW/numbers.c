#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
 
int main()
{
    int i, n, *mas;
    setlocale(0, "rus");
    printf("Введите размер массива: ");
    scanf("%d", &n);
    srand(time(0));
    mas = malloc(n * sizeof(int));
    printf("Сгенерированный массив:\n");
    for (i = 0; i < n; i++) {
        mas[i] = rand() % 1000; // диапазон случайных чисед от 0 до 100
        printf("%d ", mas[i]);
    }
    return 0;
}
