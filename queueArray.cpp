#include <iostream>

using namespace std;

class queueArray{
    private:
        int front, rear, size, numberOfElements;
        int *queueArr; //to dynamically create an array
        
        void resize(){
            
        }
        
    public:
        queueArray(int size){
            this->size=size;
            front=rear=-1; //empty queue
            numberOfElements=0;
            queueArr = new int[size];
        }
        ~queueArray(){
            delete [] queueArr;
        }
        
        void enqueue(int data){
            if(numberOfElements=size){
                resize();
            }
            if(front==-1 && rear==-1)
                front=rear=0;
            else{
                rear = (rear + 1) % size; //formula for enqueue 
            }
            queueArr[rear]=data;
            numberOfElements++;
        }
        
        int dequeue(){
            if(numberOfElements=0){
                cout<<"The list is already empty";
                return -1;
            }
            else{
                int tempvar=queueArr[front]; //front because queue deletes from left to right,(first out)
                
                if(front==rear) //if front is rear, that means only one element within our queue. 
                    front=rear=-1;
                //Set rear and front to -1 to symbolize empty queue
                else
                    front = (front + 1) % size;
                numberOfElements--;
                return tempvar;
            }
        }   
};

int main(){
    queueArray b1(3);
    b1.enqueue(1);
    b1.enqueue(2);
    b1.enqueue(3);
    cout << b1.dequeue() << endl;
    cout << b1.dequeue() << endl;
    cout << b1.dequeue() << endl;
}
