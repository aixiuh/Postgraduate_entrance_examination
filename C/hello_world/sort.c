#include <stdio.h>
#include <stdlib.h>

// 交换两个元素的函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 分区函数
int partition(int array[], int low, int high) {
    int pivot = array[high]; // 选择最后一个元素作为基准
    int i = low - 1;         // i 是小于 pivot 的元素的索引

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]); // 将 pivot 放到正确的位置
    return i + 1;                      // 返回 pivot 的索引
}

// 快速排序函数
void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high); // 获取分区索引

        // 递归排序分区
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

int main() {
    int n = 10; // 数组大小
    int array[10];

    // 生成随机数组
    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 100 + 1; // 生成 1 到 100 的随机数
        printf("%d ", array[i]);
    }
    printf("\n");

    // 调用快速排序
    quick_sort(array, 0, n - 1);

    // 输出排序后的数组
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}