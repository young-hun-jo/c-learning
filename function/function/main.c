#include <stdio.h>
#include "func.h"

//int Add(int, int);

int getMaxValue(int a, int b, int c) {
    int maxValue = a;
    if (b > maxValue) maxValue = b;
    if (c > maxValue) maxValue = c;
    return maxValue;
}

int main(void) {
//    int a = 0, b = 0, c = 0;
//    
//    printf("세 정수를 입력히세요: ");
//    scanf("%d%d%d", &a, &b, &c);
//    
//    printf("최댓값: %d\n", getMaxValue(a, b, c));
    
    int res = 0, res2 = 0;
    res = Add(3, 4);
    res2 = Multiple(3, 4);
    printf("Result:%d %d\n", res, res2);
    return 0;
}
