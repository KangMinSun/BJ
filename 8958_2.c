#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int num;
	char ox[80] = { 0 };
	int i = 0;
	int j = 0;
	int score = 0;
	int *totalscore = (int*)calloc(2, sizeof(int));
	char* ptr = &ox;

	scanf("%d\n", &num);
	//fflush(stdin);



	for (i = 0; i < num; i++) {
		score = 0;
		for (j = 0; ; j++) {
			scanf("%c", ptr + j);
			if (*(ptr+j) == '\n') {
				*(ptr+j) = 0;
				break;
			}
		}
		if (sizeof(totalscore) / sizeof(int) == i) {
			totalscore = (int*)realloc(totalscore, sizeof(int) * (i + 1));
		}

		for (j = 0; *(ptr+j) != 0; j++) {
			if (*(ptr+j) == 'O') {
				score++;
				*(totalscore+i) += score;
			}
			else
				score = 0;
		}
	}

	for (i = 0; i < num; i++) {
		printf("%d\n", *(totalscore + i));
	}

	free(totalscore);
}