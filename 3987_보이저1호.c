#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

enum DIRECTION {
	UP = 0,
	RIGHT,
	DOWN,
	LEFT
};

char DIR[4] = { 'U', 'R', 'D', 'L' };

struct answer {
	char dir;
	int time;
};

int main() {
	FILE* pFile = NULL;
	char** matrix = NULL;
	int height, width;
	int x, y, start_x, start_y;
	int i, j, k;
	int time;
	struct answer solution;
	enum DIRECTION direction;
	enum DIRECTION start_dir;

	solution.dir = 'Z';
	solution.time = -1;

	pFile = fopen("input.txt", "r");
	if (pFile == NULL) {
		printf("file open error!\n");
		return 0;
	}

	fscanf(pFile, "%d %d\n", &height, &width);

	matrix = (char**)malloc(sizeof(char*) * height);
	for (i = 0; i < height; ++i)
		matrix[i] = (char*)malloc(sizeof(char) * width);

	for (i = 0; i < height; ++i) {
		//fscanf(pFile, "%s", matrix[i]);
		for (j = 0; j < width; ++j) {
			fscanf(pFile, "%c", &matrix[i][j]);
		}
		fscanf(pFile, "\n");
	}

	fscanf(pFile, "%d %d\n", &start_y, &start_x);
	start_x -= 1;
	start_y -= 1;

	printf("%d %d\n", height, width);
	/*for (i = 0; i < height; ++i) {
		printf("%s\n", matrix[i]);
	}*/
	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			//printf("%c", *(*(matrix+i)+j));
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
	printf("%d %d\n", start_y + 1, start_x + 1);

	//////////////////////////////////////////////////////////
	direction = UP;
	for (k = 0; k < 4; ++k) {
		start_dir = direction;
		x = start_x;
		y = start_y;
		time = 1;
		//printf("%d\n", direction);
		while ((x > -1 && x < width) && (y > -1 && y < height)) {
			switch (direction) {
			case UP:
				y -= 1;
				break;
			case RIGHT:
				x += 1;
				break;
			case DOWN:
				y += 1;
				break;
			case LEFT:
				x -= 1;
				break;
			default:
				break;
			}

			if ((x > -1 && x < width) && (y > -1 && y < height)) {
				if (x == start_x && y == start_y && direction == start_dir) {
					time = INT_MAX;
					break;
				}

				if (matrix[y][x] == '.') {
					time++;
				}
				else if (matrix[y][x] == '/') {
					if (direction == RIGHT)
						direction = UP;
					else if (direction == LEFT)
						direction = DOWN;
					else if (direction == DOWN)
						direction = LEFT;
					else if (direction == UP)
						direction = RIGHT;
					time++;
				}
				else if (matrix[y][x] == '\\') {
					if (direction == UP)
						direction = LEFT;
					else if (direction == LEFT)
						direction = UP;
					else if (direction == RIGHT)
						direction = DOWN;
					else if (direction == DOWN)
						direction = RIGHT;
					time++;
				}
				else if (matrix[y][x] == 'C') {
					time++;
					break;
				}
			}
			else
				break;
		}
		if (solution.time < time) {
			solution.dir = DIR[start_dir];
			solution.time = time;
		}
		direction = start_dir + 1;
	}
	//////////////////////////////////////////////////////////

	printf("-----------------------------------\n");

	printf("%c\n", solution.dir);
	if (solution.time != INT_MAX)
		printf("%d\n", solution.time);
	else
		printf("Voyager\n");

	for (i = 0; i < height; ++i)
		free(matrix[i]);
	free(matrix);

	fclose(pFile);

	return 0;
}