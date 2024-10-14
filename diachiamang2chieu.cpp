#include <stdio.h>

int main() {
	int m, n; printf("Nhap m, n: "); scanf("%d%d", &m, &n);
    int arr[m][n];
    int* point = &arr[0][0];
    
    int address = (int)(point) + (i * N + j) * sizeof(int); // cong thuc tinh dia chi
}
