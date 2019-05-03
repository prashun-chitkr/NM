#include <stdio.h>
#include <stdlib.h>

int main(){
    int x[] = {5, 7, 11, 13, 17};
    int y[] = {150, 392, 1452, 2366, 5202};
    int denum[4][4], d[4][4], i, j, k=1;


    for(i = 0; i<4 ; i++){
        for(j=0; j<4; j++){
            if(j<5-k)
                denum[i][j] = x[j+k] - x[j];
            else
                denum[i][j] = -1;
        }
        ++k;
    }

    k = 0;

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(i==0)
                d[0][j] = (y[j+1] - y[j]) / denum[0][j];
            else if(j < 4-k)
                d[i][j] = (d[i-1][j+1]-d[i-1][j]) / denum[i][j];
            else
                d[i][j] = -1;
        }
        ++k;
    }

    printf("x\ty\tdd1\tdd2\tdd3\tdd4\n\n");

    for(i = 0; i < 9; i++){
        if(i%2==0){
            printf("%d\t%d\t", x[i/2], y[i/2]);
            for(j = 0; j < 4; j++){
                if((i==2||i==4||i==6) && j==1){
                    printf("\t%d\t", d[1][i/2-1]);
                }
                else if(i==4 && j == 3){
                    printf("\t%d", d[3][0]);
                }
            }
        }
        else{
            printf("\t\t");
            for(j = 0; j < 4; j++){
                if(i%2==1 && j==0)
                        printf("%d\t", d[0][i/2]);
                else if((i==3 || i ==5) && j==2)
                    printf("\t%d\t", d[2][i/2-1]);
            }
        }
        putchar('\n');
    }
    return 0;
}
