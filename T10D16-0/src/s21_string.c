#include "s21_string.h"

#include <stdio.h>

int s21_strlen(const char *str) {  // Quest_1
    int lenth = 0;
    for (; *(str + lenth); lenth++) {
    }
    return lenth;
}

int s21_strcmp(const char *str1, const char *str2) {  // Quest_2
    int i = 100;
    for (; *str1 && *str1 == *str2; str1++, str2++)
        ;
    int result = *str1 - *str2;
    if (result < 0) {
        i = -1;
    } else if (result > 0) {
        i = 1;
    } else {
        i = 0;
    }
    return i;
}

char *s21_strcpy(char *str1, const char *str2) {  // Quest_3
    if (str2 != NULL) {
        for (int i = 0; (str1[i] = str2[i]) != '\0'; i++)
            ;
    }
    return str1;
}

char *s21_strcat(char *str1, char *str2) {  // Quest_4
    int i, j;
    for (i = 0; str1[i] != '\0'; i++)
        ;
    for (j = 0; str2[j] != '\0'; j++) {
        str1[i + j] = str2[j];
    }
    str1[i + j] = '\0';

    return str1;
}