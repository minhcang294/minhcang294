 #include <iostream>
#include <algorithm>
using namespace std;

void nhapMang(int arr[], int n) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}


void xuatMang(int arr[], int n) {
    printf("Mang da nhap la:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void sapXepMang(int arr[], int n) {
    std::sort(arr, arr + n);
}


int timKiemTuyenTinh(int arr[], int n, int x) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}


int timKiemNhiPhan(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}


bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}


void demVaXuatSoNguyenTo(int arr[], int n) {
    int count = 0;
    std::cout << "Cac so nguyen to trong mang la:\n";
    for (int i = 0; i < n; ++i) {
        if (laSoNguyenTo(arr[i])) {
            std::cout << arr[i] << " tai vi tri " << i << std::endl;
            count++;
        }
    }
    std::cout << "Tong so luong so nguyen to trong mang la: " << count << std::endl;
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE], n, x;

    std::cout << "Nhap so luong phan tu cua mang: ";
    std::cin >> n;

    nhapMang(arr, n);
    sapXepMang(arr, n);
    xuatMang(arr, n);

    std::cout << "Nhap so can tim kiem: ";
    std::cin >> x;

    int viTriTuyenTinh = timKiemTuyenTinh(arr, n, x);
    if (viTriTuyenTinh != -1) {
        std::cout << "Tim thay " << x << " tai vi tri " << viTriTuyenTinh << " (tuyen tinh).\n";
    } else {
        std::cout << "Khong tim thay " << x << " trong mang (tuyen tinh).\n";
    }

    int viTriNhiPhan = timKiemNhiPhan(arr, n, x);
    if (viTriNhiPhan != -1) {
        std::cout << "Tim thay " << x << " tai vi tri " << viTriNhiPhan << " (nhi phan).\n";
    } else {
        std::cout << "Khong tim thay " << x << " trong mang (nhi phan).\n";
    }

    demVaXuatSoNguyenTo(arr, n);

    return 0;
}


