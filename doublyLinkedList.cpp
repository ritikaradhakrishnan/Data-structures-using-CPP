#include <iostream>

using namespace std;

class Node{
    public :
        int data;
        Node *next;
        Node *prev;
        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

class LinkedList{
    private :
        Node *header;
        Node *tail;
        int size;

    public :
        LinkedList(){
            header = NULL;
            tail = NULL;
            size = 0;
        }

        ~LinkedList(){
            Node *next;
            while(header != NULL){
                next = header->next;
                delete header;
                header = next;
            }
        }

        int getSize(){
            return size;
        }

        void append(int data){
            Node *n = new Node(data);
            if(header == NULL){
                header = n;
                tail = n;
            }
            else{
                tail->next = n;
                n->prev = tail;
                tail = n;


            }
            size++;
        }

        void prepend(int data){
            Node *n = new Node(data); //node to be inserted
            if(header == NULL){
                header = n;
                tail = n;
            }
            else{
                header->prev = n;
                n->next = header; //link from right to left is also needed in doubly LL
                header = n;
            }
            size++;
        }

        void insertAt(int pos,int data){
            if(pos < 1 || pos > size + 1)
                cout<<"Enter a valid position";
                return;
            else if(pos == 1)
                prepend(data);
            else if(pos == size + 1)
                append(data);
            else if(header != NULL){
                Node *n = new Node(data); //node to be inserted
                Node *cur = header;  //current pointer points to header
                for(int i = 1; i < pos; i++) //until we reach the position
                    cur = cur->next;
                
                cur->prev->next = n;  
                n->prev = cur->prev;

                n->next = cur;
                cur->prev = n;

                size++;
            }

        }

        void removeFirst(){ 
            if(header->next == NULL){ //if only one node within list
                delete header; //delete what header is pointing to
                header = NULL; 
                tail = NULL;
                size--;
            }
            else if(header != NULL){
                header = header->next; //advance header to new first node
                delete header->prev; 
                header->prev = NULL;
                size--;
                

            }
        }

        void removeLast(){
            if(header->next == NULL){
                delete header; ////delete what header is pointing to
                header = NULL;
                tail = NULL;
                size--;
            }

            else if(header != NULL){
                tail = tail->prev; // advance tail pointer to previous node before it
                delete tail->next; // delete the previous last node
                tail->next = NULL;
                size--;
            }
        }

        void removeAt(int pos){
            if(pos < 1 || pos > size)
                return;

            else if(pos == 1)
                removeFirst();

            else if(pos == size)
                removeLast();

            else if(header != NULL){
                Node *cur = header;
                for(int i = 1; i < pos; i++)
                    cur = cur->next;

                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
                size--;

                    
            }
        }

        void printList(){
            Node *temp = header;
            while(temp != NULL){
                // Print data
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
                
        }

        void printReverse(){
            Node *n = tail;
            while(n != NULL){
                cout << n->data << " ";
                n = n->prev;
            }
            cout << endl;
        }



};

int main(){
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.insertAt(3,20);
    list.printList();
}