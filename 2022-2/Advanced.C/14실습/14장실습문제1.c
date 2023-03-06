#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    int buffer, i, cnt, tot;
    double avg;
    FILE *fp;

    fp = fopen("data.txt", "w");
    if(fp==NULL){
        printf("Couldn't open file\n");
    }

    while(1){
        scanf("%d", &buffer);
        if(buffer == -1) break;
        fprintf(fp, "\n%d", buffer);
    }
    fclose(fp);

    fp = fopen("data.txt", "r");
    if(fp==NULL){
        printf("Couldn't open file\n");
    }

    cnt = 0; tot = 0; avg = 0;
    while(!feof(fp)){
        fscanf(fp, "%d", &buffer);
        cnt++;
        tot += buffer;
    }
    fclose(fp);
    avg = tot*1.0 / cnt;

    printf("%d\n%d\n%.2lf\n", cnt, tot, avg);



    return 0;
}