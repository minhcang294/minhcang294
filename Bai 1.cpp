#include <stdio.h>

// Ðinh nghia hàm doi cho hai phan tu
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm chia mang theo giá tri pivot và tra ve vi trí pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chon phan tu cuoi cùng làm pivot
    int i = low - 1; // Chi so cua phan tu nho hon pivot

    for (int j = low; j <= high - 1; j++) {
        // Neu phan tu hien thi nho hon hoac bang pivot
        if (arr[j] <= pivot) {
            i++; // Tang chi so cua phan tu nho hon pivot
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Hàm th?c hi?n gi?i thu?t Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // p là ch? s? noi pivot dã d?ng dúng v? trí
        int p = partition(arr, low, high);

        // S?p x?p các ph?n t? tru?c và sau phân ho?ch
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Hàm xu?t m?ng ra màn hình
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100]; // Khai báo m?ng có th? ch?a t?i da 100 ph?n t?
    int n;

    // Nh?p s? lu?ng ph?n t? c?a m?ng
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    // Nh?p các ph?n t? c?a m?ng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // G?i hàm quickSort d? s?p x?p m?ng
    quickSort(arr, 0, n - 1);

    // In ra màn hình m?ng sau khi dã s?p x?p
    printf("Day so sau khi sap xep tang dan la: ");
    printArray(arr, n);

    return 0;
}

