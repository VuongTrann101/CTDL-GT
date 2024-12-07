#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct node {
	char data[10];
	struct node* left;
	struct node* right;
} node;

void init(node** root) {
	*root = NULL;
}

int empty(node* root) {
	return root == NULL;
}

// Kiem tra do uu tien cua toan tu
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

node* makenode(char* data) {
    node* newnode = (node*)malloc(sizeof(node));
    if (!newnode) {
        printf("Loi cap phat bo nho\n");
        exit(1);
    }
    strcpy(newnode->data, data);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[100];
    int top = -1, k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) { 
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; // Loai bo '(' khoi stack
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while (top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';
}

node* buildExpressionTree(char* postfix) {
    node* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) { 
            char data[2] = {postfix[i], '\0'};
            stack[++top] = makenode(data);
        } else if (isOperator(postfix[i])) { 
            char data[2] = {postfix[i], '\0'};
            node* opNode = makenode(data);

            opNode->right = stack[top--];
            opNode->left = stack[top--];
            stack[++top] = opNode;
        }
    }
    return stack[top];
}

void preorder(node* root) {
    if (root) {
        printf("%s ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root) {
    if (root) {
        if (isOperator(root->data[0])) printf("(");
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
        if (isOperator(root->data[0])) printf(")");
    }
}

void postorder(node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->data);
    }
}

int main() {
    char infix[] = "a*5-b*c^6/d+(h-f)*e^(1/2)";
    char postfix[100];
    
    // Chuyen bieu thuc trung to sang hau to
    infixToPostfix(infix, postfix);
    printf("Bieu thuc hau to: %s\n", postfix);

    // Xay dung cay bieu thuc
    node* root = buildExpressionTree(postfix);

    // In cac bieu thuc theo cac cach duyet
    printf("Bieu thuc tien to: ");
    preorder(root);
    printf("\n");

    printf("Bieu thuc trung to: ");
    inorder(root);
    printf("\n");

    printf("Bieu thuc hau to: ");
    postorder(root);
    printf("\n");

    return 0;
}
