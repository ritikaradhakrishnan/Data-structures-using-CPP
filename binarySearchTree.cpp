#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int data){
            this->data=data;
            left=right=NULL; //no children
        }
};

class binarySearchTree{
    private: 
        Node *root; //pointer to keep track of the root of our tree
        //1st parameter is the data we want to insert & 2nd parameter is the pointer of the 'current' root
        void insertPrivate(int data, Node *&root){
        // we can root by reference so that we can make changes in the original root
        if(root==NULL){
            root = new Node(data); //tree is empty, set our root to the node we just created
        }
        else if(data < root->data){
            if(root->left != NULL){
                insertPrivate(data,root->left);
            }
            else{
                root->left=new Node(data);
            }
        }
        else if(data > root->data){
            if(root->right != NULL){
                insertPrivate(data,root->right);
            }
            else{
                root->right=new Node(data);
            }
        }
    }
        
        void removePrivate(int data, Node *&root){
            //first, we find the node to be deleted
            if(root==NULL){
                return;
            }
            else if(data<root->data){ //(if 25-to remove, 100-root node, check 25<100)
                removePrivate(data, root->left); //if less, go left
            }
            else if(data>root->data){ //(if 120-to remove, 100-root node, check 120>100)
                removePrivate(data, root->right); //if greater, go right
            }
            //after the above loop, we finnaly find the node to be deleted
            else{
                //If no child
                if(root->left==NULL&&root->right==NULL){
                    delete root;
                    root=NULL;
                }
                //If only one child
                else if(root->left==NULL){
                    Node *temp = root;
                    root=root->right;
                    delete temp;
                }
                else if(root->right==NULL){
                    Node *temp = root;
                    root=root->left;
                    delete temp;
                }
                //If 3 children
                else{
                    Node *temp = findMin(root->right);
                    root->data = temp->data;
                    removePrivate(temp->data,root->right);
                }
            }
            return;
        }
        // helper method. Finds smallest value within a tree
        Node* findMin(Node* root){
            int i = 0;
            while(root->left != NULL){
                root = root->left;
                i++;
            }
            return root;
        }
                
     
    public:
        binarySearchTree(){
            root=NULL; //tree is empty
        }
    void insert(int data){
        insertPrivate(data,root);
    }
        
    void remove(int data){
        removePrivate(data,root);
    }

};

int main(){
    binarySearchTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(7);
    tree.insert(3);
    tree.remove(5);
}
