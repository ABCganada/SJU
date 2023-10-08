#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void addArray(int x[], int y[], int z[], int length);

int main()
{
	int n;
	int x[20], y[20], z[20];
	int *px, *py, *pz;
	scanf("%d", &n);

	for (px = x; px < x + n; px++)
		scanf("%d", px);
	for (py = y; py < y + n; py++) {
		scanf("%d", py);
	}

	addArray(x, y, z, n);

	for (pz = z; pz < z + n; pz++)
		printf(" %d", *pz);
	return 0;
}
void addArray(int x[], int y[], int z[], int length) {
	int *i, *j;
	for (i = x, j = y + length - 1; i < x + length; i++) {
		*z = *i + *j;
		z++;
		j--;
	}
}