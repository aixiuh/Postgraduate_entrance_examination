#include<stdio.h>

int main() {
    int year, month, ex;
    printf("请输入年份及月份（空格分隔）：");
    scanf("%d %d", &year, &month);
    if(month < 1 || month > 12) {
        printf("输入有误！！");
    } else {
        if((year%4 == 0 && year%100 != 0) || year%400 == 0) {
            ex = 1;
            printf("%d年为闰年。\n", year);

        } else {
            ex = 0;
            printf("%d年不为闰年。\n", year);
        }

        switch(month) {
            case 4: printf("这是4月\n");
            case 6:
            case 9: 
            case 11: 
            printf("%d月有%d天。", month, 30); 
            break;
            case 2: printf("%d月有%d天。", month, 27+ex); break;
            default: printf("%d月有%d天。", month, 31);
        }
    }
}