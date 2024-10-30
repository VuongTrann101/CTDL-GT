#include <stdio.h>
#include <math.h>
//ham doi gia tri
void swap(int *var1, int *var2) {
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
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

void tron(int a[], int b[], int c[], int n, int m) {
	int i = 0, j = 0, k = 0;
		while ((i<n)&&(j<m)) { 
	   if (a[i] <= b[j]) {
	   	 c[k++] = a[i++];
	   } 
	   else c[k++] = b[j++];
		
	}
	while (i<n) {
		c[k++] = a[i++];
	}
	while(j<m) { c[k++] = b[j++]; 
	}
	xuat(n+m,c);
}

int main() {
	int n, m; printf("Nhap n, m: ") ;scanf("%d%d", &n,&m);
	
	int a[n], b[m], c[m+n];
	printf("Nhap mang a: ");
	
	nhap(n,a); 
	printf("Nhap mang b: ");nhap(m,b);
	for(int i = 0; i <n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if (a[i] >a[j] ) {
				swap(&a[i],&a[j]);
			}
		}
	}
		for(int i = 0; i <m-1; i++) {
		for(int j=i+1; j<m; j++) {
			if (b[i] >b[j] ) {
				swap(&b[i],&b[j]);
			}
		}
	}
	printf("xuat mang a:") ; xuat(n,a);
	printf("/nxuat mang b:"); xuat (m,b);
printf("\nday tron: ");
	tron(a,b,c,n,m);
}
