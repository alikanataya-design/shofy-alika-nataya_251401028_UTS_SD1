#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* buatNode(int nilai) {
    Node* baru = new Node;
    baru->data = nilai;
    baru->left = NULL;
    baru->right = NULL;
    return baru;
}

Node* insert(Node* root, int nilai) {
    if (root == NULL) {
        return buatNode(nilai);
    }

    if (nilai < root->data) {
        root->left = insert(root->left, nilai);
    } 
    else if (nilai > root->data) {
        root->right = insert(root->right, nilai);
    }

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int nilaiTerkecil(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

int nilaiTerbesar(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}

void hapusTree(Node* root) {
    if (root != NULL) {
        hapusTree(root->left);
        hapusTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = NULL;
    int angka;

    cout << "Masukkan angka (0 untuk berhenti):" << endl;

    while (cin >> angka && angka != 0) {
        root = insert(root, angka);
    }

    if (root == NULL) {
        cout << "Tree masih kosong." << endl;
    } else {
        cout << "\nData (In-Order): ";
        inorder(root);

        cout << "\nNilai Terkecil: "
             << nilaiTerkecil(root);

        cout << "\nNilai Terbesar: "
             << nilaiTerbesar(root) << endl;
    }

    hapusTree(root);

    return 0;
}