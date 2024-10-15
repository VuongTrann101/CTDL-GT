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
    }
}

void xuat(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int x = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > x) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = x;
        xuat(n, arr); 
    }
}

void SelectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
        xuat(n, arr); 
    }
}

void BubbleSort(int a[], int n) {
    int i, j;
    for (int i = 0; i < n - 1; i++) { 
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(&a[j], &a[j - 1]);
            }
        }
        xuat(n, a); 
    }
}

int main() {
    int n = 12; 
    int arr[12], arr_copy[12];

    nhap(n, arr);
    
    // Copy mang ban dau cho cac thuat toan khac
    for (int i = 0; i < n; i++) arr_copy[i] = arr[i];

    printf("Day lua chon: \n");
    SelectionSort(arr, n);

    // Khoi phuc mang ban dau de thuc hien thuat toan tiep theo
    for (int i = 0; i < n; i++) arr[i] = arr_copy[i];

    printf("\nDay noi bot: \n");
    BubbleSort(arr, n);

    for (int i = 0; i < n; i++) arr[i] = arr_copy[i];

    printf("\nDay chen: \n");
    InsertionSort(arr, n);

    return 0;
}
