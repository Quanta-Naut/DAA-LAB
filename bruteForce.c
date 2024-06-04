#include <stdio.h>
#include <string.h>

// Function to perform Brute Force String Matching
void bruteForceStringMatch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int i, j;

    // Loop through the text
    for (i = 0; i <= textLength - patternLength; i++) {
        // For current position, check for the pattern
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        // If the pattern is found
        if (j == patternLength) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100], pattern[100];

    // Input the text
    printf("Enter the text: ");
    gets(text);

    // Input the pattern
    printf("Enter the pattern: ");
    gets(pattern); // Remove newline character if present

    // Call the brute force string match function
    bruteForceStringMatch(text, pattern);

    return 0;
}

