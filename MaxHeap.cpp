#include <iostream>
using namespace std;

class MaxHeap
{
    public:
        int size; // number of current elements in Heap
        int max_size; // this tells the maximum size of the heap
        int* arr;

    public:
        MaxHeap(int n)
        {
            size = 0;
            max_size = n;
            arr = new int[n];
        }
    public:
      void  insert(int elm)
            {
                if(size == max_size)
                {
                    cout<<"Max Heap is full can't inser the element's : "<<endl;
                    return;
                }
                arr[size] = elm;
                int index = size;
                size++;
                if(index > 0 && arr[(index-1)/2] < arr[index])
                {
                    swap(arr[(index-1)/2], arr[index]);
                    index = (index-1)/2;
                }

                cout<<arr[index]<<" is inserted into the heap"<<endl;
            }
    public:
            void display()
            {
                for(int i = 0; i< size; i++)
                {
                    cout<<arr[i]<<" ";
                }
            }
    
    public:
            void heapify(int index)
            {
                int left = (2*index) + 1;
                int right = (2*index) + 2;

                if(left < size && arr[left] > arr[index])
                {
                    swap(arr[left],arr[index]);
                    heapify(left);
                }
                if(right < size && arr[right] > arr[index])
                {
                    swap(arr[right],arr[index]);
                    heapify(right);
                }
            }
    
    public:
            void deleate()
            {
                if(size == 0)
                {
                    cout<<"MAX-HEAP is empty cna't deleat the element : "<<endl;
                    return;
                }
                arr[0] = arr[size-1];
                size--;

                if(size == 0)
                {
                    cout<<"After deleating the elemnt the heap became empty : "<<endl;
                    return;
                }
                heapify(0);
            }
};

int main()
{
    
    MaxHeap* obj = new MaxHeap(10);
    obj->insert(10);
    obj->insert(5);
    obj->insert(20);
    obj->insert(6);
    obj->insert(22);
    obj->insert(1);

    cout<<"BEFORE DELETE : "<<endl;
    obj->display();

    obj->deleate();

    cout<<"AFTER DELETE : "<<endl;

    obj->display();

    return 1;
}