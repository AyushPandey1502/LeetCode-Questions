class MyCircularQueue {
private:
    int front;
    int rear;
    int *queue;
    int maxSize;

public:
    MyCircularQueue(int k) {
        queue = new int[k];
        front = -1;
        rear = -1;
        maxSize = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false; 
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % maxSize; 
        queue[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false; 
        }
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % maxSize; 
        }
        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1; 
        }
        return queue[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1; 
        }
        return queue[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % maxSize == front;
    }
};
