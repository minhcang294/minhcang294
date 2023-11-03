#include <stdio.h>

// H�m nh?p ma tr?n
void nhapMaTran(int a[][100], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("Nhap phan tu tai hang %d cot %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

// H�m xu?t ma tr?n
void xuatMaTran(int a[][100], int m, int n) {
    printf("Ma tran vua nhap:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// H�m t�m ph?n t? l?n nh?t trong ma tr?n
int timMax(int a[][100], int m, int n) {
    int max = a[0][0];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    return max;
}

// H�m t�m ph?n t? nh? nh?t trong ma tr?n
int timMin(int a[][100], int m, int n) {
    int min = a[0][0];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
        }
    }
    return min;
}

// H�m ki?m tra s? nguy�n t?
int laSoNguyenTo(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// H�m d?m s? nguy�n t? v� t�nh t?ng c�c ph?n t? tr�n ma tr?n
void demVaTinhTong(int a[][100], int m, int n, int *countPrime, int *sum) {
    *countPrime = 0;
    *sum = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laSoNguyenTo(a[i][j])) {
                (*countPrime)++;
            }
            *sum += a[i][j];
        }
    }
}

void timVaInViTriX(int a[][100], int m, int n, int x) {
    printf("Cac vi tri cua %d tren ma tran:\n", x);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == x) {
                printf("Hang %d, Cot %d\n", i + 1, j + 1);
            }
        }
    }
}

void inDiemYenNgua(int a[][100], int m, int n) {
    printf("Cac diem yen ngua tren ma tran:\n");
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int isMinRow = 1, isMaxCol = 1;
            for (int k = 0; k < n; ++k) {
                if (a[i][j] > a[i][k]) {
                    isMinRow = 0;
                    break;
                }
            }
            for (int k = 0; k < m; ++k) {
                if (a[i][j] < a[k][j]) {
                    isMaxCol = 0;
                    break;
                }
            }
            if (isMinRow && isMaxCol) {
                printf("Hang %d, Cot %d: %d\n", i + 1, j + 1, a[i][j]);
            }
        }
    }
}

void sapXepTangDan(int a[][100], int m, int n) {
    int temp[100 * 100];
    int index = 0;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            temp[index++] = a[i][j];
        }
    }

    for (int i = 0; i < m * n - 1; ++i) {
        for (int j = i + 1; j < m * n; ++j) {
            if (temp[i] > temp[j]) {
                int swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }

    index = 0;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            a[i][j] = temp[index++];
        }
    }
}

int tinhTongDuongCheoChinh(int a[][100], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m && i < n; ++i) {
        sum += a[i][i];
    }
    return sum;
}

int demSoChanTamGiacTrenDuongCheoChinh(int a[][100], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] % 2 == 0) {
                count++;
            }
        }
    }
    return count;
}

void inSoLeTamGiacDuoiDuongCheoPhu(int a[][100], int m, int n) {
    printf("Cac so le trong tam giac duoi cua duong cheo phu:\n");
    for (int i = 1; i < m && i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i][j] % 2 != 0) {
                printf("%d\t", a[i][j]);
            }
        }
    }
}

void nhapHaiMaTran(int a[][100], int b[][100], int m, int n) {
    printf("Nhap ma tran A:\n");
    nhapMaTran(a, m, n);

    printf("Nhap ma tran B:\n");
    nhapMaTran(b, m, n);
}

void tinhTongHaiMaTran(int a[][100], int b[][100], int c[][100], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void tinhTichHaiMaTran(int a[][100], int b[][100], int c[][100], int m, int n, int p) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int m, n;
    printf("Nhap so dong: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);

    int a[100][100], b[100][100], c[100][100];

    
    nhapMaTran(a, m, n);
    xuatMaTran(a, m, n);

    int max = timMax(a, m, n);
    int min = timMin(a, m, n);

    printf("Phan tu lon nhat trong ma tran: %d\n", max);
    printf("Phan tu nho nhat trong ma tran: %d\n", min);

    int countPrime, sum;
    demVaTinhTong(a, m, n, &countPrime, &sum);

    printf("So luong so nguyen to: %d\n", countPrime);
    printf("Tong cac phan tu tren ma tran: %d\n", sum);

    // C�c ph?n c�n l?i c?a b�i t?p c� th? tri?n khai tuong t?.
    
    int x;
    printf("Nhap gia tri x can tim: ");
    scanf("%d", &x);

    // Y�u c?u 6
    timVaInViTriX(a, m, n, x);

    // Y�u c?u 7
    inDiemYenNgua(a, m, n);

    // Y�u c?u 8
    sapXepTangDan(a, m, n);
    printf("Ma tran sau khi sap xep tang dan:\n");
    xuatMaTran(a, m, n);

    // Y�u c?u 9
    int tongCheoChinh = tinhTongDuongCheoChinh(a, m, n);
    printf("Tong cac phan tu tren duong cheo chinh: %d\n", tongCheoChinh);

    // Y�u c?u 10
    int countChanTamGiac = demSoChanTamGiacTrenDuongCheoChinh(a, m, n);
    printf("So luong so chan tren tam giac tren cua duong cheo chinh: %d\n", countChanTamGiac);

    // Y�u c?u 11
    inSoLeTamGiacDuoiDuongCheoPhu(a, m, n);

    // Y�u c?u 12
    nhapHaiMaTran(a, b, m, n);

    tinhTongHaiMaTran(a, b, c, m, n);
    printf("Tong hai ma tran A va B:\n");
    xuatMaTran(c, m, n);


    return 0;
}
