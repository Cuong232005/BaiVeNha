#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int heso;
    int mu;
    struct Node* next;
} Node;

Node* taoNode(int heso, int mu) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho de cap phat!\n");
        exit(1);
    }
    newNode->heso = heso;
    newNode->mu = mu;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node** first, int heso, int mu) {
    if (heso == 0) return;

    Node* newNode = taoNode(heso, mu);
    newNode->next = *first;
    *first = newNode;
}

void InDT(Node* first) {
    Node* p = first;
    while (p != NULL) {
        if (p->heso > 0 && p != first) {
            printf("+");
        }
        printf("%dx^%d ", p->heso, p->mu);
        p = p->next;
    }
    printf("\n");
}

void freeDT(Node* first) {
    Node* p = first;
    while (p != NULL) {
        Node* nextNode = p->next;
        free(p);
        p = nextNode;
    }
}

int main() {
    Node* DT = NULL;

    int n, heso, mu;
    printf("Nhap so luong hang tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap he so va so mu : ");
        scanf("%d %d", &heso, &mu);
        addNode(&DT, heso, mu);
    }

    printf("Da thuc la: ");
    InDT(DT);

    freeDT(DT);

    return 0;
}
