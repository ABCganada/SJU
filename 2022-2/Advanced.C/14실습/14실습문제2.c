#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Convertor(char *p);

int main() 
{
    FILE *fp1 = fopen("test1.txt", "r");
    FILE *fp2 = fopen("test2.txt", "w");
    char buffer[10];
    int i;
    
    while(!feof(fp1)){
        fgets(buffer, 9, fp1);
        Convertor(buffer);
        fputs(buffer, fp2);
    }

    fclose(fp1);
    fclose(fp2);


    return 0;
}
void Convertor(char *p){
    char *ptr;
    int diff = 'a' - 'A';

    for(ptr=p; ptr<p+strlen(p); ptr++){
        if(*ptr >= 'a' && *ptr <= 'z')
            *ptr = *ptr - diff;
        else
            *ptr = *ptr + diff;
    }
}