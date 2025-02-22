#include <iostream>
using namespace std;

class PrintQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    PrintQueue(int initialCapacity = 10)
    {
        capacity = initialCapacity;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~PrintQueue()
    {
        delete[] arr;
    }

    void resize()
    {
        int newCapacity = capacity * 2;
        int *newArr = new int[newCapacity];

        for (int i = 0; i < size; i++)
        {
            int index = front + i;
            if (index >= capacity)
                index -= capacity;
            newArr[i] = arr[index];
        }

        delete[] arr;
        arr = newArr;
        front = 0;
        rear = size;
        capacity = newCapacity;
    }

    void enqueue(int job)
    {
        if (size == capacity)
        {
            resize();
        }
        rear = rear + 1;
        if (rear == capacity)
            rear = 0;
        arr[rear] = job;
        size++;
    }

    int dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        int job = arr[front];
        front = front + 1;
        if (front == capacity)
            front = 0;
        size--;
        return job;
    }

    // helper function for checking for the empty queue
    bool isEmpty() const
    {
        return size == 0;
    }

    // helper function for getting the size of the queue
    int getSize() const
    {
        return size;
    }
};

int main()
{
    PrintQueue queue;

    queue.enqueue(101);
    queue.enqueue(102);
    queue.enqueue(103);
    cout << "Processing job: " << queue.dequeue() << endl;
    cout << "Processing job: " << queue.dequeue() << endl;
    queue.enqueue(104);
    queue.enqueue(105);

    while (!queue.isEmpty())
    {
        cout << "Processing job: " << queue.dequeue() << endl;
    }
    return 0;
}
