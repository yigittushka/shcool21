#include <stdio.h>
#include <stdlib.h>
#define SIZE 300
// ../datasets/door_state_1

typedef struct dateOfTime {
    int year, month, day, hour, minute, second, status, code;
} Data;

void read_DOFT(FILE *file);
void print_DOFT(Data *DOFT);
void sort_DOFT(FILE *file);

int main() {
    char size_of_data[SIZE];
    int number;
    scanf("%300s", size_of_data);
    FILE *file = fopen(size_of_data, "r+b");
    if (file != NULL) {
        while (1) {
            scanf("%d", &number);
            switch (number) {
                case 0:
                    read_DOFT(file);
                    break;
                case 1:
                    read_DOFT(file);
                    sort_DOFT(file);
                    break;
                case 2:
                    fclose(file);
                    break;
                default:
                    scanf("%*s");
                    printf("n/a\n");
                    break;
            }
        }
    }
    return 0;
}

void read_DOFT(FILE *file) {
    Data DOFT[1];
    while (fread(DOFT, sizeof(DOFT), 1, file)) {
        print_DOFT(DOFT);
    }
}

void sort_DOFT(FILE *file) {
    Data DOFT1, DOFT2;
    int i = 0;
    while (i < 5) {
        fread(&DOFT1, sizeof(DOFT1), 1, file);
        fread(&DOFT2, sizeof(DOFT1), 1, file);
        fseek(file, 2 * sizeof(DOFT1), SEEK_CUR);
        int position = ftell(file);
        printf("%d\n", position);
        fwrite(&DOFT2, sizeof(DOFT2), 1, file);
        fwrite(&DOFT1, sizeof(DOFT1), 1, file);
        fseek(file, 1 * sizeof(DOFT1), SEEK_CUR);
        i++;
    }
}

void print_DOFT(Data *DOFT) {
    printf("%d %d %d %d %d %d %d %d\n", DOFT->year, DOFT->month, DOFT->day, DOFT->hour, DOFT->minute,
           DOFT->second, DOFT->status, DOFT->code);
}
