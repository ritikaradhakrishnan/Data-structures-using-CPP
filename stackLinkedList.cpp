#include <iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data=data;
            next=NULL;
    }
};

class StackusingLL{
    private:
        Node *top;
    public:
        StackusingLL(){
            top=NULL; //stack empty
        }
        
        ~StackusingLL(){
            // pointer which always points to the next node within our list
            Node *next;
            // keep going until top does not equal NULL
            while(top != NULL){
                // advance to pointer to point to next node
                next = top->next;
                // delete node that top is pointing to
                delete top;
                // advance top to point to the next node
                top = next;
            }
        }       
        
    void push(int data){
        Node *n = new Node(data);
        if(top==NULL){
            top=n; //if empty then top will point to new node
        }
        else{
            n->next=top;
            top=n;
        }
    }
    
    int pop(){
        if(top==NULL){
            cout<<"The stack is empty";
            return -1;
        }
        else{
            int tempVar = top->data; //temp variable will store the data
            Node *temp = top; //temp pointer will point to top pointer
            top = top->next; //moves forward
            delete temp; //deletes whatever old pointer temp was pointing to
            return tempVar; //returns the popped value
            
            
        }
    }
    
    
    
    
    
    
};





int main(){

    StackusingLL BB;
    BB.push(1);
    BB.push(2);
    BB.push(7);
    cout<<BB.pop()<<endl;
    cout<<BB.pop()<<endl;
    
    return 0;
}
