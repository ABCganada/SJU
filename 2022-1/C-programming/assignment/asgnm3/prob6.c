#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n;//몇 층?
	scanf("%d", &n);//n 층

	while (n > 1 && n % 3 != 0) {//종료조건

		for (int i = 0; i < n; i++) {//층 수 변수 i
			for (int j = i + 1; j < n; j++) {//공백 갯수 변수 j
				printf(" ");
			}
			for (int k = 0; k < 2 * i + 1; k++) {//X, O를 출력할 변수 k
				if (i != 0 && i != n - 1) {//만약 맨 아랫층과 윗층이 아니라면
					if (k == 0 || k == 2 * i)//양 끝에만 X를 출력하고
						printf("X");
					else//그 외에는 O를 출력한다
						printf("O");
				}
				else//맨 아랫층과 윗층이라면 X만 출력한다
					printf("X");
			}
			printf("\n");//줄바꿈
		}

		scanf("%d", &n);//while문 돌기 전에 새로 n입력
	}

	return 0;
}