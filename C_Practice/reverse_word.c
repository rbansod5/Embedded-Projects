#include <stdio.h>
#include <string.h>

void reverseWords(char *sentence) {
    int length = strlen(sentence);
    int start = 0, end = length - 1;

    // Reverse the entire sentence first
    reverseString(sentence, start, end);

    // Reverse each word in the reversed sentence to keep the words intact
    start = 0;
    for (end = 0; end <= length; end++) {
        if (sentence[end] == ' ' || sentence[end] == '\0') {
            reverseString(sentence, start, end - 1);
            start = end + 1;
        }
    }
}

void reverseString(char *str, int start, int end) {
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

    // Reverse the words in the sentence
    reverseWords(sentence);

    // Print the sentence with words in reverse order
    printf("Sentence with Reversed Word Order: %s\n", sentence);

    return 0;
}
