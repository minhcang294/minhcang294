#include <stdio.h>
#include <math.h>

// H�m nh?p m?ng
void nhapMang(int arr[], int n) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// H�m xu?t m?ng
void xuatMang(int arr[], int n) {
    printf("Mang da nhap la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// H�m t?m ki?m tuy?n t�nh
int timKiemTuyenTinh(int arr[], int n, int x) {
    int count = 0;
    printf("Tim kiem tuyen tinh:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("%d o vi tri %d\n", x, i);
            count++;
        }
    }
    return count;
}

// H�m t?m ki?m nh? ph�n
int timKiemNhiPhan(int arr[], int n, int x) {
    printf("Tim kiem nhi phan:\n");
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == x) {
            printf("%d o vi tri %d\n", x, mid);
            return 1;
        }
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

// H�m ki?m tra s? nguy�n t?
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    
    for (int i = 2; i<=sqrt(n); i++) { // hoac i*i<=n
        if (n % i == 0) return 0;
    }
    return 1;
}

// H�m t?m s? nguy�n t? trong m?ng
void timSoNguyenTo(int arr[], int n) {
    printf("Cac so nguyen to trong mang:\n");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d o vi tri %d\n", arr[i], i);
        }
    }
}

int main() {
    int n, x;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];

    nhapMang(arr, n);
    xuatMang(arr, n);

    printf("Nhap so can tim: ");
    scanf("%d", &x);
    int linearSearchCount = timKiemTuyenTinh(arr, n, x);
    if (linearSearchCount == 0)
       printf("So %d khong co trong mang.\n", x);
    else
        printf("So %d co %d lan xuat hien trong mang.\n", x, linearSearchCount);

    if (!timKiemNhiPhan(arr, n, x))
        printf("So %d khong co trong mang.\n", x);

    timSoNguyenTo(arr, n);

    return 0;
}

