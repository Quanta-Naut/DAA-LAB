#include<stdio.h>

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int knap(int W, int wt[], int val[], int n){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knap(W,wt,val,n-1);
    }
    else{
        return max((val[n-1] + knap(W-wt[n-1], wt,val, n-1)), knap(W,wt,val,n-1));
    }
}

int main(int argc, char const *argv[])
{
    int wt[] = {10,10,10};
    int val[] = {10,20,30};
    int W = 20;
    int n =3;
    printf("%d\n",knap(W,wt,val,n));
    return 0;
}
