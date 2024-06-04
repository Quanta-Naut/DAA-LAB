#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 30
int position[size] = {0};


int place(int k){
    for(int i = 1; i<k; i++){
        if((position[i] == position[k]) || (abs(position[i]-position[k]) == abs(i-k))){
            return 0;
        }
    }
    return 1;
}

void print_sol(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(position[i] == j){
                printf("Q  ");
            }
            else{
                printf("*  ");
            }
        }
        printf("\n");
    }
}

int queen(int k, int n){
    if(k==0){
        return 0;
    }
    position[k] = position[k] +1;
    while((position[k]<=n) && (!place(k))){
        position[k]++;
    }
    if(position[k]<=n){
        if(k==n){
            print_sol(n);
            return 1;
        }
        else{
            position[++k] = 0;
            queen(k,n);
        }
    }
    else{
        queen(k-1,n);
    }
}
int main(){
	int n;
	printf("Enter the number of Queens\n");
	scanf("%d",&n);
	if(!queen(1,n)) /*1 is for the first queen*/
		printf("\n No valid solution!\n");
}


