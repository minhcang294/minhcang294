#include <stdio.h>

// �inh nghia h�m doi cho hai phan tu
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// H�m chia mang theo gi� tri pivot v� tra ve vi tr� pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chon phan tu cuoi c�ng l�m pivot
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

// H�m th?c hi?n gi?i thu?t Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // p l� ch? s? noi pivot d� d?ng d�ng v? tr�
        int p = partition(arr, low, high);

        // S?p x?p c�c ph?n t? tru?c v� sau ph�n ho?ch
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// H�m xu?t m?ng ra m�n h�nh
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100]; // Khai b�o m?ng c� th? ch?a t?i da 100 ph?n t?
    int n;

    // Nh?p s? lu?ng ph?n t? c?a m?ng
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    // Nh?p c�c ph?n t? c?a m?ng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // G?i h�m quickSort d? s?p x?p m?ng
    quickSort(arr, 0, n - 1);

    // In ra m�n h�nh m?ng sau khi d� s?p x?p
    printf("Day so sau khi sap xep tang dan la: ");
    printArray(arr, n);

    return 0;
}

