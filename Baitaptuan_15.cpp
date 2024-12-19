#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[100];
    int pages;
    struct Node *child;
    struct Node *next;
} Node;

Node *createNode(const char *name, int pages) {
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->pages = pages;
    node->child = NULL;
    node->next = NULL;
    return node;
}

void addChild(Node *father, Node *child) {
    if (father->child== NULL) {
        father->child= child;
    } else {
        Node *temp = father->child;
        while (temp->next !=NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

int quantity(Node *root) {
    if (root== NULL) return 0;
    int count = 0;
    Node *temp = root->child;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *LongestChap(Node *root) {
    if (root ==NULL) return NULL;
    Node *temp = root->child;
    Node *longest = NULL;
    int maxPage = 0;

    while (temp !=NULL) {
        if (temp->pages >maxPage) {
            maxPage= temp->pages;
            longest = temp;
        }
        temp = temp->next;
    }
    return longest;
}

int Delete(Node *root, const char *name) {
    if (root==NULL) return 0;

    Node *pre = NULL, *post = root->child;

    while (post!=NULL) {
        if (strcmp(post->name, name) == 0) {
            if (pre !=NULL) {
                pre->next = post->next;
            } else {
                root->child = post->next;
            }
            free(post);
            return 1;
        }
        pre = post;
        post = post->next;
    }

    post = root->child;
    while (post != NULL) {
        if (Delete(post, name)) {
            return 1;
        }
        post = post->next;
    }
    return 0;
}

void print(Node *root, int level) {
    if (root==NULL) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("- %s (%d pages)\n", root->name, root->pages);

    Node *temp = root->child;
    while (temp != NULL) {
        print(temp, level + 1);
        temp = temp->next;
    }
}

int main() {
    Node *book = createNode("Name's Book", 0);

    Node *chapter1 = createNode("Chapter 1", 84);
    Node *chapter2 = createNode("Chapter 2", 25);
    Node *chapter3 = createNode("Chapter 3", 46);

    addChild(book, chapter1);
    addChild(book, chapter2);
    addChild(book, chapter3);

    addChild(chapter2, createNode("Section 2.1", 47));
    addChild(chapter2, createNode("Section 2.2", 35));
    addChild(chapter3, createNode("Section 3.1", 76));

    printf("structure's Book:\n");
    print(book, 0);

    printf("\nNumber of chapter: %d\n", quantity(book));

    Node *longest = LongestChap(book);
    if (longest !=NULL) {
        printf("Longest chapter: %s (%d pages)\n", longest->name, longest->pages);
    }

    printf("\nDeleting 'Chapter 3'\n");
    Delete(book, "Chapter 3");
    print(book, 0);

    return 0;
}

