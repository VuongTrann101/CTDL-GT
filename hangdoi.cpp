#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Product {
    char name[50];  
    int quantity;
    double price;   
} Product;


typedef struct Node {
    Product products[100]; 
    int productCount;     
    struct Node* next;    
} Node;


typedef struct Queue {
    Node* front; 
    Node* rear;  
} Queue;


void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}


int isEmpty(Queue* queue) {
    return queue->front == NULL;
}


void enqueue(Queue* queue, Product* products, int productCount) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        newNode->products[i] = products[i];
    }
    newNode->productCount = productCount;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
}


double dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return 0;
    }
    Node* temp = queue->front;
    double total = 0;
    for (int i = 0; i < temp->productCount; i++) {
        total += temp->products[i].quantity * temp->products[i].price;
    }

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return total;
}


double calculateTotal(Queue* queue) {
    double total = 0;
    while (!isEmpty(queue)) {
        total += dequeue(queue);
    }
    return total;
}


int countProductA(Queue* queue, const char* productName) {
    int count = 0;
    Node* current = queue->front;
    while (current) {
        for (int i = 0; i < current->productCount; i++) {
            if (strcmp(current->products[i].name, productName) == 0) {
                count += current->products[i].quantity;
            }
        }
        current = current->next;
    }
    return count;
}

int main() {
    Queue queue;
    initQueue(&queue);

   
    Product products1[] = {{"Sua", 2, 1.5}, {"BanhMi", 1, 2.0}};
    Product products2[] = {{"Sua", 1, 1.5}, {"Trung", 12, 0.1}, {"A", 5, 0.5}};
    Product products3[] = {{"A", 3, 0.5}, {"BanhMi", 2, 2.0}};

    
    enqueue(&queue, products1, 2);
    enqueue(&queue, products2, 3);
    enqueue(&queue, products3, 2);

   
    double total = calculateTotal(&queue);
    printf("T?ng s? ti?n thu du?c: %.2f\n", total);

    
    int productACount = countProductA(&queue, "A");
    printf("So luong san pham A dã duoc bán: %d\n", productACount);

    return 0;
}


