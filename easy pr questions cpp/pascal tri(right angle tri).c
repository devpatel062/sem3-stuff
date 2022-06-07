#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int i,j,num;
	int mat[100][100];
	scanf("%d",&num);
	for(i=0;i<num;i++){
		
		for(j=0;j<i+1 && j<=num;j++){
			
			mat[j][0]=1;
			
			if(i>=2 && i!=j){
				
				mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
			}
			if(i==j){
				mat[i][j]=1;
			}
		}
	}
	
	for(i=0;i<num;i++){
		
		for(j=0;j<i+1 && j<num;j++){
			
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
return 0;

}