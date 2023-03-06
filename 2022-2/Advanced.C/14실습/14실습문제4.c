#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    FILE *fp1, *fp2;
    char filename1[21], filename2[21], ch;
    scanf("%s", filename1);
    scanf("%s", filename2); 
    

    fp1 = fopen(filename1, "a");
    fp2 = fopen(filename2, "r");
    

    while(!feof(fp2)){
        ch = fgetc(fp2);
        fputc(ch, fp1);
    }

    while(!feof(fp2)){
        ch = fgetc(fp2);
        fputc(ch, fp1);
    }


    fclose(fp1);
    fclose(fp2);


    return 0;
}