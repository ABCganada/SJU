#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ABC(int *start, int length);

int main()
{
	int arr[10];
	int *p;
	int num = 10;

	for (p = arr; p < arr + 10; p++)
		scanf("%d", p);

	for (p = arr; p < arr + 10; p++) {
		ABC(p, num);
		num--;
	}

	for (p = arr; p < arr + 10; p++)
		printf(" %d", *p);



	return 0;
}
void ABC(int *start, int length) {
	int max;
	int r = 0;
	int tmp;
	int seat = 0;
	int max_seat = 0;
	for (int *i = start; i < start + length; i++) {
		if (r == 0) {
			max = *i;
			max_seat = seat;
			r++;
		}
		if (max < *i) {
			max = *i;
			max_seat = seat;
		}
		seat++;
	}
	tmp = *(start);
	*(start) = *(start + max_seat);
	*(start + max_seat) = tmp;


}