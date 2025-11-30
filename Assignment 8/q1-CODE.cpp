// question 1

#include<iostream>

using namespace std;

class node{

    public:

    int d;
    node *left;
    node *right;

    node(int d){
        this->d=d;
        left=nullptr;
        right=nullptr;
    }
};

class bst{

    public:

    node *root;

    bst(){
        root=nullptr;
    }

    node *insert(node *root,int element){

        if(root==nullptr){
            root=new node(element);
        }
        else if(root->d>element){
            root->left=insert(root->left,element);
        }
        else{
            root->right=insert(root->right,element);
        }

        return root;
    }

    void inorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            inorder(root->left);
            cout<<root->d<<" ";
            inorder(root->right);
        }
    } 

    void preorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            cout<<root->d<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(node *root){
        if(root==nullptr){
            return;
        }
        else{
            postorder(root->left);
            postorder(root->right);
            cout<<root->d<<" ";
        }
    }
};

int main(){

    bst t;

    t.root=t.insert(t.root,40);
    t.root=t.insert(t.root,20);
    t.root=t.insert(t.root,60);
    t.root=t.insert(t.root,50);
    t.root=t.insert(t.root,70);

    cout<<"inorder:";
    t.inorder(t.root);
    cout<<endl<<"postorder:";
    t.postorder(t.root);
    cout<<endl<<"preorder:";
    t.preorder(t.root);

    return 0;
}