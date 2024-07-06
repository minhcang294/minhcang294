#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <cmath>    // For std::sqrt
#include <algorithm> // For std::sort
#include <cstddef>   // For NULL definition
using namespace std;

// �?nh nghia c?u tr�c Tam gi�c
struct Triangle {
    double side_a;
    double side_b;
    double side_c;

    // Constructor
    Triangle(double a, double b, double c) : side_a(a), side_b(b), side_c(c) {}

    // H�m ki?m tra xem ba c?nh c� t?o th�nh tam gi�c kh�ng
    bool isTriangle() const {
        return (side_a + side_b > side_c && side_a + side_c > side_b && side_b + side_c > side_a);
    }

    // T�nh chu vi c?a tam gi�c
    double perimeter() const {
        return side_a + side_b + side_c;
    }

    // T�nh di?n t�ch c?a tam gi�c b?ng c�ng th?c Heron
    double area() const {
        double s = perimeter() / 2;
        return sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
    }

    // �?nh nghia to�n t? '<' d? s?p x?p tam gi�c theo di?n t�ch
    bool operator<(const Triangle& other) const {
        return this->area() < other.area();
    }

    // In th�ng tin tam gi�c
    void print() const {
        cout << "Canh a: " << side_a << ", Canh b: " << side_b << ", Canh c: " << side_c << endl;
        cout << "Chu vi: " << perimeter() << endl;
        cout << "Dien tich: " << area() << endl;
    }
};

// L?p C�y nh? ph�n t�m ki?m d? luu tr? tam gi�c theo di?n t�ch
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

    // H�m d? quy d? th�m tam gi�c v�o c�y
    Node* insertRecursive(Node* root, Triangle t) {
        // N?u c�y r?ng, t?o n�t m?i
        if (root == NULL)
            return new Node(t);

        // Th�m v�o c�y theo di?n t�ch c?a tam gi�c
        if (t < root->triangle)
            root->left = insertRecursive(root->left, t);
        else
            root->right = insertRecursive(root->right, t);

        return root;
    }

    // Duy?t c�y v� in tam gi�c theo th? t? NLR (Preorder)
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

    // Phuong th?c ch�n tam gi�c v�o c�y
    void insert(Triangle t) {
        root = insertRecursive(root, t);
    }

    // Phuong th?c duy?t c�y theo NLR (Preorder)
    void preorderTraversal() {
        preorderTraversal(root);
    }
};

int main() {
    list<Triangle> triangleList;    // List d? luu danh s�ch tam gi�c
    stack<Triangle> triangleStack;  // Stack d? luu tam gi�c (LIFO)
    queue<Triangle> triangleQueue;  // Queue d? luu tam gi�c (FIFO)
    BinarySearchTree bst;           // C�y nh? ph�n t�m ki?m d? luu tam gi�c theo di?n t�ch

    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double a, b, c;
        cout << "Nhap thong tin tam giac thu " << i + 1 << " (canh a, b, c): ";
        cin >> a >> b >> c;

        Triangle t(a, b, c);
        if (t.isTriangle()) {
            triangleList.push_back(t);      // Th�m v�o list
            triangleStack.push(t);          // Th�m v�o stack
            triangleQueue.push(t);          // Th�m v�o queue
            bst.insert(t);                  // Th�m v�o c�y nh? ph�n t�m ki?m
        } else {
            cout << "Ba canh vua nhap khong tao thanh tam giac. Tam giac khong duoc them vao danh sach." << endl;
        }
    }

    // In danh s�ch c�c tam gi�c t? list
    cout << "\nDanh sach tam giac tu List:" << endl;
    for (list<Triangle>::iterator it = triangleList.begin(); it != triangleList.end(); ++it) {
        it->print();
        cout << endl;
    }

    // In danh s�ch tam gi�c t? stack (in theo th? t? LIFO)
    cout << "\nDanh sach tam giac tu Stack (LIFO):" << endl;
    while (!triangleStack.empty()) {
        triangleStack.top().print();
        cout << endl;
        triangleStack.pop();
    }

    // In danh s�ch tam gi�c t? queue (in theo th? t? FIFO)
    cout << "\nDanh sach tam giac tu Queue (FIFO):" << endl;
    while (!triangleQueue.empty()) {
        triangleQueue.front().print();
        cout << endl;
        triangleQueue.pop();
    }

    // In danh s�ch tam gi�c t? c�y nh? ph�n t�m ki?m theo th? t? NLR (Preorder)
    cout << "\nDanh sach tam giac tu Binary Search Tree (theo dien tich tang dan):" << endl;
    bst.preorderTraversal();

    return 0;
}


