#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // (1)
    int nData = 10;
    
    printf("%s\n", "nData"); // nData 라는 문자열 상수의 첫번째 요소의 메모리 주소(&)에 있는 값 즉,`n`부터 `null`이 나올떄까지 쭉 출력해주게 동작
    printf("%d\n", nData);
    printf("%p\n", &nData);
    
    int x = 10;
    int* pnData = &x;

    // (2)
    char szBuffer[16] = { "Hello" };
    char* pszData = szBuffer;  // pszData라는 포인터 변수에 szBuffer 라는 문자열 기준 요소의 주소값을 간접지정. szBuufer는 메모리 주소 상수이므로 R-value!
    
    while (*pszData != '\0') // 간접지정한 pszData에 간접지정 연산을 또 취해버리니 문자(char)가 됨. 그 문자가 `null`인지 비교
        pszData++;           // `null`이 아니면 즉 문자열의 끝이 나올때까지 pszData 라는 포인터 변수에 단항 증가 연산 수행. 즉, 문자열이니까 1byte 만큼 메모리 주소를 증가시킴
    
    printf("&pszData: %p, &szBuffer: %p\n", pszData, szBuffer);
    // pszData는 계속 증가한 메모리 주소, szBuffer는 초기 메모리 주소. 즉 이 둘의 차이를 구했다는 것은 문자열의 길이를 구하는 셈임
    printf("Length: %d\n", pszData - szBuffer);
    
    // (3)
    // 정수(int) 포인터 변수로서 pList를 간접 지정으로 정의 및 선언. 고로 pList에는 메모리 주소가 들어있음
    int* pList = NULL;
    // OS에게 메모리를 요청. int가 4byte니까 총 12byte를 할당 받음. 고로 int[3]가 됨
    // 이 때 malloc()이 메모리 주소를 반환하는데, 메모리 주소를 간접지정했던 pList에 간집지정 연산을 수행하면 int 형으로 변환
    pList = (int*)malloc(sizeof(int) * 3);
    
    // pList는 곧 정수 1차원 배열(int[3])과 100% 호환되므로 해당 1차원 배열 요소 덮어쓰기
    pList[0] = 10;
    pList[1] = 20;
    pList[2] = 30;
    pList[3] = 40;  // 만약 malloc()으로 요청한 사이즈를 넘어서서 점유한다면 메모리를 반납(free)할 때 에러 발생(이는 모두 런타임때 발생)
    
    for (int i = 0; i < 3; ++i) {
        printf("%d\n", pList[i]);
    }
    
    // OS로부터 받은 메모리 반납
    free(pList);
     
    // (4)
    // []로 지정해도 컴파일러가 알아서 Hello를 보고 길이 6으로 잡음
    char szBuffer[] = { "Hello" };
    char* pszBuffer = "Hello";
    char* pszData = NULL;  // 포인터 변수 초기화
    
    // 초기화한 포인터 변수에 담겨있는 메모리 주소가 가리키는 데이터를 담기 위해 메모리 할당받음
    // malloc()으로 6바이트 길이의 메모리를 할당 받음. malloc()이 반환하는 포인터 주소에 간접지정(*)연산을 함에 따라 char 형식이 됨 -> 1차원 배열과 100% 호환!
    pszData = (char*)malloc(sizeof(char) * 6);
    
    pszData[0] = 'H';
    pszData[1] = 'e';
    pszData[2] = 'l';
    pszData[3] = 'l';
    pszData[4] = 'o';
    pszData[5] = '\0';
    
    puts(szBuffer);
    puts(pszBuffer);
    puts(pszData);
    // malloc()으로 할당 받은 메모리 OS에 반납
    free(pszData);
    
    // (5) 메모리 초기화
    int* pList = NULL, * pNewList = NULL;
    int aList[3] = { 0 };
    
    pList = (int*)malloc(sizeof(int) * 3);
    memset(pList, 0, sizeof(int) * 3);  // 0으로 초기화
    
    pNewList = (int*)calloc(3, sizeof(int)); // malloc + memset(0으로 초기화)를 한꺼번에 수행 해줌
    
    for (int i = 0; i < 3; ++i)
        printf("pList[%d]: %d\n", i, pList[i]);
    for (int i = 0; i < 3; ++i)
        printf("pNewList[%d]: %d\n", i, pNewList[i]);
    
    free(pList);
    free(pNewList);
    
    // (6) 메모리 값 복사(매우 중요)
    // (6-1) memcpy(dest, src, n of byte) 함수 사용
    char szBuffer[12] = { "HelloWorld" };
    char szNewBuffer[12] = { 0 };
    
    memcpy(szNewBuffer, szBuffer, 4);
    puts(szNewBuffer);
    memcpy(szNewBuffer, szBuffer, 6);
    puts(szNewBuffer);
    memcpy(szNewBuffer, szBuffer, sizeof(szBuffer));
    puts(szNewBuffer);
    
    // (6-2) memcpy() 쓰지 않고 개별요소하나씩 복사(이것이 memcpy()가 내부적으로 동작하는 방식)
    char szBuffer[12] = { "HelloWorld" };
    char* pszData = NULL;
    
    pszData = (char*)malloc(sizeof(char) * 12);
    for (int i = 0; i < 12; ++i)
        pszData[i] = szBuffer[i];
    puts(pszData);
    
    // (6-3) 메모리 값 비교 => 반드시 전용함수를 사용해야 함
    char szBuffer[12] = { "TestString" };
    char* pszData = "TestString";
    // 컴퓨터는 비교를 할 때 뺄셈을 한다!
    // [메모리초기화,복사,비교] 강의 속 17분20초 참고
    printf("%d\n", memcmp(szBuffer, pszData, 10));
    printf("%d\n", memcmp("testString", pszData, 10)); // 32가 나오는데 이유는 `T의 ASCII 코드값(84) - t의 ASCII 코드값(116)` 이기 때문. 단! 기준 요소만으로만 비교함! 왜? 배열의 메모리는 기준 요소의 메모리잖아!
    printf("%d\n", memcmp("DataString", pszData, 10)); // TestString
    
    // (7)
    // szBuffer 배열, pszData도 문자열 배열 -> 그런데 배열의 메모리 복사를 단순대입으로 한 것이 에러!
    char szBuffer[12] = { "HelloWorld" };
    char* pszData = NULL;
    pszData = (char*)malloc(sizeof(char) * 12);
    
    // 만약 이렇게 하고 free를 하면 결국 szBuffer 메모리 주소를 clear하는 것인데, szBuffer는 지역변수로 stack 메모리에서 자동관리되고 있음. 그래서 이를 날려버리려 하니까 에러 발생
    // pszData = szBuffer;
    memcpy(pszData, szBuffer, sizeof(szBuffer));
    // strcpy(dest, src) 함수도 있음. 이는 문자열 메모리 복사에 주로 쓰임!
    
    puts(pszData);
    
    free(pszData);
    
    // (8)
    char szBuffer[32] = { "You are a girl." };
    char* pzBuffer = szBuffer;
    
    printf("%c\n", szBuffer[0]);
    printf("%c\n", *szBuffer); // 메모리 주소에 간접지정 연산하면 변수가 됨
    printf("%c\n", *pzBuffer); // 포인터 변수에 간접지정 연산하면 변수가 됨
    
    printf("%c\n", szBuffer[5]);
    printf("%c\n", *(szBuffer + 5)); // 배열 기준 요소에서 5번째 떨어져있는 메모리 주소에 간접지정 연산하면 변수가 됨
    printf("%c\n", *szBuffer + 5); // 이는 *(szBuffer+5) 결과와 다름 *szBuffer 문자의 ASCII 코드 값에 5를 더한 ASCII 코드값에 속하는 문자
    
    printf("%s\n", &szBuffer[4]); // szBuffer[4]라는 L-value의 주소연산자(&)
    printf("%s\n", &*(szBuffer + 4)); // szBuffer[4] 랑 *(szBuffer+4)랑 동일. 그리고 주소 연산자는 간접 지정 연산자랑 정반대(Q.질문)이므로 두개가 만나 없어지는 셈
    printf("%s\n", szBuffer + 4); // 결국 이렇게 되는셈인데, 이는 메모리 주소를 의미. 이는 szBuffer + 4 메모리 주소부터 null이 나올때까지 계속 출력
    printf("%p\n", szBuffer + 4);

    char *p="KOREA" ;
    printf("%s\n",p);
    printf("%s\n",p+3);
    printf("%c\n", *p);
    printf("%c\n",*(p+3));
    printf("%c\n", *p+2);

    return  0;
}
