#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *s) {
    int freq[26] = {0};
    for (int i = 0; s[i]; i++) freq[s[i] - 'a']++;
    for (int i = 0; s[i]; i++) if (freq[s[i] - 'a'] == 1) return s[i];
    return '$';
}

int main() {
    char s[100];
    scanf("%s", s);
    printf("%c\n", firstNonRepeating(s));
    return 0;
}