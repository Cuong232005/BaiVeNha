#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int quantity;
    float price;
} Product;

typedef struct Node {
    int id;
    Product *items;
    int num;
    struct Node *next;
} Node;

typedef struct {
    Node *F;
    Node *R;
} Queue;

void initqueue(Queue *q) {
    q->F = q->R = NULL;
}

void addNode(Queue *q, int id, Product *items, int num) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->id = id;
    newNode->items = items;
    newNode->num = num;
    newNode->next = NULL;

    if (q->R == NULL) {
        q->F = q->R = newNode;
        return;
    }
    q->R->next = newNode;
    q->R = newNode;
}

Node *deNode(Queue *q) {
    if (q->F == NULL) {
        printf("Khong co hang doi!\n");
        return NULL;
    }
    Node *temp = q->F;
    q->F = q->F->next;
    if (q->F == NULL) {
        q->R = NULL;
    }
    return temp;
}

float Revenue(Queue *q) {
    Node *current = q->F;
    float total = 0;

    while (current != NULL) {
        for (int i = 0; i < current->num; i++) {
            total += current->items[i].quantity * current->items[i].price;
        }
        current = current->next;
    }
    return total;
}

int count(Queue *q, const char *proname) {
    Node *current = q->F;
    int counts = 0;

    while (current != NULL) {
        for (int i = 0; i < current->num; i++) {
            if (strcmp(current->items[i].name, proname) == 0) {
                counts += current->items[i].quantity;
            }
        }
        current = current->next;
    }
    return counts;
}

void freecart(Node *node) {
    free(node->items);
    free(node);
}

int main() {
    Queue q;
    initqueue(&q);

    Product *items1 = (Product *)malloc(2 * sizeof(Product));
    strcpy(items1[0].name, "Sua");
    items1[0].quantity = 2;
    items1[0].price = 20000;
    strcpy(items1[1].name, "Banh mi");
    items1[1].quantity = 1;
    items1[1].price = 15000;
    addNode(&q, 1, items1, 2);

    Product *items2 = (Product *)malloc(2 * sizeof(Product));
    strcpy(items2[0].name, "Sua");
    items2[0].quantity = 1;
    items2[0].price = 20000;
    strcpy(items2[1].name, "Tao");
    items2[1].quantity = 3;
    items2[1].price = 30000;
    addNode(&q, 2, items2, 2);

    Product *items3 = (Product *)malloc(2 * sizeof(Product));
    strcpy(items3[0].name, "Tao");
    items3[0].quantity = 2;
    items3[0].price = 30000;
    strcpy(items3[1].name, "Banh mi");
    items3[1].quantity = 2;
    items3[1].price = 15000;
    addNode(&q, 3, items3, 2);

    Node *processed = deNode(&q);
    printf("Thanh toan xong gio hang: %d\n", processed->id);
    freecart(processed);

    float total_revenue = Revenue(&q);
    printf("Tong so tien thu duoc: %.2f VND\n", total_revenue);

    const char *proname = "Sua";
    int counts = count(&q, proname);
    printf("So luong san pham %s da ban: %d\n", proname, counts);

    while ((processed = deNode(&q)) != NULL) {
        freecart(processed);
    }

    return 0;
}
