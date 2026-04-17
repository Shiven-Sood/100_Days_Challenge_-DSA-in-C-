#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char names[n][100];
    int count[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (strcmp(names[i], names[j]) == 0) count[i]++;
    char winner[100];
    int maxVotes = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] > maxVotes || (count[i] == maxVotes && strcmp(names[i], winner) < 0)) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
    }
    printf("%s %d\n", winner, maxVotes);
    return 0;
}