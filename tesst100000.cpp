#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SinhVien {
    int maSV;
    char hoTen[50];
    int tuoi;
    struct SinhVien *next;
};


void nhapThongTinSV(struct SinhVien **head) {
    struct SinhVien *newSV = (struct SinhVien *)malloc(sizeof(struct SinhVien));
    if (newSV == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }

    printf("Nhap ma so sinh vien: ");
    scanf("%d", &newSV->maSV);
    printf("Nhap ho ten: ");
    scanf(" %[^\n]s", newSV->hoTen); 
    printf("Nhap tuoi: ");
    scanf("%d", &newSV->tuoi);

    newSV->next = *head;
    *head = newSV;
}


void inDanhSach(struct SinhVien *head) {
    printf("\nDanh sach sinh vien:\n");
    printf("Ma SV\tHo ten\t\tTuoi\n");
    while (head != NULL) {
        printf("%d\t%s\t\t%d\n", head->maSV, head->hoTen, head->tuoi);
        head = head->next;
    }
}

int main() {
    struct SinhVien *head = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. In danh sach sinh vien\n");
        printf("3. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapThongTinSV(&head);
                break;
            case 2:
                inDanhSach(head);
                break;
            case 3:
                printf("CUTS!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 3);

    
    while (head != NULL) {
        struct SinhVien *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

