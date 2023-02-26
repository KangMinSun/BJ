#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
	int test;
	int student;
	int i = 0;
	int j = 0;
	int* score;
	int sum = 0;
	int count = 0;
	double* result;

	scanf("%d", &test);

	result = (double*)malloc(sizeof(double) * test);

	for (i = 0; i < test; i++) {
		sum = 0;
		scanf("%d", &student);

		score = (int*)malloc(sizeof(int) * student);

		for (j = 0; j < student; j++) {
			scanf("%d", (score + j));
			sum += *(score + j);
		}


		double average = (double)sum / student;
		count = 0;

		for (j = 0; j < student; j++) {
			if (*(score + j) > average) {
				count++;
			}
		}

		*(result + i) = (double)count / student * 100;
		//printf("%.3lf%%\n", *(result + i));

		free(score);
	}
	for (i = 0; i < test; i++) {
		printf("%.3lf%%\n", *(result + i));
	}

	free(result);
	return 0;
}