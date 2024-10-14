#include <stdio.h>
#include <math.h> 

// Ham kiem tra so nguyen to
int prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Ham kiem tra so Blum 
int blumprime(int n) {
    return prime(n) && (n % 4 == 3);
}

// Tao mang so Blum bé hon n, tra ve so luong so Blum
int creatblum(int n, int blum[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (blumprime(i)) {
            blum[count++] = i;
        }
    }
    return count;
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int blum[n]; // Mang chua các so Blum
    int tongblum[n]; // Mang chua tong cua hai so Blum mà tong cung là so Blum

    int blum_count = creatblum(n, blum); // So luong so Blum duoc tim thay

    // In ra cac so Blum be hon n
    printf("Mang so blum be hon %d:\n", n);
    for (int i = 0; i < blum_count; i++) {
        printf("%d ", blum[i]);
    }
    printf("\n\n");

    // Tim cac cap so Blum có tong là so Blum
    int count = 0;
    for (int i = 0; i < blum_count; i++) {
        for (int j = i + 1; j < blum_count; j++) {
            if (blumprime(blum[i] + blum[j]) && ((blum[i]+blum[j])<n)) { // Kiem tra tong cap hai so Blum có phai la so Blum nho hon n khong
                tongblum[count++] = blum[i] + blum[j];
            }
        }
    }

    // In ra cac tong cua cap so Blum
    if (count==0) {
    	
   printf("Khong ton tai tong 2 so blum trong day be hon %d ",n); } else {
	
    printf("Danh sach tong 2 so blum la 1 so blum :\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", tongblum[i]);
    } }
    printf("\n\n");

    // Kiem tra blumM co trong day khongg
    int blumM, found = 0;
    printf("Nhap blumM: ");
    scanf("%d", &blumM);

    for (int i = 0; i < blum_count; i++) {
        if (blumM == blum[i]) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Co ton tai\n", blumM);
    } else {
        printf("Khong ton tai\n", blumM);
    }

    return 0;
}

