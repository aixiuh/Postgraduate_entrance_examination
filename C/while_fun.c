#include <stdio.h>

int main() {
    int x = 1,sum = 0;
    while (520) {
        printf("Hello, World!,第%d次\n", x);
        sum = sum + x;
        x++;
        if (x == 14) {
            break;
        }
    printf("sum = %d\n", sum);    
    }
}