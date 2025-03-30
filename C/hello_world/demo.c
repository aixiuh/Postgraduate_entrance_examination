#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
int i;
i = 10;
int j;
j = i+10;
printf("i的值为%d,地址为%d\n",i,&i);
printf("sizeof(int)=%ld",sizeof(int));
printf("\nsizeof(i)=%ld",sizeof(i));
printf("\n0x%x\n",&i);
printf("\n%p\n",&i);
return 1;
}