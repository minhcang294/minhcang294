#include <iostream>
#include <string>
using namespace std;

// Ð?nh nghia c?u trúc Sinh viên
struct Student {
    int student_id;
    string full_name;
    int age;
    Student* left;
    Student* right;

    // Constructor
    Student(int id, string name, int age) {
        student_id = id;
        full_name = name;
        this->age = age;
        left = right = NULL;
    }
};

// L?p Cây nh? phân tìm ki?m
class BinarySearchTree {
private:
    Student* root;

    // Hàm h? tr? thêm sinh viên (d? quy)
    Student* insertRecursive(Student* root, Student* new_student) {
        // N?u cây r?ng, tr? v? nút m?i
        if (root == NULL)
            return new_student;

        // Chèn vào cây theo th? t? sinh viên_id
        if (new_student->student_id < root->student_id)
            root->left = insertRecursive(root->left, new_student);
        else if (new_student->student_id > root->student_id)
            root->right = insertRecursive(root->right, new_student);

        // Tr? v? nút g?c dã du?c thay d?i
        return root;
    }

    // Hàm d? quy d? th?c hi?n duy?t cây theo NLR (Preorder)
    void preorderRecursive(Student* root) {
        if (root != NULL) {
            cout << root->student_id << " - " << root->full_name << " - " << root->age << endl;
            preorderRecursive(root->left);
            preorderRecursive(root->right);
        }
    }

    // Hàm d? quy d? th?c hi?n duy?t cây theo LRN (Postorder)
    void postorderRecursive(Student* root) {
        if (root != NULL) {
            postorderRecursive(root->left);
            postorderRecursive(root->right);
            cout << root->student_id << " - " << root->full_name << " - " << root->age << endl;
        }
    }

    // Hàm d? quy d? th?c hi?n duy?t cây theo LNR (Inorder)
    void inorderRecursive(Student* root) {
        if (root != NULL) {
            inorderRecursive(root->left);
            cout << root->student_id << " - " << root->full_name << " - " << root->age << endl;
            inorderRecursive(root->right);
        }
    }

public:
    // Constructor
    BinarySearchTree() {
        root = NULL;
    }

    // Phuong th?c chèn sinh viên m?i vào cây
    void insert(Student* new_student) {
        root = insertRecursive(root, new_student);
    }

    // Phuong th?c duy?t cây theo NLR (Preorder)
    void preorderTraversal() {
        cout << "Preorder traversal:" << endl;
        preorderRecursive(root);
    }

    // Phuong th?c duy?t cây theo LRN (Postorder)
    void postorderTraversal() {
        cout << "Postorder traversal:" << endl;
        postorderRecursive(root);
    }

    // Phuong th?c duy?t cây theo LNR (Inorder)
    void inorderTraversal() {
        cout << "Inorder traversal:" << endl;
        inorderRecursive(root);
    }

    // Phuong th?c nh?p danh sách sinh viên t? bàn phím và thêm vào cây
    void inputStudents() {
        int n;
        cout << "Nhap so luong sinh vien: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int id, age;
            string name;

            cout << "Nhap thong tin sinh vien " << i + 1 << ":" << endl;
            cout << "Ma so sinh vien: ";
            cin >> id;
            cin.ignore(); // Ð? xóa ký t? '\n' còn l?i trong b? d?m
            cout << "Ho va ten: ";
            getline(cin, name);
            cout << "Tuoi: ";
            cin >> age;

            // T?o d?i tu?ng Sinh viên và thêm vào cây
            insert(new Student(id, name, age));
        }
    }
};

int main() {
    BinarySearchTree bst;

    // Nh?p thông tin sinh viên và thêm vào cây
    bst.inputStudents();

    // Th?c hi?n duy?t cây và in k?t qu? ra màn hình
    bst.preorderTraversal();
    cout << endl;
    bst.postorderTraversal();
    cout << endl;
    bst.inorderTraversal();
    cout << endl;

    return 0;
}

