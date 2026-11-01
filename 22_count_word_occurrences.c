#include <stdio.h>
#include <string.h>
#include <ctype.h>

int equal_word(const char *a, size_t n, const char *b) {
    if (strlen(b) != n) return 0;
    for (size_t i = 0; i < n; i++)
        if (tolower((unsigned char)a[i]) != tolower((unsigned char)b[i])) return 0;
    return 1;
}

int main(void) {
    char sentence[1000], word[100];
    int count = 0;
    printf("Enter a sentence: ");
    if (!fgets(sentence, sizeof sentence, stdin)) return 1;
    sentence[strcspn(sentence, "\n")] = '\0';
    printf("Enter the word to count: ");
    if (!fgets(word, sizeof word, stdin)) return 1;
    word[strcspn(word, "\n")] = '\0';

    if (word[0] == '\0') {
        printf("Word cannot be empty.\n");
        return 1;
    }

    size_t i = 0;
    while (sentence[i] != '\0') {
        while (sentence[i] != '\0' && !isalnum((unsigned char)sentence[i])) i++;
        size_t start = i;
        while (sentence[i] != '\0' && isalnum((unsigned char)sentence[i])) i++;
        if (i > start && equal_word(sentence + start, i - start, word)) count++;
    }

    printf("Occurrence count = %d\n", count);
    return 0;
}
