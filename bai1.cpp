#include <stdio.h>

#define MAX_SIZE 100

void nhapMang(int mang[], int *n) {
    printf("Nhap so luong phan tu trong mang: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("nhap phan tu thu %d: ", i + 1);
        scanf("%d", &mang[i]);
    }
}

void inPhanTuThuI(int mang[], int n, int i) {
    if (i >= 0 && i < n) {
        printf("Giá tri phan tu thu %d là: %d\n", i + 1, mang[i]);
    } else {
        printf("Chi so khong hop l?.\n");
    }
}

void timMax(int mang[], int n) {
    int max = mang[0];
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (mang[i] > max) {
            max = mang[i];
            maxIndex = i;
        }
    }
    printf("Vi tri max: %d, giá tr? max: %d\n", maxIndex + 1, max);
}

void timMin(int mang[], int n) {
    int min = mang[0];
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (mang[i] < min) {
            min = mang[i];
            minIndex = i;
        }
    }
    printf("Vi tri min: %d, giá tr? min: %d\n", minIndex + 1, min);
}

void inSoLe(int mang[], int n) {
    printf("cac so le trong mang: ");
    for (int i = 0; i < n; i++) {
        if (mang[i] % 2 != 0) {
            printf("%d ", mang[i]);
        }
    }
    printf("\n");
}

void tinhTong(int mang[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += mang[i];
    }
    printf("Tong gia tru cua các phan tu trong mang: %d\n", tong);
}

int main() {
    int mang[MAX_SIZE];
    int n;
    
    nhapMang(mang, &n);
    
    int x;
    printf("Nhap x (chi so phan tu can in): ");
    scanf("%d", &x);
    inPhanTuThuI(mang, n, x - 1);  
    timMax(mang, n);
    timMin(mang, n);
    inSoLe(mang, n);
    tinhTong(mang, n);
    
    return 0;
}

