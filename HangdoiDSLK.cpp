#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Product {
    char name[50];    
    int quantity;   
    float price;      
} Product;


typedef struct Order {
    int customerID;       
    int productCount;     
    Product *products;    
    float total;          
    struct Order *next;    
} Order;


typedef struct Queue {
    Order *front;          
    Order *rear;           
} Queue;

void init(Queue *q) {
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, int customerID, int productCount, Product *products) {
    Order *newOrder = (Order *)malloc(sizeof(Order));
    newOrder->customerID = customerID;
    newOrder->productCount = productCount;
    newOrder->products = products;
    newOrder->total = 0;

    
    for (int i = 0; i < productCount; i++) {
        newOrder->total += products[i].quantity * products[i].price;
    }

    newOrder->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newOrder;
        return;
    }
    q->rear->next = newOrder;
    q->rear = newOrder;
}

float dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Hang doi rong, khong co ai thanh toan.\n");
        return 0;
    }

    Order *temp = q->front;
    float total = temp->total;  

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    
    free(temp->products);
    free(temp);
    
    return total;  }

float calculateTotalRevenue(Queue *q) {
    Order *temp = q->front;
    float totalRevenue = 0;

    while (temp != NULL) {
        totalRevenue += temp->total;
        temp = temp->next;
    }

    return totalRevenue;
}

int countProductSold(Queue *q, const char *productName) {
    Order *temp = q->front;
    int count = 0;

    while (temp != NULL) {
        for (int i = 0; i < temp->productCount; i++) {
            if (strcmp(temp->products[i].name, productName) == 0) {
                count += temp->products[i].quantity;
            }
        }
        temp = temp->next;
    }

    return count;
}

void In(Queue *q) {
    Order *temp = q->front;
    if (temp == NULL) {
        printf("Hang doi rong.\n");
        return;
    }

    while (temp != NULL) {
        printf("Khach hang %d:\n", temp->customerID);
        for (int i = 0; i < temp->productCount; i++) {
            printf("- %s: %d x %.2f\n", temp->products[i].name, temp->products[i].quantity, temp->products[i].price);
        }
        printf("Tong tien: %.2f\n", temp->total);
        temp = temp->next;
    }
}

int main() {
    Queue q;
    init(&q);

  
    Product products1[] = {{"San pham A", 2, 10.0}, {"San pham B", 1, 20.0}};
    enqueue(&q, 1, 2, products1);

    Product products2[] = {{"San pham A", 3, 10.0}, {"San pham C", 2, 15.0}};
    enqueue(&q, 2, 2, products2);

   
    printf("Danh sach hang doi:\n");
    In(&q);

   
    printf("Thanh toan khach hang dau tien\n");
    dequeue(&q);

   
    float revenue = calculateTotalRevenue(&q);
    printf("Tong doanh thu hien tai: %.2f\n", revenue);

    
    int countA = countProductSold(&q, "San pham A");
    printf("So luong san pham A da ban: %d\n", countA);

    return 0;
}



