// question 4

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left, *right;

    node(int d) {
        data = d;
        left = right = nullptr;
    }
};

class tree {
public:
    node* root;

    tree() {
        root = nullptr;
    }

    node* insert(node* r, int val) {
        if (!r) return new node(val);
        if (val < r->data) r->left = insert(r->left, val);
        else r->right = insert(r->right, val);
        return r;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool isBSTUtil(node* r, int minv, int maxv) {
        if (!r) return true;

        if (r->data < minv || r->data > maxv)
            return false;

        return isBSTUtil(r->left, minv, r->data - 1) &&
               isBSTUtil(r->right, r->data + 1, maxv);
    }

    bool isBST() {
        return isBSTUtil(root, -100000, 100000);
    }

    void inorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    } 
};

int main() {
    tree t;

    t.root = new node(10);
    t.root->left = new node(5);
    t.root->right = new node(15);
    t.root->right->left = new node(12);
    t.root->right->right = new node(20);

    if (t.isBST()){
        cout << "The tree is a BST"<<endl;
    } 
    else{
        cout << "The tree is NOT a BST"<<endl;
    }

    t.inorder(t.root);

    return 0;
}
