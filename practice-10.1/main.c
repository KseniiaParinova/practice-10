#include <stdio.h>
#include "mathutils.h"

int main(void) {
    printf("=== Тестирование mathutils ===\n\n");
    
    printf("factorial(5) = %d\n", factorial(5));
    printf("factorial(10) = %d\n", factorial(10));
    printf("factorial(0) = %d\n", factorial(0));
    
    printf("\nfibonacci(10) = %d\n", fibonacci(10));
    printf("fibonacci(1) = %d\n", fibonacci(1));
    printf("fibonacci(20) = %d\n", fibonacci(20));
    
    printf("\ngcd(48, 18) = %d\n", gcd(48, 18));
    printf("gcd(17, 19) = %d\n", gcd(17, 19));
    printf("gcd(100, 25) = %d\n", gcd(100, 25));
    
    printf("\nlcm(4, 6) = %d\n", lcm(4, 6));
    printf("lcm(12, 18) = %d\n", lcm(12, 18));
    
    printf("\nis_prime(17) = %d\n", is_prime(17));
    printf("is_prime(18) = %d\n", is_prime(18));
    printf("is_prime(97) = %d\n", is_prime(97));
    
    return 0;
}