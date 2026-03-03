#include <stdio.h>
#include <stdlib.h>

struct Node
 {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void printPolynomial(struct Node* head) 
{
    struct Node* temp = head;
    while (temp) {
        printf("%d", temp->coeff);
        if (temp->exp > 0) {
            printf("x");
            if (temp->exp > 1) {
                printf("^%d", temp->exp);
            }
        }
        if (temp->next) printf(" + ");
        temp = temp->next;
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        struct Node* newNode = createNode(coeff, exp);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    printPolynomial(head);
    return 0;
}