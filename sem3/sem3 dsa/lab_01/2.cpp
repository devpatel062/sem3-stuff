#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,*eqn,*eqn1,i;
     int *feqn;
    
    scanf("%d",&n);
    eqn = (int *)malloc((n+1) * sizeof(int));
    eqn1 = (int *)malloc((n+1) * sizeof(int));
    feqn = (int *)calloc(((n*2)+1) , sizeof(int));
    
    for(i=0; i<n+1; i++){
        scanf("%d",&eqn[i]);
    }
    
     for(i=0; i<n+1; i++){
        scanf("%d",&eqn1[i]);
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            *(feqn+i+j) = *(feqn+i+j)+ ((*(eqn + i)) * (*(eqn1 + j)));
        }
    }
    
    for(int i = 0; i <= n * 2 ; i++)
    {
        printf("%d ", *(feqn + i));
    } 
    
    free(eqn);
    free(eqn1);
    free(feqn);

    return 0;
}
