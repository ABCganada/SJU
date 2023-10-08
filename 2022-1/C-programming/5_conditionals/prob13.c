#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int kor, eng, mat;
	scanf("%d%d%d", &kor, &eng, &mat);

	double avg = (kor + eng + mat) / 3.0;

	printf("%.2lf\n", avg);

	int judge = (int)avg;

	switch (judge/25) {
	case 4: case 3:
		printf("A\n");
		break;

	case 2:
		printf("B\n");
		break;

	default:
		printf("F\n");
		break;
	}

	return 0;
}