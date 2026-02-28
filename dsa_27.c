#include <stdio.h>
#include <stdlib.h>

struct Node
 {
    int data;
    struct Node* next;
};

struct Node* createNode(int value)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) 
{
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) 
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = (len1 > len2) ? (len1 - len2) : (len2 - len1);

    if (len1 > len2) 
    {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
     {
        if (head1->data == head2->data) 
        {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main()
 {
    int n, m;
    scanf("%d", &n);

    struct Node* head1 = NULL;
    struct Node* tail1 = NULL;

    for (int i = 0; i < n; i++) 
    {
        int value;
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    scanf("%d", &m);

    struct Node* head2 = NULL;
    struct Node* tail2 = NULL;

    for (int i = 0; i < m; i++)
     {
        int value;
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head2 == NULL) 
        {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL) 
    {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }

    struct Node* temp;
    while (head1 != NULL) 
    {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2 != NULL)
     {
        temp = head2;
        head2 = head2->next;
        free(temp);
    }

    return 0;
}