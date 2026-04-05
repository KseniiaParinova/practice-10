#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strutils.h"

char *str_reverse(const char *s) {
    if (s == NULL) return NULL;
    
    size_t len = strlen(s);
    char *result = malloc(len + 1);
    if (result == NULL) return NULL;
    
    for (size_t i = 0; i < len; i++) {
        result[i] = s[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

char *str_to_upper(const char *s) {
    if (s == NULL) return NULL;
    
    size_t len = strlen(s);
    char *result = malloc(len + 1);
    if (result == NULL) return NULL;
    
    for (size_t i = 0; i < len; i++) {
        result[i] = toupper((unsigned char)s[i]);
    }
    result[len] = '\0';
    return result;
}

char *str_to_lower(const char *s) {
    if (s == NULL) return NULL;
    
    size_t len = strlen(s);
    char *result = malloc(len + 1);
    if (result == NULL) return NULL;
    
    for (size_t i = 0; i < len; i++) {
        result[i] = tolower((unsigned char)s[i]);
    }
    result[len] = '\0';
    return result;
}

char *str_trim(const char *s) {
    if (s == NULL) return NULL;
    
    size_t len = strlen(s);
    size_t start = 0;
    size_t end = len;
    
    while (start < len && isspace((unsigned char)s[start])) start++;
    while (end > start && isspace((unsigned char)s[end - 1])) end--;
    
    size_t new_len = end - start;
    char *result = malloc(new_len + 1);
    if (result == NULL) return NULL;
    
    memcpy(result, s + start, new_len);
    result[new_len] = '\0';
    return result;
}

int str_word_count(const char *s) {
    if (s == NULL) return 0;
    
    int count = 0;
    int in_word = 0;
    
    while (*s) {
        if (isspace((unsigned char)*s)) {
            in_word = 0;
        } else {
            if (!in_word) {
                count++;
                in_word = 1;
            }
        }
        s++;
    }
    return count;
}