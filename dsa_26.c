#include <stdio.h>
#include <stdlib.h>

struct Node
 {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void traverseForward(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
 {
    int n;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < n; i++) 
    {
        int value;
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    traverseForward(head);

    struct Node* temp;
    while (head != NULL)
     {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}