#include <stdio.h>
#include <stdlib.h>

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
    return  0;
}
