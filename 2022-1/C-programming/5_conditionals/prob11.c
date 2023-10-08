#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int a1, a2, a3, n1, n2, n3;
	scanf("%d%d%d", &a1, &a2, &a3);
	scanf("%d%d%d", &n1, &n2, &n3);

	int s = 0;
	int b = 0;

	if (n1 == a1 || n1 == a2 || n1 == a3) {

		if (n1 == a1)
			s++;

		else
			b++;
	}

	if (n2 == a1 || n2 == a2 || n2 == a3) {

		if (n2 == a2)
			s++;

		else
			b++;
	}

	if (n3 == a1 || n3 == a2 || n3 == a3) {

		if (n3 == a3)
			s++;

		else
			b++;
	}

	printf("%dS%dB\n", s, b);

	return 0;
}