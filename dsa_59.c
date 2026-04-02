#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd)
        return NULL;
    struct Node* node = newNode(postorder[*postIndex]);
    (*postIndex)--;
    if (inStart == inEnd)
        return node;
    int inIndex = search(inorder, inStart, inEnd, node->data);
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);
    return node;
}

void printPreorder(struct Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int inorder[N], postorder[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &postorder[i]);
    int postIndex = N - 1;
    struct Node* root = buildTree(inorder, postorder, 0, N - 1, &postIndex);
    printPreorder(root);
    return 0;
}