#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function to check if two strings match considering wildcard characters
bool isMatch(char *str1, char *str2) {
    // Pointers to traverse both strings
    char *s1 = str1, *s2 = str2;
    // Pointers to store the positions when '*' and '?' are encountered
    char *star = NULL, *ques = NULL;

    // Traverse until the end of the first string
    while (*s1 != '\0' && *s2 != '\0') {
        // If current characters match or '?' is encountered
        if (*s2 == *s1 || *s2 == '?') {
            s1++;
            s2++;
        }
        // If '*' is encountered in the second string
        else if (*s2 == '*') {
            star = s2; // Store the position of '*'
            ques = s1; // Store the position of corresponding character in the first string
            s2++;      // Move to the next character in the second string
        }
        // If characters don't match and there is no '*' in the second string
        // Go back to the last '*' position and try to match from there
        else if (star != NULL) {
            s2 = star + 1; // Move to the next character after '*'
            s1 = ++ques;   // Move to the next character in the first string from the last '*' position
        } else {
            return false; // If no '*' encountered and characters don't match, return false
        }
    }

    // Ignore any extra '*' characters in the second string
    while (*s2 == '*') {
        s2++;
    }

    // If both strings have reached the end, return true
    return (*s1 == '\0' && (*s2 == '\0' || (*s2 == '*' && *(s2+1) == '\0')));
}

int main() {
    // Input two strings terminated by '#'
    char str1[100], str2[100];
    scanf("%[^#]#%[^#]#", str1, str2);

    // Check if the strings match and print the result
    if (isMatch(str1, str2)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

