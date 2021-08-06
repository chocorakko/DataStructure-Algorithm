//copyright thataxjan
#include <stdio.h>
#define N 10
int price[N+1] = {0,1,5,8,9,10,17,17,20,24,30};
int value[N+1];
int cut[N+1];

void CutRod(int n){
    int i,j;
    for(i=0; i<=n; i++){
        int r=0;
        for(j=1; j<=i; j++){
            if(r<(price[j]+value[i-j])){
                r=price[j]+value[i-j];
                cut[i]=j;
            }
        }
        value[i]=r;
    }
}

void printCut(int n){
    while(n>0){
        printf("長さ %-2d :価格 %-2d | ",cut[n],value[cut[n]]);
        n=n-cut[n];
    }
}

int main(){
    CutRod(N);
    printf("Maximum Obtainable Value is %d\n", value[N]);
    for(int i=0; i<=N; i++){
        printf("p[%-2d]=%-2d \t r[%-2d]=%-2d \t",i,price[i],i,value[i]);
        printCut(i);
        printf("\n");
    }
    return 0;
}