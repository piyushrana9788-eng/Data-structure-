#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char s[500];
    printf("Enter a string: ");
    if (!fgets(s, sizeof s, stdin)) return 1;
    s[strcspn(s, "\n")] = '\0';

    int left = 0, right = (int)strlen(s) - 1, palindrome = 1;
    while (left < right) {
        if (tolower((unsigned char)s[left]) != tolower((unsigned char)s[right])) {
            palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (palindrome) printf("Palindrome.\n");
    else printf("Not a palindrome.\n");
    return 0;
}
