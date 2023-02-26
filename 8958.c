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
	int totalscore[10] = { 0 };

	scanf("%d\n", &num);
	//fflush(stdin);



	for (i = 0; i < num; i++) {
		score = 0;
		for (j = 0; ; j++) {
			scanf("%c", &ox[j]);
			if (ox[j] == '\n') {
				ox[j] = 0;
				break;
			}
		}

		for (j = 0; ox[j] != 0; j++) {
			if (ox[j] == 'O') {
				score++;
				totalscore[i] += score;
			}
			else
				score = 0;
		}
	}

	for (i = 0; i < num; i++) {
		printf("%d\n", totalscore[i]);
	}

	return 0;
}