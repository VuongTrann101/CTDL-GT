#include <stdio.h>



void MergeArrays(int A[],int m, int n, int p){
	int i=m,j=n+1;
	while (i<j && j<=p){
		if (A[i]<=A[j]) i++;
		else {//chen Aj vao vi tri i
			int x=A[j];
			for (int k=j-1;k>=i;k--) 
				A[k+1]=A[k];
			A[i]=x;
			i++; j++;
		}
	}
}

void Split_Merg(int A[], int first, int last){
	if (first>=last) return;
	int m=(first+last)/2;
	Split_Merg(A,first,m); // d? quy tách n?a trái
	Split_Merg(A,m+1,last); // d? quy tách n?a ph?i
	MergeArrays(A,first,m,last); //ghép 2 n?a dãy
}

void MergeSort(int A[], int N){
	if (N<2) return;
	Split_Merg(A,0,N-1);
}

void nhap(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    } printf("\n");
}

void xuat(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
		int n, m; printf("Nhap n, m: ") ;scanf("%d%d", &n,&m);
	
	int a[n], b[m], c[m+n];
	printf("Nhap mang a: ");
	
	nhap(n,a); 
	printf("Nhap mang b: ");nhap(m,b);
	for(int i = 0; i <n-1; i++) {


