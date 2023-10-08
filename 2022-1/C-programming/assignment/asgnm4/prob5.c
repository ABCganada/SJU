#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[101], b[101], ab[200];//a배열, b배열: 100개 + 음수까지 입력될 수 있음
	//합집합 배열은 각 배열의 최대 개수를 수용해야 함
	int na = 0, nb = 0;//na, nb는 각 배열의 원소 개수
	int tmp = 0;//중복 확인 변수
	int cnt = 0;//합집합 배열의 자리수
	

	for (int i = 0; i < 101; i++) {//a배열 scan
		scanf("%d", &a[i]);
		if (a[i] < 0) {//음수면
			na = i;//원소 개수를 저장하고 
			break;//break
		}
		for (int j = 0; j <= i; j++) {//중복 확인
			if (a[i] == a[j])//같을 때마다
				tmp++;//tmp를 올려준다
		}
		if (tmp > 1) {//tmp가 2 이상이면
			i--;//i를 하나 내려주고 그 자리를 다시 입력 받아야 한다
		}
		tmp = 0;//tmp 초기화
	}
	
	for (int i = 0; i < 101; i++) {//b배열 scan
		scanf("%d", &b[i]);
		if (b[i] < 0) {//음수면
			nb = i;//원소 개수를 저장하고
			break;//break
		}
		for (int j = 0; j <= i; j++) {//중복 확인
			if (b[i] == b[j])//같을 때마다
				tmp++;//tmp를 올려준다
		}
		if (tmp > 1) {//tmp가 2 이상이면
			i--;//i를 하나 내려주고 그 자리를 다시 입력 받아야 한다
		}
		tmp = 0;//tmp 초기화
	}
	
	for (int i = 0; i < na + nb; i++) {//ab배열 만들기
		if (i >= na) {//i가 a배열의 자리수를 넘어가면
			ab[cnt++] = b[i - na];//b배열을 받는다
		}
		else {//그게 아니면
			ab[cnt++] = a[i];//a배열을 받는디
		}
		
		for (int j = 0; j <= i; j++) {//ab배열 중복 확인
			if (ab[cnt-1] == ab[j])//같을 때마다
				tmp++;//tmp를 올려준다
		}
		if (tmp > 1)//tmp가 2 이상이면
			cnt--;//ab배열 자리수를 하나 내려주고 그 자리를 다시 입력 받아야 한다
		tmp = 0;//tmp 초기화
	}
	for (int i = 0; i < cnt; i++) {//tmp 오름차순 정렬
		for (int j = 0; j < cnt; j++) {
			if (ab[i] < ab[j]) {//작으면
				tmp = ab[i];//서로 swap을 해준다.
				ab[i] = ab[j];
				ab[j] = tmp;
			}
		}
	}
	for (int i = 0; i < cnt; i++) {//ab배열 출력
		printf(" %d", ab[i]);
	}
	printf("\n");

	return 0;

}

