#include <stdio.h>
#include <string.h>

struct nameNumber
{
    char name[50];
    char phone[50];
};

int main(void)
{
    printf("Введите \"add\" чтобы добавить имя и номер\n");
    printf("Введите \"remove\" чтобы удалить имя и номер\n");
    printf("Введите \"search\" чтобы найти номер\n");
    printf("Введите \"print\" чтобы посмотреть список контактов\n");
    printf("Введите \"exit\" чтобы выйти\n");
    char options[7] = "abcdef\0";
    while(strcmp(options, "exit"))
    {
        scanf("%s", options);
        if(!strcmp(options, "add"))
        {
            struct nameNumber phoneBook;
            printf("Введите имя:");
            scanf("%s", phoneBook.name);
            printf("Введите номер:");
            scanf("%s", phoneBook.phone);
            FILE *file;
            file = fopen("file.txt", "a");
            if(file)
            {
                fprintf(file, "%s - %s\n", phoneBook.name, phoneBook.phone);
            }
            fclose(file);
            printf("Готово\n");
            fclose(file);
        }
        else if(!strcmp(options, "print"))
        {
            printf("Контакты\n");
            FILE *file;
            file = fopen("file.txt", "r");
            if(file)
            {
                int ch = 0;
                while((ch = fgetc(file)) != EOF)
                {
                    printf("%c", ch);
                }
            }
            else
            printf("пусто\n");
        fclose(file);
        }
        else if(!strcmp(options, "search"))
        {
            char sName[50];
            printf("Введите имя:");
            scanf("%s", sName);
            FILE *file;
            file = fopen("file.txt", "r");
            if(file)
            {
                char str[50];
                while(fscanf(file, "%s", str) != EOF)
                {
                    if(!strcmp(str, sName))
                    {
                        fscanf(file, "%s", str);
                        fscanf(file, "%s", str);
                        printf("номер: %s\n", str);
                    }
                }
            }
            else
                printf("контактов нет\n  \n");
            fclose(file);
        }
        else if(!strcmp(options, "remove"))
        {
            char rStr[102];
            printf("Введите имя:");
            scanf("%s", rStr);
            char rNumber[50];
            printf("Введите номер:");
            scanf("%s", rNumber);
            strcat(rStr," - ");
            strcat(rStr, rNumber);
            strcat(rStr, "\n");
            FILE *file, *tFile;
            file = fopen("file.txt", "r");
            tFile = fopen("tFile.txt", "w");
            if(file&&tFile)
            {
                char ch[102];
                while(fgets (ch, 102 , file) != NULL)
                {
                    if(strcmp(ch, rStr))
                        fprintf(tFile, "%s", ch);
                }
            }
            remove("file.txt");
            rename("tFile.txt", "file.txt");
            fclose(file);
            fclose(tFile);
        }
    }
        return 0;
}