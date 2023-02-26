#include <stdio.h>

int self_number(int n) {
    int dn = n;
    dn += (n / 1000) + ((n / 100) % 10) + ((n / 10) % 10) + (n % 10);
    return dn;
}

int main() {
    int a[10001] = { 0, };
    int result;

    for (int i = 1; i < 10001; i++) {
        result = self_number(i);
        if (result <= 10000)
            a[result] = 1;
    }

    for (int j = 1; j < 10001; j++) {
        if (a[j] == 0) {
            printf("%d\n", j);
        }
    }
    return 0;
}