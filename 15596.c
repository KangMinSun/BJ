#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

long long sum(int* a, int n) {
	long long result = 0;
	int i = 0;
	for (i = 0; i < n; i++) {
		result += a[i];
	}
	return result;
}

int main() {
	int n;
	int i = 0;
	int* a;
	long long ans;
	scanf("%d", &n);

	a = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	ans = sum(a, n);
	printf("%ld", ans);
	return 0;
}
