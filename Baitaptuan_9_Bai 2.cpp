#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WordNode {
    char word[20];
    struct WordNode* next;
} WordNode;

typedef struct {
    WordNode* head;
} WordList;

void CreateList(WordList* list) {
    list->head = NULL;
}

WordNode* CreateNode(const char* word) {
    WordNode* newNode = (WordNode*)malloc(sizeof(WordNode));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

void InsertWord(WordList* list, const char* word) {
    WordNode* newNode = CreateNode(word);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        WordNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

char* FindWord(WordList* list) {
    if (list->head == NULL) return NULL;

    WordNode* current = list->head;
    int maxCount = 0;
    char* most = NULL;

    while (current != NULL) {
        WordNode* p = list->head;
        int count = 0;
        while (p != NULL) {
            if (strcmp(current->word, p->word) == 0) {
                count++;
            }
            p = p->next;
        }
        if (count > maxCount) {
            maxCount = count;
            most = current->word;
        }
        current = current->next;
    }
    return most;
}

void DeleteWord(WordList* list) {
    if (list->head == NULL || list->head->next == NULL) return;

    WordNode* current = list->head;
    while (current != NULL && current->next != NULL) {
        if (strcmp(current->word, current->next->word) == 0) {
            WordNode* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

int countWord(WordList* list) {
    int count = 0;
    WordNode* current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void PrintList(WordList* list) {
    WordNode* current = list->head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

int main() {
    WordList wordList;
    CreateList(&wordList);

    char sentence[1000];
    printf("Nhap cau tieng Viet: ");
    int i = 0;
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {
    	sentence[i++] = ch;
	}
	sentence[i] = '\0';

    char* t = strtok(sentence, " \n");
    while (t != NULL) {
        InsertWord(&wordList, t);
        t = strtok(NULL, " \n");
    }

    printf("\nDanh sach tu trong cau:\n");
    PrintList(&wordList);

    char* most = FindWord(&wordList);
    if (most != NULL) {
        printf("\nTu xuat hien nhieu nhat: %s\n", most);
    } else {
        printf("\nKhong co tu nao.\n");
    }

    DeleteWord(&wordList);
    printf("\nDanh sach sau khi loai bo tu lay:\n");
    PrintList(&wordList);

    int wordCount = countWord(&wordList);
    printf("\nSo tu vung trong cau: %d\n", wordCount);

    return 0;
}
