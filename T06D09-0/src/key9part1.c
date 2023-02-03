/*------------------------------------
    Здравствуй, человек!
    Чтобы получить ключ
    поработай с комментариями.
-------------------------------------*/

#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length, int number, int *numbers);
int sum_numbers(int *buffer, int length, int number);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
    Функция получает массив данных
    через stdin.
    Выдает в stdout особую сумму
    и сформированный массив
    специальных элементов
    (анвыбрных с помощью найденной суммы):
    это и будет частью ключа
-------------------------------------*/
int main() {
    int length, data[NMAX], number = 0, numbers;
    int result = 0;
    if (input(data, &length) == 1) {
        printf("n/a");
        result = 1;
    }
    output(data, length, number, &numbers);
    return result;
}

int input(int *buffer, int *length) {
    char c;
    int result = 0;
    if (scanf("%d%c", length, &c) != 2 || c != '\n' || *length > NMAX || *length <= 0) {
        result = 1;
    } else {
        for (int *p = buffer; p - buffer < *length; p++) {
            if (scanf("%d", p) != 1) {
                result = 1;
                break;
            }
        }
    }
    return result;
}

void output(int *buffer, int length, int number, int *numbers) {
    printf("%d\n", sum_numbers(buffer, length, number));
    find_numbers(buffer, length, number, numbers);
}

/*------------------------------------
    Функция должна находить
    сумму четных элементов
    с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length, int number) {
    number = 0;

    for (int *p = buffer; p < buffer + length; p++) {
        if (*p % 2 == 0) {
            number += *p;
        }
    }

    return number;
}

/*------------------------------------
    Функция должна находить
    все элементы, на которые нацело
    делится переданное число и
    записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    for (int *p = buffer; p < buffer + length; p++) {
        if (*p != 0) {
            if (sum_numbers(buffer, length, number) % *p == 0) {
                *numbers = *p;
                if (*p == buffer[length - 1]) {
                    printf("%d", buffer[length - 1]);
                } else {
                    printf("%d ", *numbers);
                }
            }
        }
    }
    return 0;
}
