#pragma warning (disable : 4996)
#include <stdio.h>

int main() {
	int scale[8] = { 0 };
	int i = 0;
	int as = 0;
	int de = 0;

    for (i = 0; i < 8; i++)
        scanf("%d ", &scale[i]);

    for (i = 0; i < 8; i++) {
        if (scale[i] == i + 1)
            as++;
        else if (scale[7 - i] == i + 1)
            de++;
    }

    if (as == 8)
        printf("ascending");
    else if (de == 8)
        printf("descending");
    else
        printf("mixed");

	return 0;
}
