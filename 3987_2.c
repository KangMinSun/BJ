#pragma warning (disable:4996);
#include <stdio.h>

int main() {
	int n;
	int m;
	char a[501][501];
	int i = 0;
	int j = 0;
	char enter;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		for (j = 0; j < m+1; j++) {
			scanf("%c", &a[i][j]);
		}
		//scanf("%c", &enter);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < m+1; j++) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}