#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *cFile;
    cFile = fopen("t.txt", "r");
    if(cFile)
    {
	    char cArr[1001] = {0};
	    fgets(cArr, 1001, cFile);
        for(int i = 32; i<=127; i++)
        {
            int chNum = 0;
            for(int j = 0; j < 1000; j++)
            {
                if(cArr[j]==i)
                    chNum++;
            }
            printf("char \"%c\":%d\n", i, chNum);
        }

    }
    else
        printf("Нет такого файла \"file.txt\" \n");
    return 1;
}