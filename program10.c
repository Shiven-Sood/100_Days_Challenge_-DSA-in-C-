#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];  // assuming max length 1000
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;

    // mirror the string
    while(left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    printf("%s\n", s);

    return 0;
}