#include <iostream>
#include <string>
using namespace std;

// �?nh nghia c?u tr�c Sinh vi�n
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

// L?p C�y nh? ph�n t�m ki?m
class BinarySearchTree {
private:
    Student* root;

    // H�m h? tr? th�m sinh vi�n (d? quy)
    Student* insertRecursive(Student* root, Student* new_student) {
        // N?u c�y r?ng, tr? v? n�t m?i
        if (root == NULL)
            return new_student;

        // Ch�n v�o c�y theo th? t? sinh vi�n_id
        if (new_student->student_id < root->student_id)
            root->left = insertRecursive(root->left, new_student);
        else if (new_student->student_id > root->student_id)
            root->right = insertRecursive(root->right, new_student);

        // Tr? v? n�t g?c d� du?c thay d?i
        return root;
    }

    // H�m d? quy d? th?c hi?n duy?t c�y theo NLR (Preorder)
    void preorderRecursive(Student* root) {
        if (root != NULL) {
            cout << root->student_id << " - " << root->full_name << " - " << root->age << endl;
            preorderRecursive(root->left);
            preorderRecursive(root->right);
        }
    }

    // H�m d? quy d? th?c hi?n duy?t c�y theo LRN (Postorder)
    void postorderRecursive(Student* root) {
        if (root != NULL) {
            postorderRecursive(root->left);
            postorderRecursive(root->right);
            cout << root->student_id << " - " << root->full_name << " - " << root->age << endl;
        }
    }

    // H�m d? quy d? th?c hi?n duy?t c�y theo LNR (Inorder)
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

    // Phuong th?c ch�n sinh vi�n m?i v�o c�y
    void insert(Student* new_student) {
        root = insertRecursive(root, new_student);
    }

    // Phuong th?c duy?t c�y theo NLR (Preorder)
    void preorderTraversal() {
        cout << "Preorder traversal:" << endl;
        preorderRecursive(root);
    }

    // Phuong th?c duy?t c�y theo LRN (Postorder)
    void postorderTraversal() {
        cout << "Postorder traversal:" << endl;
        postorderRecursive(root);
    }

    // Phuong th?c duy?t c�y theo LNR (Inorder)
    void inorderTraversal() {
        cout << "Inorder traversal:" << endl;
        inorderRecursive(root);
    }

    // Phuong th?c nh?p danh s�ch sinh vi�n t? b�n ph�m v� th�m v�o c�y
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
            cin.ignore(); // �? x�a k� t? '\n' c�n l?i trong b? d?m
            cout << "Ho va ten: ";
            getline(cin, name);
            cout << "Tuoi: ";
            cin >> age;

            // T?o d?i tu?ng Sinh vi�n v� th�m v�o c�y
            insert(new Student(id, name, age));
        }
    }
};

int main() {
    BinarySearchTree bst;

    // Nh?p th�ng tin sinh vi�n v� th�m v�o c�y
    bst.inputStudents();

    // Th?c hi?n duy?t c�y v� in k?t qu? ra m�n h�nh
    bst.preorderTraversal();
    cout << endl;
    bst.postorderTraversal();
    cout << endl;
    bst.inorderTraversal();
    cout << endl;

    return 0;
}

