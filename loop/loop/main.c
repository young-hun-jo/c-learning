#include <stdio.h>

int main(void) {
    // while문 필수연습문제(1)
    int n = 0;
    int nInput = 1;
    while (nInput <= 2) {
        scanf("%d", &n);
        if (n > 9)
            n = 9;
        else if (n < 1)
            n = 1;
        
        int i = 1;
        while (i <= n) {
            putchar('*');
            ++i;
        }
        printf("\n");  // putchar('\n')도 가능
        ++nInput;
    }
    
    // 필수연습문제(2)
    int iWhile = 0, sumWhile = 0;
    while (iWhile < 10) {
        ++iWhile;
        sumWhile += iWhile;
    }
    printf("Total(while): %d\n", sumWhile);
    
    int sumFor = 0;
    for (int i = 1; i <= 10; ++i) {
        sumFor += i;
    }
    printf("Total(for): %d\n", sumFor);
    
    // 필수연습문제(3)
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("* ");
        }
        putchar('\n');
    }
    
    // 필수연습문제(4)
    for (int i = 1; i <= 5; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("* ");
        }
        putchar('\n');
    }
    
    // 필수연습문제(5)
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i + j < 4)
                printf("  ");
            else
                printf("* ");
        }
        putchar('\n');
    }
    
    // 필수연습문제(6)
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5 + i; ++j) {
            if (i + j < 4)
                printf("  ");
            else
                printf("* ");
        }
        putchar('\n');
    }
    return 0;
}
