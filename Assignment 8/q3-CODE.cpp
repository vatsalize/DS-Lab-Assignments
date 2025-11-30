// question 3

#include<iostream>

using namespace std;

class node{

    public:

    node *left;
    node *right;
    int d;

    node(int d){
        left=nullptr;
        right=nullptr;
        this->d=d;
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

    node *find_Min(node *root){
        while(root->left!=nullptr){
            root=root->left;
        }
        return root;
    }

    node *delete_Element(node *root,int element){

        if(root==nullptr){
            cout<<element<<" not present"<<endl;
            return nullptr;
        }

        if(root->d>element){
            root->left=delete_Element(root->left,element);
        }
        else if(root->d<element){
            root->right=delete_Element(root->right,element);
        }
        else{
            if(root->left==nullptr && root->right==nullptr){
                root=nullptr;
            }
            else if(root->left==nullptr){
                root=root->right;
            }
            else if(root->right==nullptr){
                root=root->left;
            }
            else{
                node *smallest=find_Min(root->right);
                root->d=smallest->d;
                root->right=delete_Element(root->right,smallest->d);
            }
        }
    }

    int max_depth(node *root){
        if(root==nullptr){
            return 0;
        }
        int l=max_depth(root->left);
        int r=max_depth(root->right);
        
        if(l>r){
            return 1+l;
        }
        else{
            return 1+r;
        }
    }

    int min_d(node* root){
        if(root == NULL)
            return 0;

        int left  = min_d(root->left);
        int right = min_d(root->right);

        if(left == 0)
            return right + 1;

        if(right == 0)
            return left + 1;

        return min(left, right) + 1;
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
    cout<<endl;
    t.delete_Element(t.root,50);
    cout<<"after deleting 50-inorder:";
    t.inorder(t.root);
    cout<<endl;

    int max_d=t.max_depth(t.root);
    cout<<"max depth:"<<max_d<<endl;
    int min_d=t.max_depth(t.root);
    cout<<"min depth:"<<min_d<<endl;
    
    return 0;
}