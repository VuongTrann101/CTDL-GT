#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 7 

void MT(int matrix[MAX][MAX], int sosinh) {
    printf("Nhap ma tran:\n", sodinh, sodinh);
    for (int i = 0; i < sodinh; i++) {
        for (int j = 0; j < sodinh; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}


#define MAX_DEGREE 10 

void DS(char list[MAX][MAX_DEGREE][MAX], int sodinh) {
    for (int i = 0; i < sodinh; i++) {
        printf("Nhap dinh ke %c: ", 'a' + i);
        int k = 0;
        while (1) {
            char dinh;
            scanf(" %c", &dinh);
            if (dinh == '.') break; // nhap . thi ket thuc
            list[i][k][0] = dinh;
            k++;
        }
        list[i][k][0] = '\0'; 
    }
}
