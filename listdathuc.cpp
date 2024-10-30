#include <stdio.h>
#include <stdlib.h>


typedef struct HangTu {
    int heSo;             
    int bac;            
    struct HangTu *tiep;  
} HangTu;


typedef struct DaThuc {
    HangTu *hangTuDau;    
} DaThuc;


void khoiTaoDaThuc(DaThuc *daThuc) {
    daThuc->hangTuDau = NULL;  
}


void themHangTu(DaThuc *daThuc, int heSo, int bac) {
    if (heSo == 0) return;  

    HangTu *hangTuMoi = (HangTu*)malloc(sizeof(HangTu));
    hangTuMoi->heSo = heSo;
    hangTuMoi->bac = bac;
    hangTuMoi->tiep = NULL;


    if (daThuc->hangTuDau == NULL || daThuc->hangTuDau->bac < bac) {
        hangTuMoi->tiep = daThuc->hangTuDau;
        daThuc->hangTuDau = hangTuMoi;
    } else {
       
        HangTu *hienTai = daThuc->hangTuDau;
        while (hienTai->tiep != NULL && hienTai->tiep->bac > bac) {
            hienTai = hienTai->tiep;
        }
        hangTuMoi->tiep = hienTai->tiep;
        hienTai->tiep = hangTuMoi;
    }
}


void nhapDaThuc(DaThuc *daThuc) {
    int n, heSo, bac;
    printf("Nhap so luong hang tu cua da thuc: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap he so va bac cua hang tu thu %d: ", i + 1);
        scanf("%d %d", &heSo, &bac);
        themHangTu(daThuc, heSo, bac);
    }
}


void inDaThuc(DaThuc *daThuc) {
    HangTu *hienTai = daThuc->hangTuDau;

    if (hienTai == NULL) {
        printf("0\n");
        return;
    }

    while (hienTai != NULL) {
        
        if (hienTai->heSo > 0 && hienTai != daThuc->hangTuDau) {
            printf(" + ");
        } else if (hienTai->heSo < 0) {
            printf(" - ");
        }

        int heSoTuyetDoi = hienTai->heSo < 0 ? -hienTai->heSo : hienTai->heSo;
        if (heSoTuyetDoi != 1 || hienTai->bac == 0) {
            printf("%d", heSoTuyetDoi);
        }

        if (hienTai->bac != 0) {
            printf("x");
            if (hienTai->bac > 1) {
                printf("^%d", hienTai->bac);
            }
        }

        hienTai = hienTai->tiep;
    }
    printf("\n");
}


void giaiPhongDaThuc(DaThuc *daThuc) {
    HangTu *hienTai = daThuc->hangTuDau;
    while (hienTai != NULL) {
        HangTu *tam = hienTai;
        hienTai = hienTai->tiep;
        free(tam);
    }
}

int main() {
    DaThuc daThuc;
    khoiTaoDaThuc(&daThuc);

    nhapDaThuc(&daThuc);


    printf("Da thuc vua nhap la: ");
    inDaThuc(&daThuc);


    giaiPhongDaThuc(&daThuc);

    return 0;
}

