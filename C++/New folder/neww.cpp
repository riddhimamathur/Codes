#include <stdio.h>

int main(void)
{
    const int total = 100;
    int n = 1;
    int row = 1;

    /* 14 rows can hold 105 numbers; we stop at 100 */
    const int max_rows = 14;

    while (n <= total) {
        int count = row;
        int remaining = total - n + 1;
        if (count > remaining) {
            count = remaining;
        }

        int pad = (max_rows - count) * 2;
        int i;
        for (i = 0; i < pad; i++) {
            putchar(' ');
        }

        for (i = 0; i < count; i++) {
            printf("%4d", n);
            n++;
        }
        putchar('\n');
        row++;
    }

    return 0;
}
