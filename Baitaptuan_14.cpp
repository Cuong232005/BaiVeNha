#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isEmpty(Node* root) {
    return root == NULL;
}

Node* Tree() {
    Node* n1 = createNode('a');
    Node* n2 = createNode('5');
    Node* n3 = createNode('*');
    n3->left = n1;
    n3->right = n2;

    Node* n4 = createNode('b');
    Node* n5 = createNode('c');
    Node* n6 = createNode('6');
    Node* n7 = createNode('^');
    Node* n8 = createNode('*');
    Node* n9 = createNode('d');
    Node* n10 = createNode('/');
    n7->left = n5;
    n7->right = n6;
    n8->left = n4;
    n8->right = n7;
    n10->left = n8;
    n10->right = n9;

    Node* n11 = createNode('-');
    n11->left = n3;
    n11->right = n10;

    Node* n12 = createNode('h');
    Node* n13 = createNode('f');
    Node* n14 = createNode('-');
    n14->left = n12;
    n14->right = n13;

    Node* n15 = createNode('e');
    Node* n16 = createNode('1');
    Node* n17 = createNode('2');
    Node* n18 = createNode('/');
    Node* n19 = createNode('^');
    n18->left = n16;
    n18->right = n17;
    n19->left = n15;
    n19->right = n18;

    Node* n20 = createNode('*');
    n20->left = n14;
    n20->right = n19;

    Node* root = createNode('+');
    root->left = n11;
    root->right = n20;

    return root;
}

void preorder(Node* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void inorder(Node* root) {
    if (root != NULL) {
        if (root->left || root->right) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (root->left || root->right) printf(")");
    }
}

int main() {
    Node* tree = Tree();
    printf("Duyet theo tien to: ");
    preorder(tree);
    printf("\n");

    printf("Duyet theo hau to: ");
    postorder(tree);
    printf("\n");

    printf("Duyet theo trung to: ");
    inorder(tree);
    printf("\n");

    return 0;
}
