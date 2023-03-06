#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    FILE *fp1, *fp2;
    char filename1[21], filename2[21], ch;
    scanf("%s", filename1);
    scanf("%s", filename2); 

    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "w");

    

    while(!feof(fp1)){
        ch = fgetc(fp1);
        fputc(ch, fp2);
    }


    fclose(fp1);
    fclose(fp2);


    return 0;
}