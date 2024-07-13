#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x = 0;
    scanf("%d", &x);
    
    // 정수끼리 나누면 결과는 무조건 정수
    printf("몫은: %d\n", x / 3);
    printf("나머지는: %d\n", x % 3);
    // 이형 연산: 실수 / 정수 면 실수로 나옴
    printf("몫을 모두 나타내면: %f\n", (double)x / 3);
    
    int x = 0;
    scanf("%d", &x);
    printf("몫: %d\n", 10 / x);
    return 0;
}
