#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val)
 {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }
    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    struct QNode* arr;
    int front, rear;
};

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct QNode*)malloc(size * sizeof(struct QNode));
    q->front = q->rear = 0;
    return q;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

struct List {
    int* arr;
    int size;
    int capacity;
    int hd;
    struct List* next;
};

struct List* createList(int hd) {
    struct List* l = (struct List*)malloc(sizeof(struct List));
    l->capacity = 10;
    l->size = 0;
    l->hd = hd;
    l->arr = (int*)malloc(l->capacity * sizeof(int));
    l->next = NULL;
    return l;
}

void addToList(struct List* l, int val) {
    if (l->size == l->capacity) {
        l->capacity *= 2;
        l->arr = (int*)realloc(l->arr, l->capacity * sizeof(int));
    }
    l->arr[l->size++] = val;
}

struct List* findOrCreate(struct List** head, int hd) {
    struct List* curr = *head, *prev = NULL;
    while (curr && curr->hd < hd) {
        prev = curr;
        curr = curr->next;
    }
    if (curr && curr->hd == hd) return curr;
    struct List* newL = createList(hd);
    if (prev == NULL) {
        newL->next = *head;
        *head = newL;
    } else {
        newL->next = curr;
        prev->next = newL;
    }
    return newL;
}

void verticalOrder(struct Node* root, int n) {
    if (!root) return;
    struct Queue* q = createQueue(n);
    enqueue(q, root, 0);

    struct List* head = NULL;

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct Node* node = temp.node;
        int hd = temp.hd;

        struct List* l = findOrCreate(&head, hd);
        addToList(l, node->val);

        if (node->left) enqueue(q, node->left, hd - 1);
        if (node->right) enqueue(q, node->right, hd + 1);
    }

    struct List* curr = head;
    while (curr) {
        for (int i = 0; i < curr->size; i++) {
            printf("%d ", curr->arr[i]);
        }
        printf("\n");
        curr = curr->next;
    }
}

int main() 
{
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, N);
    verticalOrder(root, N);

    return 0;
}