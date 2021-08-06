//copyright thetaxjan
#include <stdio.h>
#define ROW 4 // 行数
#define COL 7 // 列数
#define VAR 3 // 変数の数
double min, p, d;
int i, j, k, x, y, flag;
void simplex(){
    static double a[ROW][COL] = {
        {2.0, 1.0, 1.0, 1.0, 0.0, 0.0, 60.0},
        {1.0, 2.0, 1.0, 0.0, 1.0, 0.0, 60.0},
        {0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 30.0},
        {-8.0, -9.0, -10.0, 0.0, 0.0, 0.0, 0.0}};
    while (1){
        min = 9999;
        for (k = 0; k < COL - 1; k++){
            if (a[ROW - 1][k] < min){
                min = a[ROW - 1][k];
                y = k;
            }
        }
        if (min >= 0)
            break;

        min = 9999;
        for (k = 0; k < ROW - 1; k++){
            p = a[k][COL - 1] / a[k][y];
            if (a[k][y] > 0 && p < min){
                min = p;
                x = k;
            }
        }

        p = a[x][y];

        for (k = 0; k < COL; k++)
            a[x][k] = a[x][k] / p;
        for (k = 0; k < ROW; k++){
            if (k != x){
                d = a[k][y];
                for (j = 0; j < COL; j++)
                    a[k][j] = a[k][j] - d * a[x][j];
            }
        }
    }
    for (k = 0; k < VAR; k++){
        flag = -1;
        for (j = 0; j < ROW; j++){
            if (a[j][k] == 1){
                flag = j;
            }
            else if (flag != -1 && a[j][k] != 0){
                flag = -1;
                break;
            }
        }
        if (flag != -1)
            printf("x%d = %8.2f\n", k + 1, a[flag][COL - 1]);
        else
            printf("x%d = %8.2f\n", k + 1, 0.0);
    }
    printf("z  = %8.2f\n", a[ROW - 1][COL - 1] * 100);
}

int main(){
    simplex();
    return 0;
}