#include <stdio.h>
#include <limits.h>  // 包含 INT_MAX 和 INT_MIN 的定义

int main() {
    printf("int最大值: %d\n", INT_MAX);  // 输出 2147483647
    printf("int最小值: %d\n", INT_MIN);  // 输出 -2147483648
    int a = 2147483647;
    a++;  // 溢出后可能变为 -2147483648（补码循环）
      printf("a = %d\n", a);
    return 0;
}