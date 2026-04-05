#include <stdio.h>
#include <stdlib.h>
#include "strutils.h"

int main(void) {
    const char *test = "   Hello   World   ";
    
    printf("=== Тестирование strutils ===\n\n");
    printf("Original: \"%s\"\n", test);
    
    char *reversed = str_reverse(test);
    printf("Reversed: \"%s\"\n", reversed);
    free(reversed);
    
    char *upper = str_to_upper(test);
    printf("Upper:    \"%s\"\n", upper);
    free(upper);
    
    char *lower = str_to_lower(test);
    printf("Lower:    \"%s\"\n", lower);
    free(lower);
    
    char *trimmed = str_trim(test);
    printf("Trimmed:  \"%s\"\n", trimmed);
    free(trimmed);
    
    int words = str_word_count(test);
    printf("Words:    %d\n", words);
    
    return 0;
}