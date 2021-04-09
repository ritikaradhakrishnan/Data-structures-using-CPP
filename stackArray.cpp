#include <iostream>

using namespace std;

class StackArrayImpl{
    private:
        int size;
        int *stackArr;
        int top; //poisition of top of stack
        void resize(){ //incase our stack becomes full
            int tempSize = size * 2; 
            int *temp = new int[tempSize];
            for(int i = 0; i < size;i++)
                temp[i] = stackArr[i]; //copy old array elements to new array
            delete [] stackArr; //delete old array
            stackArr = temp; //set old array variable to new array
            size = tempSize; //size will be new size
        }
    public:
        StackArrayImpl(int size){
            this->size = size;
            stackArr = new int[size];
            top = -1; //at the bottom
        }

        ~StackArrayImpl(){
            delete [] stackArr;
        }

        void push(int data){
            //if stack is full, resize array
            if(top == size - 1)
                resize();
            stackArr[++top] = data; //top changes from 0 to 1 and then adds data
        }

        int pop(){ //in stack pop does not actually delete, it overrides old data that was popped, if push() is used
            // if stack is empty, nothing to pop
            if(top == -1)
                return -1;
            // remove and return data from the top of the stack
            return stackArr[top--]; //after printing comes down to the new last element in the stack
        }

};


int main(){
    StackArrayImpl test(3);
    test.push(1);
    test.push(2);
    test.push(3);
    cout << test.pop() << endl;
}
    