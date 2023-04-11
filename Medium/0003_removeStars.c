#include <stdio.h>

void removeStars(char *s) {
    if (s == NULL) {
        return;
    }

    int n = strlen(s);

    // Iterate through the string
    int k = 0; // Index of the last non-star character
    for (int i = 0; i < n; i++) {
        if (s[i] != '*') {
            // If the current character is not a star, keep it
            if (i > k) {
                s[k] = s[i];
            }
            k++;
        } else {
            // If the current character is a star, remove it along with the closest non-star character to its left
            int j = i - 1; // Index of the closest non-star character to the left

            // Find the closest non-star character to the left
            while (j >= 0 && s[j] == '*') {
                j--;
            }

            // Remove the closest non-star character and the current star
            if (j >= 0) {
                k = j;
            }
        }
    }

    // Null-terminate the resulting string
    s[k] = '\0';
}

int main() {
    char s1[] = "a*b*c";
    char s2[] = "*****";
    char s3[] = "abc";
    char s4[] = "a*b*c*d*e*";
    char s5[] = "a**b**c";

    printf("Before: %s\n", s1);
    removeStars(s1);
    printf("After: %s\n", s1);

    printf("Before: %s\n", s2);
    removeStars(s2);
    printf("After: %s\n", s2);

    printf("Before: %s\n", s3);
    removeStars(s3);
    printf("After: %s\n", s3);

    printf("Before: %s\n", s4);
    removeStars(s4);
    printf("After: %s\n", s4);

    printf("Before: %s\n", s5);
    removeStars(s5);
    printf("After: %s\n", s5);

    return 0;
}
