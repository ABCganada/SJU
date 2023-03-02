#include <stdio.h>  //stdio 라이브러리
#include <string.h> //string 라이브러리
#include <stdlib.h> //stdlib 라이브러리

typedef struct rest{ //구조체
    char name[100];
    int breakfast, lunch, dinner;
}rest;

int main()
{
    rest r[10];
    int i, j, k, n, money, near, tmp, Max_near, in = 0, s = 0;
    char *p[3];
    scanf("%d", &n);
    getchar();
    for(i=0; i<n; i++){
        scanf("%s", r[i].name);
        scanf("%d %d %d", &r[i].breakfast, &r[i].lunch, &r[i].dinner);
        getchar();
    }
    scanf("%d", &money);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                if(i != j && j != k && k != i){
                    tmp = r[i].breakfast + r[j].lunch + r[k].dinner;
                    near = money - tmp;
                    if(in == 0 && near >=0){
                        Max_near = near;
                        p[0] = r[i].name;
                        p[1] = r[j].name;
                        p[2] = r[k].name;
                        
                        in = 1;
                    }
                    if(Max_near > near && near >= 0){
                        Max_near = near;
                        p[0] = r[i].name;
                        p[1] = r[j].name;
                        p[2] = r[k].name;
                    }
                }
            }
        }
    }
    printf("%s\n%s\n%s\n%d\n", p[0], p[1], p[2], money-Max_near);

    return 0;
}
