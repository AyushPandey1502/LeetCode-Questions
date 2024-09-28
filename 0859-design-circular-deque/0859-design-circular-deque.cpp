class MyCircularDeque {
private:
    vector<int> deque;
    int front, rear, capacity, count;

public:
    MyCircularDeque(int k) : deque(k), front(0), rear(k - 1), capacity(k), count(0) {}
    
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity; 
        deque[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity; 
        deque[rear] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity; 
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity; 
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return deque[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
