#include <stdio.h>
#include <stdlib.h>

#define ENG 26
#define RUS 32

void filetext(char c[]);    /// Quest_1
void filetext_2(char c[]);  /// Quest_2

void enCipher(int n, char directoriya_put[]);  /// Quest_3
void deCipher(int n, char directoriya_put[]);  /// Quest_3

int main() {
    int choice;
    char c[100];
    char directoriya_put[100];
    int nn;

    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%s", c);
                filetext(c);
                break;

            case 2:

                filetext_2(c);
                break;
            case 3:
                scanf("%s", directoriya_put);
                scanf("%d", &nn);
                enCipher(nn, directoriya_put);
                break;
            case 4:
                scanf("%d", &nn);
                deCipher(nn, directoriya_put);
                break;
            case -1:
                return 0;

            default:
                scanf("%*s");
                printf("n/a\n");
                break;
        }
    }

    return 0;
}

void filetext(char c[]) {  /// Quest_1

    char qq[100];

    FILE *f = fopen(c, "r+");

    if (f == NULL) {
        printf("n/a\n");

    } else {
        fscanf(f, "%s", qq);
        printf("%s\n", qq);
        fclose(f);
    }
}

void filetext_2(char c[]) {  /// Quest_2

    char qqq[100];

    char c2[1000];
    scanf("%s", c2);

    FILE *f = fopen(c, "r+");

    if (f == NULL) {
        printf("n/a\n");

    } else {
        fscanf(f, "%s", qqq);
        fputs(c2, f);
        printf("%s\n", qqq);
        printf("%s\n", c2);
        fclose(f);
    }
}

void enCipher(int nn, char directoriya_put[]) {  /// Quest_3

    FILE *fp1 = fopen(directoriya_put, "r+");
    FILE *fp2 = fopen(directoriya_put, "r+");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1)) {
        flag = 0;
        if (c >= 'A' && c <= 'Z') {
            c = c + (nn % ENG);
            if (c > 'Z') c = 'A' + (c - 'Z') - 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z') {
            c = c + (nn % ENG);
            if (c > 'z') c = 'a' + (c - 'z') - 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }

        if (!flag) fprintf(fp2, "%c", c);

        c = getc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
}

void deCipher(int nn, char directoriya_put[]) {  /// Quest_3

    FILE *fp1 = fopen(directoriya_put, "r+");
    FILE *fp2 = fopen(directoriya_put, "r+");
    int flag;
    char c;
    c = getc(fp1);
    while (!feof(fp1)) {
        flag = 0;
        if (c >= 'A' && c <= 'Z') {
            c = c - (nn % ENG);
            if (c < 'A') c = 'Z' - ('A' - c) + 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (c >= 'a' && c <= 'z') {
            c = c - (nn % ENG);
            if (c < 'a') c = 'z' - ('a' - c) + 1;
            fprintf(fp2, "%c", c);
            flag = 1;
        }
        if (!flag) fprintf(fp2, "%c", c);
        c = getc(fp1);
    }
    fclose(fp1);
    fclose(fp2);
}
