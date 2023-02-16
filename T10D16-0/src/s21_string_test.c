#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_string_test.h"

int main() {
#ifdef LEN
    // Quest_1
    // 1
    char *str = "Hello";
    s21_strlen_test(str, 5);
    // 2
    str = "";
    s21_strlen_test(str, 0);
    // 3
    str = "/n";
    s21_strlen_test(str, 1);
    // 4
    str = "Hello, WORLD! How are u?\n";
    s21_strlen_test(str, 40);
    // Quest_end
#endif

#ifdef CMP
    // Quest_2
    // 1
    char *str1 = "ok";
    char *str2 = "ok_21";
    s21_strcmp_test(str1, str2, 10);
    // 2
    str1 = "";
    str2 = "ok_21";
    s21_strcmp_test(str1, str2, 0);
    // 3
    str1 = "111111111111111111111111";
    str2 = "ok_21";
    s21_strcmp_test(str1, str2, -1);
    // 4
    str1 = "ok";
    str2 = "ok";
    s21_strcmp_test(str1, str2, 2);
    // Quest_end
#endif

#ifdef CPY
    // Quest_3
    // 1
    char str1[] = "ok";
    char str2[100] = "ojjjjj";
    s21_strcpy_test(str1, str2);
    // 2
    char str3[] = "";
    s21_strcat_test(str3, str2);
    // 3
    char str4[] = "Hello, WORLD! How are u?";
    s21_strcat_test(str4, str2);
    // 4
    char str5[] = "Hello, WORLD! How are u?";
    s21_strcat_test(str5, str2);
    // Quest_end
#endif

#ifdef CAT
    // Quest_4
    // 1
    char str1[] = "ok";
    char str2[100] = "7";
    s21_strcat_test(str1, str2);
    // 2
    char str3[] = "\0";
    s21_strcat_test(str3, str2);

    char str4[] = "Hello, WORLD! How are u?";
    s21_strcat_test(str4, str2);

    char str5[] = ".";
    s21_strcat_test(str5, str2);
    // Quest_end
#endif

    return 0;
}

void s21_strlen_test(const char *str, int lenth) {  // Quest_1
    printf("%s\n", str);
    int l = s21_strlen(str);
    printf("%d\n", l);
    if (l == lenth) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcmp_test(const char *str1, const char *str2, int lenth) {  // Quest_2
    printf("%s%s\n", str1, str2);
    int l = s21_strcmp(str1, str2);
    printf("%d\n", l);
    if (l == lenth) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
}

void s21_strcpy_test(char *str1, char *str2) {  // Quest_3
    char *l;
    printf("%s\n", str1);
    printf("%s\n", str2);
    if (*str1 != *str2) {
        l = s21_strcpy(str1, str2);
        printf("SUCCESS\n");
        printf("%s\n", l);
    } else {
        printf("FAIL\n");
    }
}

void s21_strcat_test(char *str1, char *str2) {  // Quest_4
    printf("%s\n", str1);
    printf("%s\n", str2);
    char *l = s21_strcat(str1, str2);
    printf("%s\n", l);
    if (!s21_strcmp(l, str1)) {
        printf("SUCCESS\n");

    } else {
        printf("FAIL\n");
    }
}