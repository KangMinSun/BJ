#pragma warning (disable : 4996)
#include <stdio.h>

int main() {
	int score[5][4] = { 0 };
	int i = 0;
	int j = 0;
	int sum = 0;
	int max = 0;
	int n = 0;

	for (i = 0; i < 5; i++) {
		sum = 0;
		for (j = 0; j < 4; j++) {
			scanf("%d", &score[i][j]);
			sum += score[i][j];
		}
		if (max < sum) {
			max = sum;
			n = i + 1;
		}
	}

	printf("%d %d", n, max);
	return 0;
}