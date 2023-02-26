#pragma warning (disable:4996)
#include <stdio.h>

int n;
int m;
char a[501][501];
int pr;
int pc;
int i = 0;
int j = 0;
char D[] = { 'U', 'R', 'D', 'L' };
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int A[] = { 1, 0, 3, 2 };
int B[] = { 3, 2, 1, 0 };
int dist;
int direction;
int infinity = 0;

/*
char direcion 활용 해볼 것.
U  -1,  0
R   0, +1
D  +1,  0
L   0, -1

무한 경로의 조건 == 현재 탐색중인 좌표가 시작좌표와 일치하면서, 시작할 때 의 탐색 방향과 현재 탐색 방향이 일치하는 경우

탐색 루트를 벗어나는 조건 == C를 만났거나 / 탐색 좌표가 M,N 의 범위를 벗어났을 경우

*/


void sol() {
	for (i = 0; i < 4; i++) {
		int x = pr;
		int y = pc;
		int cnt = 1;
		int k = i;

		//while (a[x + dx[k]][y + dy[k]]) {
		while((x+dx[k] > -1 && x+dx[k] < m) && (y+dy[k] > -1 && y+dy[k] < n)) {
			x += dx[k];
			y += dy[k];
			if (a[y][x] == '.')
				cnt += 1;
			else if (a[y][x] == '/') {
				k = A[k];
				cnt += 1;
			}
			else if (a[y][x] == '\\') {
				k = B[k];
				cnt += 1;
			}
			else if (a[y][x] == 'C') {
				cnt += 1;
				break;
			}
			if (x == pr && y == pc && k == i) {
				infinity = 1;
				break;
			}
		}


		if (dist < cnt) {
			dist = cnt;
			direction = i;
		}
	}

	printf("%c\n", D[direction]);
	if (infinity == 1) {
		printf("Voyager\n");
	}
	else
		printf("%d\n", dist);

}


int main() {
	FILE* pFile = NULL;
	pFile = fopen("input.txt", "r");

	bool fact = true;



	//scanf("%d %d", &n, &m);
	fscanf(pFile, "%d %d\n", &n, &m);

	for(i = 0; i < n; i++) {
		for (j = 0; j <= m; j++) {
			//scanf("%c", &a[i][j]);
			fscanf(pFile, "%c", &a[i][j]);
		}
		fscanf(pFile, "\n");
	}

	//scanf("%d %d", &pr, &pc);
	fscanf(pFile, "%d %d\n", &pr, &pc);
	pr -= 1;
	pc -= 1;
	sol();

	fclose(pFile);
	return 0;
}
