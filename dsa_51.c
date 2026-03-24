#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->val && n2 < root->val)
            root = root->left;
        else if (n1 > root->val && n2 > root->val)
            root = root->right;
        else
            return root->val;
    }
    return -1;
}

int main() {
    int N;
    scanf("%d", &N);
    struct Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d\n", findLCA(root, n1, n2));
    return 0;
}