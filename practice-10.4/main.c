#include <stdio.h>
#include "calc.h"

int main(void) {
    printf("=== Тестирование библиотеки calc ===\n\n");
    printf("10 + 5 = %d\n", add(10, 5));
    printf("10 - 5 = %d\n", sub(10, 5));
    printf("10 * 5 = %d\n", mul(10, 5));
    printf("10 / 5 = %d\n", div(10, 5));
    return 0;
}