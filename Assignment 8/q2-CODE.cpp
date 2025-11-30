// question 2

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

    bool search_Element(node *root,int element){
        if(root==nullptr){
            return false;
        }
        else if(root->d>element){
            return search_Element(root->left,element);
        }
        else if(root->d<element){
            return search_Element(root->right,element);
        }   
        else{
            return true;
        }
    }

    int max_element(node *root){
        if(root==nullptr){
            return -1;
        }
        while(root->right!=nullptr){
            root=root->right;
        }
        return root->d;
    }

    int min_element(node *root){
        if(root==nullptr){
            return -1;
        }
        while(root->left!=nullptr){
            root=root->left;
        }
        return root->d;
    }

    int successor(node *root,int x){
        node *curr=root;
        node *succ=nullptr;

        while(curr!=nullptr){
            if(x<curr->d){
                succ=curr;
                curr=curr->left;
            }
            else if(x>curr->d){
                curr=curr->right;
            }
            else{
                break;
            }
        }

        if(curr==nullptr){
            return 0;
        }

        if(curr->right!=nullptr){
            node *temp=curr->right;
            while(temp->left!=nullptr){
                temp=temp->left;
            }
            return temp->d;
        }

        if(succ!=nullptr){
            return succ->d;
        }
        else{
            return 0;
        }
    }

    int predecessor(node *root,int x){
        node *curr=root;
        node *pred=nullptr;

        while(curr!=nullptr){
            if(x<curr->d){
                curr=curr->left;
            }
            else if(x>curr->d){
                pred=curr;
                curr=curr->right;
            }
            else{
                break;
            }
        }

        if(curr==nullptr){
            return 0;
        }
        
        if(curr->left!=nullptr){
            node *temp=curr->left;
            while(temp->right!=nullptr){
                temp=temp->right;
            }
            return temp->d;
        }

        if(pred!=nullptr){
            return pred->d;
        }
        else{
            return 0;
        }
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

    int num=50;
    int x=t.search_Element(t.root,num);
    if(x==1){
        cout<<num<<" is present"<<endl;
    }
    else{
        cout<<num<<" is not present"<<endl;
    }

    int max=0;
    max=t.max_element(t.root);
    cout<<"maximum element:"<<max<<endl;
    int min=0;
    min=t.min_element(t.root);
    cout<<"minimum element:"<<min<<endl;

    int succ=t.successor(t.root,50);
    int pred=t.predecessor(t.root,50);

    cout<<"successor of 50:"<<succ<<endl;
    cout<<"predecessor of 50:"<<pred<<endl;

    return 0;
}