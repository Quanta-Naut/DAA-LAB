#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    int text[125];
    char t[100], p[25];
    int i,j,k,m,n,flag=0;
    printf("Enter text: ");
    gets(t);
    printf("Enter text: ");
    gets(p);
    n=strlen(t);
    m = strlen(p);

    for(i=0; i<126; i++){
        text[i] = m;
    }
    for(j = 0; j<m-2; j++){
        text[p[j]] = m-1-j;
    }
    i = m-1;
    while(i<=n-1){
        k=0;
        while((k<=m-1) && p[m-1-k] == t[i-k]){
            k++;
        }
        if(k==m){
            printf("Pattrn found at: %d", i-m+2);
            flag = 1;
            break;
        }
        else{
            i=i+text[t[i]];
        }
    }
    if(!flag){
        printf("Pattern not found!!!");
    }


    return 0;
}
