#include <stdio.h>
#include <string.h>

void longest_equal_substring(char *s) {
    int n = strlen(s), i ;
    int max_length = 0;
    int max_start = 0;
    
    int current_length = 1;
    for ( i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                max_start = i - max_length;
            }
            current_length = 1;
        }
    }
    
    // Check the last substring
    if (current_length > max_length) {
        max_length = current_length;
        max_start = n - max_length;
    }

    if (max_length > 1) {
        for (i = max_start; i < max_start + max_length; i++) {
            printf("%c", s[i]);
        }
    } else {
        printf("no");
    }
}

int main() {
    char input_str[1000];
    scanf("%s", input_str);
    longest_equal_substring(input_str);
    return 0;
}

