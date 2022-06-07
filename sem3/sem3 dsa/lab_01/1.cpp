#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,*eqn,*eqn1,i;
    
    scanf("%d",&n);
    eqn = (int *)malloc((n+1) * sizeof(int));
    eqn1 = (int *)malloc((n+1) * sizeof(int));
    
    for(i=0; i<n+1; i++){
        scanf("%d",&eqn[i]);
    }
    
     for(i=0; i<n+1; i++){
        scanf("%d",&eqn1[i]);
    }
    
    for(i=0; i<n+1; i++){
        printf("%d ",eqn[i] + eqn1[i]);
    }
    
    free(eqn);
    free(eqn1);
    return 0;
}