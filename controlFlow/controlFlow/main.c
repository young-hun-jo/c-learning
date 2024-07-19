#include <stdio.h>

int main(void) {
    // 필수 연습문제(1)
    int n = 0, max = 0;
    
    scanf("%d", &n);
    max = n;
    scanf("%d", &n);
    if (n > max) max = n;
    scanf("%d", &n);
    if (n > max) max = n;
    printf("MAX: %d\n", max);
    
    // 필수 연습문제(2)
    unsigned int fare = 750, age = 0;
    
    scanf("%d", &age);
    if (age >= 20) {
        age = 20;
        fare = 1000;
    }
    
    printf("나이: %d, 최종요금: %d원\n", age, fare);
    
    scanf("%d", &age);
    if (age >= 20) {
        age = 20;
        fare = 1000;
    }
    
    printf("나이: %d, 최종요금: %d원\n", age, fare);
    
    // 필수 연습문제(1)
    unsigned int fare = 1000, age = 0;
    
    scanf("%d", &age);
    
    if (age < 14) {
        if (age < 4)
            fare = 0;
        else
            fare *= 0.5;
    }
    else {
        if (age >= 20)
            fare *= 1;
        else
            fare *= 0.75;
    }
    printf("최종 요금: %d\n", fare);
    return 0;
}
