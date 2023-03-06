#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student{
    char name[10];
    int scr;
}STUDENT;



int main() 
{
    FILE *fp;
    char filename[] = "student.dat";
    
    STUDENT st[3];
    for(int i=0; i<3; i++){
        scanf("%s", st[i].name);
        scanf("%d", &st[i].scr);
        getchar();
    }

    fp = fopen(filename, "wb");
    fwrite(st, sizeof(STUDENT), 3, fp);

    fclose(fp);



    return 0;
}