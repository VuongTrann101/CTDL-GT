#include <stdio.h>
#include <string.h>

#define max 100
typedef struct Wood {
	char type[20];
	int bk, age;
};

typedef struct Stack {
	int top;
	Wood data[max];
};

Stack khogo;
void Init(Stack* khogo) {
    khogo->top = 0;
}

int Isempty(Stack khogo) {
    return (khogo.top == 0);
}

int Isfull(Stack khogo) {
    return (khogo.top == max);
}

void push(Stack *khogo, const char* type, int bk, int age) {
	if (Isfull(*khogo)) {
		 printf("Ngan xep day\n"); return; }
		 khogo->top++;
		 khogo->data[khogo->top].age = age;
		 khogo->data[khogo->top].bk = bk;
		 strcpy(khogo->data[khogo->top].type, type);
}

void pop(Stack *khogo) {
	if(Isempty(*khogo)) {
         printf("Ngan xep rong\n"); return;
	}
	khogo->top--;
}

 Wood Top(Stack *khogo) {
	return  khogo->data[--khogo->top];
}

void printStack(Stack khogo) {
    if (Isempty(khogo)) {
        printf("Ngan xep rong\n");
        return;
    }
    for (int i = 1; i <= khogo.top; i++) {
        printf("Go %d: Loai = %s, Ban kinh = %d, Do tuoi = %d\n",
               i, khogo.data[i].type, khogo.data[i].bk, khogo.data[i].age);
    }
}

void sortByAge(Stack* khogo) {
    if (khogo->top <= 1) {
        printf("Ngan xep rong hoac chi co 1 thanh go, khong can sap xep.\n");
        return;
    }

   
    for (int i = 0; i <= khogo->top; i++) {
        for (int j = 0; j < khogo->top - i; j++) {
            if (khogo->data[j].age > khogo->data[j + 1].age) {
                Wood temp = khogo->data[j];
                khogo->data[j] = khogo->data[j + 1];
                khogo->data[j + 1] = temp;
            }
        }
    }
}


int main() {
    Stack khogo;
    Init(&khogo); 
    
    push(&khogo, "Soi", 20, 10);
    push(&khogo, "Lim", 20, 100);
    push(&khogo, "Occho", 10, 50);
    push(&khogo, "Gu", 50, 10);

    sortByAge(&khogo);
    printStack(khogo);

    return 0;
}


