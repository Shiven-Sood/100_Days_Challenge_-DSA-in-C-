#include <stdio.h>
#include <string.h>

int main() {
    char s[1001]; // assuming max length 1000
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;
    int isPalindrome = 1; // flag

    while(left < right) {
        if(s[left] != s[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if(isPalindrome)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}