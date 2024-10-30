#include <stdio.h>

typedef struct Node {
	int data;
	Node *next;
};

struct List{
	Node *firstnode;
}; 

//khoi tao danh sach rong
void initList(List *list) {
	list->firstnode = 0;
}

//them phan tu vao cuoi danh sach
void Add_end(List *list, int add) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = add;
	newNode->next = NULL;
	//danh sach rong, phan tu dau  == phtu cuoi
	if (list->firstnode == NULL) {
		list->firstnode == newNode;	
	} 
	// neu khong chay den cuoi danh sach
	else {
		Node *temp = list->firstnode;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
}
}
// them vao dau danh sach
void Add_begin(List *list, int add) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = add;
	newNode->next = list->firstnode;
	list->firstnode = newNode;
}

//chen vao giua
void Insert(Node *node, int add) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = add;
	newNode->next = node->next;
	node->next = newNode;
}



int main() {
	
}
