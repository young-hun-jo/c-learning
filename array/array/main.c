#include <stdio.h>

int main(void) {
    // 필수연습문제(1)
    int nList[5] = {50, 40, 10, 50, 20};
    int nMax = 0;
    
    for (int i = 0; i < 5; ++i) {
        if (nList[i] > nMax)
            nMax = nList[i];
    }
    printf("MAX: %d\n", nMax);
    
    // 필수연습문제(2)
    int nList[5] = {30, 40, 10, 50, 20};
    int nMin = nList[0];
    
    for (int i = 1; i < 5; ++i) {
        if (nMin > nList[i]) {
            nList[0] = nList[i];
            nList[i] = nMin;
            nMin = nList[0];
        }
        for (int j = 0; j < 5; ++j){
            printf("%d ", nList[j]);
        }
        putchar('\n');
    }
    
    // 필수연습문제(3) - 버블정렬
    int aList[5] = {3, 5, 1, 4, 2};
    
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 5; ++j) {
            if (aList[i] > aList[j]) {
                int temp = aList[i];
                aList[i] = aList[j];
                aList[j] = temp;
            }
        }
    }
    
    for (int k = 0; k < 5; ++k)
        printf("%d ", aList[k]);
    putchar('\n');
    
    // 필수연습문제(4) - 선택정렬
    int aList[5] = {3, 5, 1, 4, 2};
    
    for (int i = 0; i < 4; ++i) {
        int idxMin = i;
        for (int j = i+1; j < 5; ++j) {
            if (aList[idxMin] > aList[j])
                idxMin = j;
        }
        int temp = aList[i];
        aList[i] = aList[idxMin];
        aList[idxMin] = temp;
    }
    
    for (int k = 0; k < 5; ++k)
        printf("%d ", aList[k]);
    putchar('\n');
    
    // 필수연습문제(5)
    int aList[3][4] = {
        {10, 20, 30},
        {40, 50, 60}
    };
    for (int i = 0; i < 3; ++i) {
        if (i != 2) {
            int colSum = 0;
            for (int j = 0; j < 4; ++j) {
                if (j != 3) {
                    colSum += aList[i][j];
                    printf("%d ", aList[i][j]);
                }
                else {
                    aList[i][j] = colSum;
                    printf("%d ", colSum);
                }
            }
        }
        else {
            for (int j = 0; j < 4; ++j) {
                printf("%d ", aList[0][j] + aList[1][j]);
            }
        }
        putchar('\n');
    }
    
    // 필수연습문제(6)
    int aList[5][5] = { 0 };
    int value = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            aList[i][j] = ++value;
            printf("%d ", aList[i][j]);
        }
        putchar('\n');
    }
    
    
    return 0;
}
