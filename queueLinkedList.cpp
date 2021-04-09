#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }

};

class QueueLinkedListImpl{
    private:
        Node *front;
        Node *rear;

    public:
        QueueLinkedListImpl(){
            front = rear = NULL;
        }
        ~QueueLinkedListImpl(){
            Node *next;
            while(front != NULL){
                next = front->next;
                delete front;
                front = next;
            }
        }

        void enqueue(int data){

            Node *n = new Node(data);
            if(rear == NULL)
                rear = front = n;
            // add n to the back of our queue
            else{
                rear->next = n;
                rear = n;
            }
        }

        int dequeue(){
            if(front == NULL) //empty queue
                return -1;

            Node *temp = front;
            int tempData = front->data;

            if(front == rear)
                front = rear = NULL;
            else
                front = front->next; // advance front to the next node in line
                
            delete temp;
            return tempData;
        }
};

int main(){
    QueueLinkedListImpl b1;
    b1.enqueue(1);
    b1.enqueue(2);
    b1.enqueue(3);
    cout << b1.dequeue() << endl;
    cout << b1.dequeue() << endl;
    cout << b1.dequeue() << endl;
}