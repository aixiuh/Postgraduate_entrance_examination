#include <stdio.h>

int func(int sum, int arr[], int index) {
    int length = sizeof(arr) / sizeof(arr[0]);
    if (index >= length) {
        return sum;
    }
    return func(sum + arr[index], arr, index + 1);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int result = func(0, array, 0);
    printf("Result: %d\n", result); // 结果: 15
    
    return 0;
}