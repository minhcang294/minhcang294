#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <cmath>    // For std::sqrt
#include <algorithm> // For std::sort
#include <cstddef>   // For NULL definition
using namespace std;

// Ð?nh nghia c?u trúc Tam giác
struct Triangle {
    double side_a;
    double side_b;
    double side_c;

    // Constructor
    Triangle(double a, double b, double c) : side_a(a), side_b(b), side_c(c) {}

    // Hàm ki?m tra xem ba c?nh có t?o thành tam giác không
    bool isTriangle() const {
        return (side_a + side_b > side_c && side_a + side_c > side_b && side_b + side_c > side_a);
    }

    // Tính chu vi c?a tam giác
    double perimeter() const {
        return side_a + side_b + side_c;
    }

    // Tính di?n tích c?a tam giác b?ng công th?c Heron
    double area() const {
        double s = perimeter() / 2;
        return sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
    }

    // Ð?nh nghia toán t? '<' d? s?p x?p tam giác theo di?n tích
    bool operator<(const Triangle& other) const {
        return this->area() < other.area();
    }

    // In thông tin tam giác
    void print() const {
        cout << "Canh a: " << side_a << ", Canh b: " << side_b << ", Canh c: " << side_c << endl;
        cout << "Chu vi: " << perimeter() << endl;
        cout << "Dien tich: " << area() << endl;
    }
};

// L?p Cây nh? phân tìm ki?m d? luu tr? tam giác theo di?n tích
class BinarySearchTree {
private:
    struct Node {
        Triangle triangle;
        Node* left;
        Node* right;

        // Constructor
        Node(Triangle t) : triangle(t), left(NULL), right(NULL) {}
    };

    Node* root;

    // Hàm d? quy d? thêm tam giác vào cây
    Node* insertRecursive(Node* root, Triangle t) {
        // N?u cây r?ng, t?o nút m?i
        if (root == NULL)
            return new Node(t);

        // Thêm vào cây theo di?n tích c?a tam giác
        if (t < root->triangle)
            root->left = insertRecursive(root->left, t);
        else
            root->right = insertRecursive(root->right, t);

        return root;
    }

    // Duy?t cây và in tam giác theo th? t? NLR (Preorder)
    void preorderTraversal(Node* root) {
        if (root != NULL) {
            root->triangle.print();
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

public:
    // Constructor
    BinarySearchTree() {
        root = NULL;
    }

    // Phuong th?c chèn tam giác vào cây
    void insert(Triangle t) {
        root = insertRecursive(root, t);
    }

    // Phuong th?c duy?t cây theo NLR (Preorder)
    void preorderTraversal() {
        preorderTraversal(root);
    }
};

int main() {
    list<Triangle> triangleList;    // List d? luu danh sách tam giác
    stack<Triangle> triangleStack;  // Stack d? luu tam giác (LIFO)
    queue<Triangle> triangleQueue;  // Queue d? luu tam giác (FIFO)
    BinarySearchTree bst;           // Cây nh? phân tìm ki?m d? luu tam giác theo di?n tích

    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double a, b, c;
        cout << "Nhap thong tin tam giac thu " << i + 1 << " (canh a, b, c): ";
        cin >> a >> b >> c;

        Triangle t(a, b, c);
        if (t.isTriangle()) {
            triangleList.push_back(t);      // Thêm vào list
            triangleStack.push(t);          // Thêm vào stack
            triangleQueue.push(t);          // Thêm vào queue
            bst.insert(t);                  // Thêm vào cây nh? phân tìm ki?m
        } else {
            cout << "Ba canh vua nhap khong tao thanh tam giac. Tam giac khong duoc them vao danh sach." << endl;
        }
    }

    // In danh sách các tam giác t? list
    cout << "\nDanh sach tam giac tu List:" << endl;
    for (list<Triangle>::iterator it = triangleList.begin(); it != triangleList.end(); ++it) {
        it->print();
        cout << endl;
    }

    // In danh sách tam giác t? stack (in theo th? t? LIFO)
    cout << "\nDanh sach tam giac tu Stack (LIFO):" << endl;
    while (!triangleStack.empty()) {
        triangleStack.top().print();
        cout << endl;
        triangleStack.pop();
    }

    // In danh sách tam giác t? queue (in theo th? t? FIFO)
    cout << "\nDanh sach tam giac tu Queue (FIFO):" << endl;
    while (!triangleQueue.empty()) {
        triangleQueue.front().print();
        cout << endl;
        triangleQueue.pop();
    }

    // In danh sách tam giác t? cây nh? phân tìm ki?m theo th? t? NLR (Preorder)
    cout << "\nDanh sach tam giac tu Binary Search Tree (theo dien tich tang dan):" << endl;
    bst.preorderTraversal();

    return 0;
}


