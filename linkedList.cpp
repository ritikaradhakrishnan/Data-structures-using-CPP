#include <iostream>
#include <list>
#include <string>

using namespace std;

class Node{
    public :
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class LinkedList{
    private :
        Node *header;
        Node *tail;
        int size;

    public :
        // Default constructor to initialize private data members
        LinkedList(){
            header = NULL;
            tail = NULL;
            size = 0;
        }
        //Destructor to avoid memory leak
        ~LinkedList(){
            Node *next;
            // keep going until header != NULL
            while(header != NULL){
                // advance to pointer to point to next node
                next = header->next;
                // delete node that header is pointing to
                delete header;
                // advance header to point to the next node
                header = next;
            }
        }

        // returns the size of our list
        int getSize(){
            return size;
        }

        void append(int data){ //add at the end of list
            Node *n = new Node(data); // newly created node to be inserted
            if(header == NULL){ //If list is empty ==NULL then both header and tail will point to new node
                header = n;
                tail = n;
            }
            else{
                tail->next = n; //Tail's node's pointer will point to n
                tail = n; //tail will now point to new appended las node
            }
            size++;
        }


        void prepend(int data){ //add at the beginning of list
            Node *n = new Node(data); // newly created node to be inserted

            if(header == NULL){
                header = n;
                tail = n;
            }

            else{
                Node *temp = header; // temp pointer which saves what header is currently pointing to
                header = n; // update header to point to n, the new node that we want to prepend
                n->next = temp; //make new node's pointer point to the previous first node
            }
            size++;
        }

        void removeFirst(){ 
 
            if(header != NULL){
                Node *temp = header;  //temporary pointer to point to first node
                // advance header to point to the new first node
                header = header->next; //advance header to point to the next node, (new first node)
                delete temp; // delete previous first node
                size--; 
            }
        }

        void removeLast(){

            if(header->next == NULL){
                removeFirst();
            }

            else if(header != NULL){
               Node *cur = header; //For traversing, use CURRENT AND PREVIOUS TEMP POINTERS
               Node *prev;

               while(cur->next != NULL){ //until last node
                prev = cur; //at first, prev and current will point the same
                cur = cur->next; //advance curr, prev will point to previous node 
               }
               tail = prev; //tail is now pointing to the 2nd last node, i.e. new last node
               prev->next = NULL; //prev node's pointer will now set to NULL
               delete cur; //remove last
               size--;
            }
        }


        void removeAt(int pos){

            if(pos > size || pos < 1){ //position should be valid
                cout<<"Make sure the position is valid. ";
                return; 
            }

            else if(pos == 1){
                removeFirst();
            }

            else if(pos == size){
                removeLast();
            }

            else if(header != NULL){ //node b/w 1st and last
                Node *cur = header;
                Node *prev;
                for(int i = 1; i < pos; i++){
                    prev = cur;
                    cur = cur->next;
                }
                prev->next = cur->next; //// make the previous node point to the next node that current has
                delete cur;
                size--;
            }
        }


       void insertAt(int pos, int data){
           
            if(pos > size + 1 || pos < 1) {//'size+1' because, if we have only 'size', then we can use append
            cout<<"Make sure the position is valid. ";
            return;
            }

           else if(pos == size + 1)
           append(data);

           else if(pos == 1)
           prepend(data);
 
           else if(header != NULL){
                Node *n = new Node(data); // create new node to be inserted
                Node *cur = header; //traversing
                Node *pre;
                for(int i = 1; i < pos;i++){
                    pre = cur;
                    cur = cur->next;
                }
                // make the previous node point to new node n & make n next pointer point to current
                pre->next = n;
                n->next = cur;
                size++;
            }
        }

        void toString(){ //printing the list

            Node *n = header; // create temp pointer which points to what header is pointing to
            while(n != NULL){
                cout<<n->data<< " "; // print data part of node
                n = n->next; 
            }
            cout << endl;
        }


};

int main(){
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(4);
    list.append(5);
    list.append(6);
    list.insertAt(3,6);
    list.removeAt(2);
    list.removeFirst();
    cout<<"The linked list is: ";
    list.toString();
}