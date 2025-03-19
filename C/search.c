#include <stdio.h>

int search(int a[], int n, int x){
    for (int i = 0; i <= n-1; i++){
        printf("a[i] = %d\n", a[i]);
        if (a[i] == x){
            return i;
        }
    }
    return -1;
}
int main (){
    int a[] = {1, 2, 3, 4, 5,6};
    int n = 6;
    int x = 6;
    int result = search(a, n, x);
    printf("result = %d\n", result);
    if (result == -1){
        printf("Not found\n");
    }
    else{
        printf("Found at index %d\n", result);
    }
    return 0;
}