#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int num,arr[26]={0},i=0,x;
    char *alp;
    
    scanf("%d",&num);
    
    alp = (char*)malloc(num*sizeof(char));
    
    for(int i=0;i<num+1;i++)
    {
       alp[i]=getchar();
    }
    
    while(alp[i] != '\0')
    {
        if(alp[i] >= 'a' && alp[i] <= 'z') 
        {
            x=alp[i]-'a';
            arr[x]++;
        }
        
        if(alp[i] >= 'A' && alp[i] <= 'Z')
        {
            x=alp[i]-'A';
            arr[x]++;
        }
        i++;
    }
    for(int j=0;j<26;j++)
    {
        printf("%d ",arr[j]);
    }
    return 0;
}
