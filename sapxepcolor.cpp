#include <stdio.h> 
#include <stdlib.h>

int main() {
	int n; 
	printf("Nhap n: ");
	scanf("%d", &n);
	int color[n];
	printf("\nNhap mang color: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &color[i]);	
	}
//nhap so 0 neu do,1 neu trang, 2 neu xanh

 for (int i = 0; i < n; i++) {
 	for (int j=i+1; j<n;j++) {
 		if (color[i]>color[j]) {
 			int a = color[i]; 
 			    color[i] = color[j];
 			    color[j]= a;
		 }
		 
}
 } 
 
 for (int i = 0; i < n; i++) {
 	if (color[i]==0) printf("do ");
 	
 	if (color[i]==1) printf("trang ");
 	
 	if (color[i]==2) printf("xanh ");
 }
 return 0;
}
