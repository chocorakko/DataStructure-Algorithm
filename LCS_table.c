//copyright thetaxjan
#include <stdio.h>
#include<string.h>
int main(){
    char X[] = "abcb";
    char Y[] = "bdcab";
    int m=strlen(X);
    int n=strlen(Y);
    int value[m+1][n+1];
    int direction[m+1][n+1];
    int i,j;

    //LCS(M,N);
    for (i=0; i<=m; i++){
	    for (j=0; j<=n; j++){
	    if (i == 0 || j == 0){
            value[i][j] = 0;
            direction[i][j] = 0;
        }else if (X[i-1] == Y[j-1]){
            value[i][j] = value[i-1][j-1] + 1;
            direction[i][j] = 1; //左下から(一致)
        }else if(value[i][j-1] > value[i-1][j]){
            value[i][j] = value[i][j-1];
            direction[i][j] = 2; //左から
        }else{
            value[i][j] = value[i-1][j];
            direction[i][j] = 3; //上から
        }
	    }
    }
    printf("LCSの長さ：%d\n", value[m][n]);
    
    //printTable(M,N);
    for (i=0; i<=m; i++){
        for (j=0; j<=n; j++){
            printf("%d(%d)\t",value[i][j],direction[i][j]);
        }
        printf("\n");
    }

    //最適解の構築
    int p=m; int q=n;
    int z=value[p][q];
    char Z[z];
    while(p!=0 && q!=0){
        if(direction[p][q] == 1){ //左下から(一致)
            printf("1:");
            z--;
            p=p-1; q=q-1;
            Z[z]=X[p];
            printf("%c\n",X[p]);
        }else if(direction[p][q] == 2){ //左から
            printf("2\n");
            q=q-1;
        }else if(direction[p][q] == 3){ //上から
            printf("3\n");
            p=p-1;
        }
    }
    printf("最適解：%s\n",Z);
    return 0;
}