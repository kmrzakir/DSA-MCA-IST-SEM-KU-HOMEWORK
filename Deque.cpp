#include <iostream>
using namespace std;

class Deque {
    int *arr;
    int front, rear;
    int size;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }

        arr[front] = x;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = x;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertRear(30);

    cout << "Deque: ";
    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    cout << "After deletion: ";
    dq.display();

    cout << "Front = " << dq.getFront() << endl;
    cout << "Rear = " << dq.getRear() << endl;

    return 0;
}