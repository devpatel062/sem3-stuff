#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int r1,c1,r2,c2;
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    if(c1==r2)
    {
        int **matrix1 = calloc(r1, sizeof(int *));
        int **matrix2 = calloc(r2, sizeof(int *));
        int **result = calloc(r1,sizeof(int *));
        
        for(int i=0;i<r1;i++)
        {
            matrix1[i] = calloc(c1,sizeof(int));
            for(int j=0;j<c1;j++)
            {
                scanf("%d",&matrix1[i][j]);
            }
               
        }
        
        for(int i=0;i<r2;i++)
        {
            matrix2[i] = calloc(c1,sizeof(int));
            for(int j=0;j<c2;j++)
                scanf("%d",&matrix2[i][j]);   
        }
        
        for(int i=0;i<r1;i++)
            result[i] = calloc(c2,sizeof(int));
        
        printf("%d\t%d\n",r1,c2);
        
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c2;j++)
            {
                for(int k=0;k<c1;k++)
                    result[i][j] += matrix1[i][k]*matrix2[k][j];
                printf("%d\t",result[i][j]);
            }
            printf("\n");
        }
        
        for(int i=0;i<r1;i++)
        {
            free(matrix1[i]);
            free(result[i]);
        }
        
        for(int i=0;i<r2;i++)
            free(matrix2[i]);

        free(result);
        free(matrix1);
        free(matrix2);
        
    }
    else
        printf("-1");
    return 0;
}