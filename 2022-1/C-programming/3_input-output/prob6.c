#include<stdio.h>

int main(){

	int y, m, d;
	scanf("%d/%d/%d", &y, &m, &d);

	printf("year %04d month %02d date %02d\n", y, m, d);

	return 0;
}