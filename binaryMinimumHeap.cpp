#include <iostream>

using namespace std;


class BinaryMinHeap {

    private:
      int *heap;
      int heapSize;
      int arraySize;

      int getLeftChild(int index) {
          return 2 * index + 1;
      }

      int getRightChild(int index) {
          return 2 * index + 2;
      }

      int getParent(int index) {
        return (index - 1) / 2;
      }

      bool hasRight(int index){
        return getRightChild(index) < heapSize;
      }

      bool hasLeft(int index){
        return getLeftChild(index) < heapSize;
      }

    public:
      BinaryMinHeap(int size) {
        heap = new int[size];
        heapSize = 0;
        arraySize = size;
      }

    void heapifyUp(int index) {
        if (index != 0){
            int parent = getParent(index);
            if (heap[parent] > heap[index]) {
                swap(parent,index);
                heapifyUp(parent);
            }
        }
    }

    void swap(int i,int j){
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    
    void insert(int data) {
      if (heapSize == arraySize)
        return;
      else {
        heapSize++;
        heap[heapSize - 1] = data;
        heapifyUp(heapSize - 1);
      }
    }

    int removeMin(){
        if(heapSize == 0)
            return -1;
        else{
            int root = heap[0];
            heap[0] = heap[heapSize - 1];
            heapSize--;
            if (heapSize > 1)
              heapifyDown(0);
            return root;
        }

    }
    
    void heapifyDown(int index){
      // get left and right child indicies of current node
      int leftChild = getLeftChild(index);
      int rightChild = getRightChild(index);
      int min = index;
      if(hasLeft(index) && heap[leftChild] < heap[min])
        min = leftChild;
      if(hasRight(index) && heap[rightChild] < heap[min])
        min = rightChild;
      if (min != index) {
        swap(index,min);
        heapifyDown(min);
	  }
    }


};
int main(){
   BinaryMinHeap heap(5);
   heap.insert(12);
   heap.insert(20);
   heap.insert(9);
   heap.insert(5);
   heap.insert(20);
   cout << heap.removeMin() << endl;
}