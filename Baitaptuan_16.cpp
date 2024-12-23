#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

int Height(Node *node) {
    return node ? node->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rotateLeft(Node *k2) {
    Node *k1= k2->left;
    Node *x= k1->right; 

    k1->right = k2;
    k2->left = x;

    k2->height = max(Height(k2->left), Height(k2->right)) + 1;
    k1->height = max(Height(k1->left), Height(k1->right)) + 1;

    return k1;
}

Node* rotateRight(Node *k2) {
    Node *k1 = k2->right;
    Node *x= k1->left; 

    k1->left = k2;
    k2->right = x;

    k2->height = max(Height(k2->left), Height(k2->right)) + 1;
    k1->height = max(Height(k1->left), Height(k1->right)) + 1;

    return k1;
}

int Balance(Node *node) {
    return node ? Height(node->left) - Height(node->right) : 0;
}

Node* insertNode(Node* node, int data) {
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);
    else 
        return node;

    node->height = 1 + max(Height(node->left), Height(node->right));

    int balance = Balance(node);

    //Truong hop 1: Left-Left
    if (balance > 1 && data < node->left->data)
        return rotateLeft(node);

    //Truong hop 4: Right-Right
    if (balance < -1 && data > node->right->data)
        return rotateRight(node);

    //Truong hop 2: Left-Right
    if (balance > 1 && data > node->left->data) {
        node->left = rotateRight(node->left);
        return rotateLeft(node);
    }

    //Truong hop 3: Right-Left
    if (balance < -1 && data < node->right->data) {
        node->right = rotateLeft(node->right);
        return rotateRight(node);
    }

    return node;
}

void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    Node *root = NULL;

    int A[] = {17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++) {
        root = insertNode(root, A[i]);
    }

    printf("Cay AVL theo thu tu giua: \n");
    inOrder(root);

    return 0;
}

