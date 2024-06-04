#include<stdio.h>

void count(int a[], int n, int k){
    int b[15], c[100];
    for(int i=0; i<=k; i++){
        c[i] = 0;
    }
    for(int j=1; j<=n; j++){
        c[a[j]] = c[a[j]] + 1;
    }
    for(int i=1; i<=k; i++){
        c[i] = c[i] + c[i-1];
    }
    for(int j=n; j>=1; j--){
        b[c[a[j]]] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }
    printf("Sorted array: ");
    for(int i=1; i<=n; i++){
        printf("%d ", b[i]);
    }
}
int main(int argc, char const *argv[])
{
    int n,k = 0,a[15];
    printf("Enter num of ele: ");
    scanf("%d", &n);
    printf("Enter the array: ");
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if(a[i]>k){
            k=a[i];
        }
    }
    count(a, n, k);
    return 0;
}
