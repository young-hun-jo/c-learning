#include <stdio.h>

int main(void){
    // 정수 0을 문자로 할당. 즉, ASCII 코드 표에서 숫자 0에 해당하는 문자로 변수 ch를 초기화
    char ch = 0;
    // 사용자 입력을 받는 함수. 입력한 것이 I/O buffer에 들어가고 그 buffer에서 가장 앞에 있는 문자 하나를 꺼내는 함수
    ch = getchar();
    putchar(ch);
    putchar('A');
    
    printf("%c\n", 'A'); // "A" 라고 쓰면 문자열로 인식하여 종단 문자인 \0(null)이 포함됨. 그럼에 따라 문자열 "A"의 첫번째 문자인 포인터 주소를 %c 형식으로 출력하는데, 이 때 포인터는 숫자로 변환되서 출력됨
    printf("%c\n", 'A' + 1); // 문자 'A'를 ASCII 코드표 기준 숫자의 +1 되는 값의 문자로 변환되어 출력
    printf("%c\n", 'C');
    
    printf("%d\n", 'A');
    printf("%d\n", 'A'+1);
    printf("%d\n", 'C');
    
    printf("%c\n", 65); // %c 형식으로 출력하라고 했으므로 65의 ASCII 코드 표에 해당하는 문자인 A로 변환되어 출력
    printf("%c\n", 65+1);
    printf("%c\n", 67);
    
    int x = 10;
    // I/O buffer에서 문자 하나만 꺼내는 함수
    putchar('B');
    putchar('\n');
    printf("%c\n", 'A');
    printf("%c\n", 65);
    
    printf("이것은 변수 x이고 값은 %d 입니다.\n\a", x);
    
    // %f는 double 자료형의 형식문자. 0.1F는 float 자료형을 의미. 단, float 자료형은 오차가 커서 쓰지 않음
    printf("%f\n", 0.1F + 0.1F + 0.1F);
    
    double dData = 123.456;
    printf("%f, %f\n", dData, -123.456);
    printf("%.1f\n", dData);  // 소수점 두번째 자리에서 반올림한 뒤 소수점 첫번째 자리까지만 출력
    printf("%.2f\n", dData);
    
    printf("%8d\n", 123);  // 정수 앞에 공백까지 포함해서 8자리로 출력
    printf("%12.3f\n", dData); // 실수를 4번째 자리에서 반올림 후 셋째자리까지 출력하되 실수와 앞에 공백 자리 포함해서 12자리를 출력
    printf("%012.3f\n", dData); // 실수를 4번째 자리에서 반올림 후 셋째자리까지 출력하되 실수와 앞에 공백이 아닌 0을 포함해서 12자리를 출력
    
    // sizeof(): 변수의 크기를 바이트 단위로 표시
    printf("%d\n", sizeof(123.456F));
    printf("%d\n", sizeof(123.456));
    
    printf("%f\n", 123.456F);  // 아래보다 오차가 커짐
    printf("%f\n", 123.456);
    
    printf("%lf\n", 123.456);  // lf: long double
    printf("%g\n", 123.456);   // g: long double 이되 끝에 0은 생략
    
    printf("%d\n", 1234);
    printf("%d, %d\n", 1234, -5678);
    printf("%+d, %+d\n", 1234, -5678);
     
    printf("%8d\n", 1234);  // 8자리로 출력하되 정수의 앞자리는 공백으로 채움
    printf("%08d\n", 1234); // 8자리로 출력하되 정수의 앞자리는 0으로 채움
    
    printf("%s\n", "Hello, World!"); // 문자(배)열은 %s 문자형식을 이용하고 반드시 쌍따옴표
    
    // 문자 32개로 구성된 문자열을 0으로 초기화하는데, 이 때 0을 문자로 바꾸면 null을 의미
    char szName[32] = { 0 };
    
    printf("이름을 입력하세요: ");
    // fgets(): 문자열을 입력받고, 입력받은 문자열의 크기도 매개변수로 넣어줌
    fgets(szName, sizeof(szName), stdin);
    
    printf("당신의 이름은 이것입니다\n");
    // puts(): 문자(배)열을 출력하는 함수. printf()와 달리 개행을 포함시켜 출력함
    puts(szName);
    puts("is your name.");

    char szName[4] = { 0 };
    
    printf("입력하세요:");
    fgets(szName, sizeof(szName), stdin); // 만약 크기가 4 이상의 문자열을 집어넣으면 메모리에는 4 크기까지만 할당됨. 단, 이때 \n까지 포함이기 떄문에 실질적으로 3개 문자밖에 못집어넣음
    printf("결과입니다\n");
    puts(szName);

    int age = 0;
    char szName[5] = { 0 };
    
    printf("나이를 입력하세요: ");
    // scanf() 입력을 받는 함수. 단, 메모리에 쓰기할 때는 변수이름 앞에 &을 넣어주어야 함. 이 &는 메모리 주소를 알려달라는 것이고 age의 메모리주소를 넣어줌으로써 메모리의 특정 주소에 값을 쓰도록 하는 것
    // 윈도우에서는 scanf_s() 함수와 대응
    scanf("%d", &age);
    printf("이름을 입력하세요: ");
    scanf("%s", szName); // 단, 문자(배)열의 경우 변수 이름 그 자체가 주소이기 때문에 & 없어도 됨. 구체적으로, 문자(배)열의 가장 첫번째 원소의 메모리 주소임

    printf("당신의 나이와 이름은 %d %s 입니다\n", age, szName);
    
    // 중요!!
    char szName[32] = { 0 };
    int nAge = 0;
    
    printf("나이를 입력하세요: ");
    // scanf("%d", &nAge);  // 나이를 입력하고 엔터를 침에따라 IO buffer에 \n까지 메모리에 저장됨. 그리고 입력한 나이의 값을 IO Buffer에서 꺼냄. 그러면 결국 IO Buffer에 \n만 남아있는 상태
    scanf("%d%*c", &nAge);  // %*c 라는 형식문자를 입력하는데, 문자 하나를 읽어서 그냥 날려버리라는 의미임
    printf("이름을 입력하세요: ");
    fgets(szName, sizeof(szName), stdin);  // 이제 이름을 입력받으려고 해보니 IO Buffer가 비어있어야하는데 \n이 있는 상태 -> 곧 사용자가 입력을 했다고 착각하고 \n을 입력한 것이라고 생각함
    
    printf("%d세 %s\n", nAge, szName);
    
    int nInput = 0;
    int x = 0, y = 0;
    printf("정수를 입력하세요: ");
    scanf("%d", &nInput); // scanf에서 \n을 입력하면 \n을 입력하는 것을 대기하게 됨. 그래서 정수를 입력하고 엔터를 쳐도 계속 \n이 남겨져 있는 상태. 그리고 어떤 문자를 쳐야 종료됨
    printf("두 정수를 입력하세요: ");
    scanf("%d%d", &x, &y); // 두 수를 입력받을 때 %d %d 이렇게 공백 있으면 안 됨!

    printf("%d\n", nInput);
    printf("%d\n", x + y);
    
    // scanf()는 공백이나 개행을 단위로 끊음
    char szBufferLeft[32] = { 0 };
    char szBufferRight[32] = { 0 };
    
    scanf("%s%s",
          szBufferLeft,
          szBufferRight);
    printf("%s %s \n", szBufferLeft, szBufferRight);
    
    // 변수는 선언할 때 정의(초기화) 해주는게 좋긴함
    char name[32] = { 0 };
    int nameAge = 0;
    
    printf("나이를 입력하세요: ");
    scanf("%d%*c", &nameAge);
    // MacOS에서는 윈도우와 달리 NFC가 아닌 NFD 인코딩 방식 즉, 완성형이 아닌 조합형으로 인코딩을 수행. 즉, '홍'이 있으면 완성현은 '홍' 한글자를 3바이트에 담지만 조합형은 'ㅎ','ㅗ','ㅇ' 이것들을 각각 3바이트에 담음..
    printf("이름을 입력하세요: ");
    fgets(name, sizeof(name), stdin);
    
    printf("%d살이고 %s", nameAge, name);
    return 0;
    
}

