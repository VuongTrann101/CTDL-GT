#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char title[100];         
    int pageCount;           
    struct Node* first; 
    struct Node* next; 
} Node;


Node* createNode(const char* title, int pageCount) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->title, title);
    newNode->pageCount = pageCount;
    newNode->first = NULL;
    newNode->next = NULL;
    return newNode;
}


int countChapters(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    Node* current = root->first; 
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

Node* longestchap(Node* root) {
    if (root == NULL || root->first == NULL) return NULL;
    Node* longest = root->first;
    Node* current = root->first->next;
    while (current != NULL) {
        if (current->pageCount > longest->pageCount) {
            longest = current;
        }
        current = current->next;
    }
    return longest;
}

 void totalpage(Node* root) {
	int total = 0;
	if (root == NULL || root->first == NULL) return;
	Node *current = root->first;
	while(current != NULL) {
		total += current->pageCount;
		current = current->next;
	}
	root->pageCount = total;
}
int deletetitle(Node* root, const char* targetTitle) {
    if (root == NULL || root->first == NULL) return 0;

    Node* current = root->first;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->title, targetTitle) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return 0; // khong thay muc can tim

    
    if (previous == NULL) {
        root->first = current->next; // neu muc can tim la con dau tien
    } else {
        previous->next = current->next;
    }


    free(current);

    return 1; 
}

void update(Node* root) {
    if (root == NULL) return;

    int total = 0;
    Node* current = root->first;
    while (current != NULL) {
        total += current->pageCount;
        current = current->next;
    }
    root->pageCount = total;
}

int main() {
    
    Node* root = createNode("Book", 0);

    Node* chapter1 = createNode("Chapter 1", 30);
    Node* chapter2 = createNode("Chapter 2", 20);
    Node* chapter3 = createNode("Chapter 3", 40);

    root->first = chapter1;
    chapter1->next = chapter2;
    chapter2->next = chapter3;

    printf("Tong so chuong: %d\n", countChapters(root));
    totalpage(root);
    printf("Tong so trang: %d\n", root->pageCount);
    Node* longest = longestchap(root);
    if (longest) {
        printf("Chuong dai nhat: %s (%d pages)\n", longest->title, longest->pageCount);
    }
    deletetitle(root,"Chapter 2");
    update(root);
    printf("So chuong sau khi xoa: %d\n", countChapters(root));
    printf("Tong so trang sau khi xoa: %d\n", root->pageCount);
    return 0;
}

