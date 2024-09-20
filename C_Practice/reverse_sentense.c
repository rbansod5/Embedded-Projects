#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    int start = 0, end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char sentence[100];

    // Ask the user to enter a sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character from the input if present
    sentence[strcspn(sentence, "\n")] = 0;

    // Reverse the entire sentence
    reverseString(sentence);

    // Print the reversed sentence
    printf("Reversed Sentence: %s\n", sentence);

    return 0;
}
