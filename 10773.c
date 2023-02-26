#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int n;
	int i = 0;
	int j = 0;
	int num;
	int rest[100001] = { 0 };
	int sum;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num == 0) {
			rest[j] = 0;
			j--;
		}
		else {
			rest[j] = num;
			j++;
		}
	}

	for (i = 0; i < j; i++) {
		sum += rest[i];
	}

	printf("%d", sum);
}