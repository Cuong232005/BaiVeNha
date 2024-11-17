#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FileNode {
    char name[256];
    char address[256];
    long size;
    char Time[20];
    struct FileNode* next;
} FileNode;

typedef struct {
    FileNode* head;
} FileList;

void CreateList(FileList* list) {
    list->head = NULL;
}

FileNode* CreateNode(const char* name, const char* address, long size, const char* Time) {
    FileNode* newNode = (FileNode*)malloc(sizeof(FileNode));
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    newNode->size = size;
    strcpy(newNode->Time, Time);
    newNode->next = NULL;
    return newNode;
}

void InsertFile(FileList* list, const char* name, const char* address, long size, const char* Time) {
    FileNode* newNode = CreateNode(name, address, size, Time);

    if (list->head == NULL || strcmp(list->head->Time, Time) > 0) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }

    FileNode* current = list->head;
    while (current->next != NULL && strcmp(current->next->Time, Time) < 0) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

long Size(FileList* list) {
    long total = 0;
    FileNode* current = list->head;
    while (current != NULL) {
        total += current->size;
        current = current->next;
    }
    return total;
}

void DeleteFile(FileList* list) {
    if (list->head == NULL) return;

    FileNode* current = list->head;
    FileNode* smallest = list->head;
    FileNode* prev = NULL;
    FileNode* prevSmallest = NULL;

    while (current != NULL) {
        if (current->size < smallest->size) {
            smallest = current;
            prevSmallest = prev;
        }
        prev = current;
        current = current->next;
    }

    if (prevSmallest == NULL) {
        list->head = smallest->next;
    } else {
        prevSmallest->next = smallest->next;
    }

    printf("Da xoa file '%s' kich thuoc %ld bytes.\n", smallest->name, smallest->size);
    free(smallest);
}

void USB(FileList* list, long usbSize) {
    while (Size(list) > usbSize) {
        DeleteFile(list);
    }
    printf("Tong kich thuoc con lai: %ld bytes.\n", Size(list));
}

void PrintList(FileList* list) {
    FileNode* current = list->head;
    printf("Danh sach cac file trong thu muc:\n");
    while (current != NULL) {
        printf("Ten: %s, Dia chi: %s, Kich thuoc: %ld bytes, Thoi gian upload: %s\n",
               current->name, current->address, current->size, current->Time);
        current = current->next;
    }
}

int main() {
    FileList Folder;
    CreateList(&Folder);

    const long long usbSize = 34359738368; 

    InsertFile(&Folder, "file1.txt", "/home/user/Documents", 1024, "2024-11-15 10:32:56");
    InsertFile(&Folder, "file2.txt", "/home/user/Documents", 2048, "2024-11-15 12:39:47");
    InsertFile(&Folder, "file3.txt", "/home/user/Documents", 1024*1024, "2024-11-14 09:20:20");
    InsertFile(&Folder, "file4.txt", "/home/user/Documents", 5*1024*1024, "2024-11-17 7:25:37"); 

    PrintList(&Folder);

    printf("Tong kich thuoc file trong thu muc: %ld bytes\n", Size(&Folder));

    USB(&Folder, usbSize);

    PrintList(&Folder);

    return 0;
}
