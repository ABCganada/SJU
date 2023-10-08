#include<stdio.h>

int main(){

	int a;
	scanf("%d", &a);

	char c = a + 65;

	printf("The %dth upper case letter in the English alphabet is %c.\n", a, c);

	return 0;
}