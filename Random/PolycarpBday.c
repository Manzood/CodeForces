#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    int b, count, test, rem;
    int n, num;

    while (t--) {
        count = 0;
        scanf("%d", &n);

        test = 1;

        num = n;
        b = 0;

        while (num > 10) {
            num = num / 10;
            b++;
        }

        while (n > num) {
            rem = n % 10;

            if (rem < num) {
                test = 0;
            }

            n = n / 10;
        }

        if (test == 1)
            count += num;
        else
            count += num - 1;

        count += (b * 9);

        printf("%d\n", count);
    }
}
