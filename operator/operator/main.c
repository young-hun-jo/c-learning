#include <stdio.h>

#define countof(array) (sizeof(array) / sizeof(array[0]))

int main(void) {
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
    
    // 필수 연습문제(1)
    int x = 0, y = 0;
    printf("두 정수를 입력하세요.: ");
    scanf("%d%d", &x, &y);
    // case1)
    int tmp = x + y;
    printf("AVG: %.2f\n", (double)tmp / 2);
    // case2)
    double avg = 0.0;
    avg = (x + y) / 2.0;
    printf("AVG: %.2f\n", avg);

//    필수 연습문제(2)
    int n = 0;
    scanf("%d", &n);
    
    int hour = 0, minute = 0, second = 0;
    int remainder = 0;
    
    hour = n / 3600;
    minute = (n % 3600) / 60;
    second = n % 60;
    
    printf("%d초는 %d시간 %02d분 %02d초 입니다.\n", n, hour, minute, second);
    
    // 대입연산자
    char szBuffer[32] = { 0 };
    // 배열의 이름은 배열의 첫 원소의 메모리 주소임. 고로, 메모리 주소에 'A'(정수로는 65)를 할당한다는 것인데 이것은 불가능
    // szBuffer = 'A';
    
    // 필수 연습문제
    int a = 0, b = 0;
    int tmp = 0;
    
    scanf("%d%d", &a, &b);
    tmp = a;
    a = b;
    b = tmp;
    printf("a:%d, b:%d\n", a, b);
    
    // 필수 연습문제
    int n = 0;
    int result = 0;
    
    scanf("%d", &n);
    result += n;
    scanf("%d", &n);
    result += n;
    scanf("%d", &n);
    result += n;
    
    printf("Total: %d\n", result);
    
    unsigned int data = 256; // int = 4byte = 32bit
    unsigned char ch; // char = 1byte = 8bit = 총 256가지 => 0 ~ 255
    
    ch = data; // 그런데 char 형에 int 형을 대입했는데, int 형의 값이 char 범위를 넘어서는 값이다 => 정보 유실됨. 심지어 C은 이런 경우에 대해서 경고나 에러를 보여주지 않음..
    printf("%d\n", ch);
    
    // 단항 증/감 연산자 주의점
    int x = 0, nResult = 0;
    ++x;
    printf("%d\n", x);
    x++;
    printf("%d\n", x);
    nResult = ++x;
    printf("%d, %d\n", nResult, x);
    nResult = x--;
    printf("%d, %d \n", nResult, x);
    
    // Endian => Mac M2 pro CPU도 little endian을 사용중
    int nData = 0x12345678;
    printf("%08X\n", nData);
    
    // 비트 연산자로 뺄셈하기
    // 1. 빼는 숫자의 1의 보수를 구한다 2. 거기에 1을 더해 2의 보수로 만든다 3. 더한다
    int x = 0, y = 0;
    int res = 0;
    scanf("%d%d", &x, &y);
    
    res = x + (~y + 1);
    printf("결과:%d\n", res);
    
    // sizeof() 연산자는 컴파일 타임 연산자이므로 ++ 와 같은 CPU를 사용하는 연산자는 넣어도 수행되지 않음. 물론 에러도 안남..
    int nData = 10;
    // printf("%lu\n", sizeof(++nData));
    
    int aList[16];
    printf("%lu\n", sizeof(aList));
    printf("%lu\n", countof(aList));
    
    // 논리 연산시 주의점
    int x = 0, res = 0;
    scanf("%d", &x);
    
    // res = 3 < x < 20; // 이렇게 하면 3 < x를 먼저하고 그 결과값을 '< 20' 이랑 비교하게 됨..
    res = x > 3 && x < 30;
    printf("Result: %d\n", res);
    
    // 필수연습문제(1)
    unsigned int score = 0;
    
    printf("점수를 입력하세요: ");
    scanf("%d", &score);
    
    printf("결과: %s\n", (score >= 80) ? ("합격") : ("불합격"));
    
    // 필수연습문제(2)
    int n = 0, max = 0;
    
    scanf("%d", &n);
    max = n;
    
    scanf("%d", &n);
    max = (max > n) ? max : n;
    
    scanf("%d", &n);
    max = (max > n) ? max : n;
    
    printf("MAX: %d\n", max);
    
    // 필수연습문제(3)
    int x = 0, y = 0, z = 0, max = 0;
    scanf("%d%d%d", &x, &y, &z);
    
    max = (x > y) ? x : y;
    max = (max > z) ? max : z;
    printf("MAX: %d\n", max);
    
    return 0;

}
