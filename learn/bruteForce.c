#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool bruteForce(char text[], char pattern[]){
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    // printf("%d    %d", textLength, patternLength);
    int i, j;

    for(i = 0; i <= textLength - patternLength; i++){
        for(j = 0; j < patternLength; j++){
            if(text[i+j] != pattern[j]){
                break;
            }
        }
        if(j == patternLength){
            printf("The pattern found at: %d\n", i);
            return true;
        }
    }
    return false;
}
int main(){
    char text[10], pattern[10];
    printf("Enter the text: ");
    gets(text);
    printf("Enter the patter: ");
    gets(pattern);

    bool val = bruteForce(text, pattern);
    if(val == false){
        printf("Pattern not found!!!");
    }
}