#include <stdio.h>



void display_pole(int y_roket_1, int y_roket_2, int x_ball, int y_ball, int shet_player_1,
                  int shet_player_2) {
    char temp = shet_player_1 / 10 + '0';
    int temp_2 = shet_player_2 / 10 + '0';
    char schet_1 = shet_player_1 % 10 + '0';
    char schet_2 = shet_player_2 % 10 + '0';

    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == y_ball && j == x_ball)
                printf("o");
            else if (j == 40)
                printf("|");
            else if (i == 5 && j == 33)
                printf("%c", temp);
            else if (i == 5 && j == 34)
                printf("%c", schet_1);
            else if (i == 5 && j == 45)
                printf("%c", temp_2);
            else if (i == 5 && j == 46)
                printf("%c", schet_2);
            else if ((i == y_roket_1 || i == y_roket_1 + 1 || i == y_roket_1 + 2) && j == 1)
                printf("[");
            else if ((i == y_roket_2 || i == y_roket_2 + 1 || i == y_roket_2 + 2) && j == 78)
                printf("]");
            else
                printf(" ");
        }
        printf("\n");
    }
}

//расчет координаты x
int X_ball(int centr, int v) {
    if (v == 1)
        centr -= 1;
    else if (v == -1)
        centr += 1;
    return (centr);
}

//расчет координаты y
int Y_ball(int centr, int v) {
    if (v == 1)
        centr -= 1;
    else if (v == -1)
        centr += 1;
    return (centr);
}


int main() {
    int y_roket_1 = 10, y_roket_2 = 10;  //положение ракеток
    int x_ball = 40, y_ball = 13;        //положение мяча
    int v_x = 1;                         //направление движения мача по оси х
    int v_y = 1;                         //направление движения мяча по оси у
    int shet_player_1 = 0, shet_player_2 = 0;  //счет игроков
    char A;
    while (1) {
        if (x_ball == 0)  //условие присвоения очка игроку #2
        {
            shet_player_2++;
            x_ball = 40;
            y_ball = 13;
        }
        if (x_ball == 80)  //условие присвоения очка игроку #1
        {
            shet_player_1++;
            x_ball = 40;
            y_ball = 13;
        }
        //Вызов функции отрисовки поля
        printf("\n");
        display_pole(y_roket_1, y_roket_2, x_ball, y_ball, shet_player_1, shet_player_2);
        //Условие победы того или иного игрока
        A = getchar();
        if (A == 'a' || A == 'A') (y_roket_1 != 0) ? y_roket_1-- : y_roket_1;
        if (A == 'z' || A == 'Z') (y_roket_1 != 21) ? y_roket_1++ : y_roket_1;
        if (A == 'k' || A == 'K') (y_roket_2 != 0) ? y_roket_2-- : y_roket_2;
        if (A == 'm' || A == 'M') (y_roket_2 != 21) ? y_roket_2++ : y_roket_2;
        if (shet_player_1 == 21 || shet_player_2 == 21) {
            if (shet_player_2 == 21)
                printf("\t\t\t\tПобеда игрока 2\n");
            else if (shet_player_1 == 21)
                printf("\t\t\t\tПобеда игрока 1\n");
            break;
        }
        //управление направлением мяча
        if (x_ball == 2 && (y_ball >= y_roket_1 && y_ball <= y_roket_1 + 3)) v_x = v_x * -1;
        if (x_ball == 80 - 2 && (y_ball >= y_roket_2 && y_ball <= y_roket_2 + 3)) v_x = v_x * -1;
        if ((y_ball == 0) || (y_ball == 25 - 1)) v_y = v_y * -1;
        //вызов функций для регулирования положением мяча
        x_ball = X_ball(x_ball, v_x);
        y_ball = Y_ball(y_ball, v_y);
        printf("\033[0d\033[2J");
    }
    return 0;
}
