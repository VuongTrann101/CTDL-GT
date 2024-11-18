#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FileNode {
    char name[100];          // T�n file
    long size;               // K�ch thu?c file (bytes)
    char creationTime[20];   // Th?i gian t?o file (dd-mm-yyyy hh:mm)
    struct FileNode* next;   // Con tr? t?i node ti?p theo
} FileNode;

// Danh s�ch li�n k?t
typedef struct {
    FileNode* head;          // Con tr? t?i node d?u danh s�ch
} LinkedList;

// Kh?i t?o danh s�ch li�n k?t
void initializeList(LinkedList* list) {
    list->head = NULL;
}

void insertFile(LinkedList* list, const char* name, long size, const char* creationTime) {
    FileNode* newNode = (FileNode*)malloc(sizeof(FileNode));
    strcpy(newNode->name, name);
    newNode->size = size;
    strcpy(newNode->creationTime, creationTime);
    newNode->next = NULL;

    // Ch�n v�o danh s�ch theo th? t? th?i gian
    if (list->head == NULL || strcmp(list->head->creationTime, creationTime) > 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        FileNode* current = list->head;
        while (current->next != NULL && strcmp(current->next->creationTime, creationTime) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

long calculateTotalSize(LinkedList* list) {
    long totalSize = 0;
    FileNode* current = list->head;
    while (current != NULL) {
        totalSize += current->size;
        current = current->next;
    }
    return totalSize;
}
#define USB_SIZE (32L * 1024 * 1024 * 1024) // 32GB

void backupToUSB(LinkedList* list) {
    long totalSize = calculateTotalSize(list);
    while (totalSize > USB_SIZE) {
        // T�m file c� k�ch thuoc nho nhat
        FileNode *prev = NULL, *current = list->head, *minPrev = NULL, *minNode = list->head;
        while (current->next != NULL) {
            if (current->next->size < minNode->size) {
                minPrev = current;
                minNode = current->next;
            }
            current = current->next;
        }
        // X�a file nho nhat
        if (minPrev == NULL) {
            list->head = list->head->next;
        } else {
            minPrev->next = minNode->next;
        }
        totalSize -= minNode->size;
        free(minNode);
    }
}

