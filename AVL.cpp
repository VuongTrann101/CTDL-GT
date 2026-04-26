#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
} node;

//chieu cao 1 newnode
int getHeight(node *newnode) {
    return (newnode == NULL) ? 0 : newnode->height;
}

// tinh do lech chieu cao cua newnode trai va phai
int getBalanceFactor(node *newnode) {
    if (newnode == NULL) return 0;
    return getHeight(newnode->left) - getHeight(newnode->right);
}


node *createNode(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1; 
    return newnode;
}

// xoay phai
node *rotateRight(node *y) {
    node *x = y->left;
    node *T2 = x->right;

      
    x->right = y;
    y->left = T2;

    // cap nhat lai chieu cao
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));

    return x; 
}

// ham xoay trai
node *rotateLeft(node *x) {
    node *y = x->right;
    node *T2 = y->left;

  
    y->left = x;
    x->right = T2;

   
    x->height = 1 + ((getHeight(x->left) > getHeight(x->right)) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));

    return y; 
}


node *insertNode(node *newnode, int data) {
    
    if (newnode == NULL)
        return createNode(data);

    if (data < newnode->data)
        newnode->left = insertNode(newnode->left, data);
    else if (data > newnode->data)
        newnode->right = insertNode(newnode->right, data);
    else // khong them gia tri lap
        return newnode;

    // cap nhat chieu cao
    newnode->height = 1 + ((getHeight(newnode->left) > getHeight(newnode->right)) ? getHeight(newnode->left) : getHeight(newnode->right));

    // kiem tra xem can bang chua
    int balance = getBalanceFactor(newnode);

    // mat can bang LL
    if (balance > 1 && data < newnode->left->data)
        return rotateRight(newnode);

    // RR
    if (balance < -1 && data > newnode->right->data)
        return rotateLeft(newnode);

    // LR
    if (balance > 1 && data > newnode->left->data) {
        newnode->left = rotateLeft(newnode->left);
        return rotateRight(newnode);
    }

    // RL
    if (balance < -1 && data < newnode->right->data) {
        newnode->right = rotateRight(newnode->right);
        return rotateLeft(newnode);
    }

    return newnode; 
}

// duyet
void LNR(node *root) {
    if (root != NULL) {
        LNR(root->left);
        printf("%d ", root->data);
        LNR(root->right);
    }
}

int main() {
    node *root = NULL;

    int arr[] = {10, 20, 30, 40, 50, 25};
    int n = 6;

   
    for (int i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }
    printf("Cay AVL:\n");
    LNR(root);
    printf("\n");

    return 0;
}

