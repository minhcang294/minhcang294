#include <stdio.h>
#include <stdlib.h>

// Struct d? bi?u di?n m?t kh?i hình h?p
struct Box {
    int chieurong;
    int chieudai;
    int cao;
    int thetich;
    struct Box *left;
    struct Box *right;
};

// T?o m?t kh?i hình h?p m?i
struct Box *createBox(int chieurong, int chieudai, int cao) {
    struct Box *newBox = (struct Box *)malloc(sizeof(struct Box));
    newBox->chieurong = chieurong;
    newBox->chieudai = chieudai;
    newBox->cao = cao;
    newBox->thetich = chieurong * chieudai * cao;
    newBox->left = NULL;
    newBox->right = NULL;
    return newBox;
}

// Chèn m?t kh?i hình h?p vào cây nh? phân tìm ki?m theo chi?u dài
struct Box *insert(struct Box *root, int chieurong, int chieudai, int cao) {
    if (root == NULL) {
        return createBox(chieurong, chieudai, cao);
    }

    // Chèn vào cây nh? phân
    if (chieudai < root->chieudai) {
        root->left = insert(root->left, chieurong, chieudai, cao);
    } else {
        root->right = insert(root->right, chieurong, chieudai, cao);
    }

    return root;
}

// Duy?t cây nh? phân theo th? t? tang d?n (inorder) và in ra thông tin c?a t?ng kh?i hình h?p
void inorderTraversal(struct Box *root, int *stt) {
    if (root != NULL) {
        inorderTraversal(root->left, stt);
        printf("%-4d %-10d %-10d %-6d %-8d\n", (*stt)++, root->chieurong, root->chieudai, root->cao, root->thetich);
        inorderTraversal(root->right, stt);
    }
}

int main() {
    struct Box *root = NULL;
    int n, chieurong, chieudai, cao;

    printf("Nhap so luong khoi hinh hop: ");
    scanf("%d", &n);

    printf("Nhap thong tin cho tung khoi hinh hop (chieurong, chieudai, cao):\n");
    for (int i = 0; i < n; i++) {
        printf("Khoi hinh hop %d: ", i + 1);
        scanf("%d %d %d", &chieurong, &chieudai, &cao);
        root = insert(root, chieurong, chieudai, cao);
    }

    // In ra b?ng thông tin
    printf("\nBang thong tin cac khoi hinh hop sau khi sap xep theo chieu dai la:\n");
    printf("STT  Chieurong  Chieudai   Cao    Thetich  \n");
    int stt = 1;
    inorderTraversal(root, &stt);

    return 0;
}

