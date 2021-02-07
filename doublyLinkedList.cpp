include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int data){
            this->data = data;
            prev = NULL;
            next = NULL;
        }
};

class DoublyLinkedList{
    private:
        Node *header;
        Node *tail;
        int size;

    public:
        DoublyLinkedList(){
            header = NULL;
            tail = NULL;
            size = 0;
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
            Node *n = new Node(data);
            if(header == NULL){
                header = n;
                tail = n;
            }
            else{
                header->prev = n;
                n->next = header;
                header = n;
            }
            size++;
        }

        void removeFirst(){
            
            if(header->next == NULL){
                
                delete header; //deleting what header is pointing to
                header = NULL;
                tail = NULL;
                
            }

            else if(header != NULL){

                header = header->next; //new 1st node
                delete header->prev; //deleting previous last node
                header->prev = NULL; 
            }
            size--;
        }
        

        void removeLast(){

            if(header->next == NULL){
                
                delete header;
                header = NULL;
                tail = NULL;
                
            }
            else if(header != NULL){
                tail = tail->prev;
                delete tail->next;
                tail->next = NULL;
            }
            size--;
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

                for(int i = 1; i < pos; i++){
                    cur = cur->next;
                }

                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
                size--;
            }
        }

        void insertAt(int pos, int data){
            if(pos < 1 || pos > size + 1)
                return;
            else if(pos == 1)
                prepend(data);
                
            else if(pos == size + 1)
                append(data);
                
            else if(header != NULL){

                Node *n = new Node(data);
                Node *cur = header;

                for(int i = 1; i < pos; i++){
                    cur = cur->next;
                }

                cur->prev->next = n; //cur->prev will give The node exactly previous to current node
                
                n->prev = cur->prev; 

                n->next = cur;

                cur->prev = n;

                size++;
            }
        }


        
        void toString(){
            Node *n = header;
            while(n != NULL){
                cout << n->data  << " ";
                n = n->next;
            }
            cout << endl;
        }

        void toStringReverse(){
            Node *n = tail;
            while(n != NULL){
                cout << n-> data << " ";
                n = n->prev;
            }
            cout << endl;
        }

};

int main(){
    DoublyLinkedList list;
    list.prepend(13);
    list.prepend(15);
    list.prepend(13);
    //list.removeAt();
    list.toString();
}
