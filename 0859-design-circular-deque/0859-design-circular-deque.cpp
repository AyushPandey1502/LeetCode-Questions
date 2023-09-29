class MyCircularDeque {
private:
    int *deque;
    int front;
    int rear;
    int size;
public:
    MyCircularDeque(int k) {
        deque = new int[k];
        front = -1;
        rear = -1;
        size = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front == 0){
            front = size-1;
        }else{
            front --;
        }
        deque[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        else if(isEmpty()){
            front = rear = 0;
        }
        else if(front != 0 && rear == size-1){
            rear = 0;
        }else{
            rear++;
        }
        deque[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        else if(front == rear) front = rear = -1;
        else if(front == size-1) front = 0;
        else front++;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        else if(front == rear) front = rear = -1;
        else if(rear == 0) rear = size - 1;
        else rear--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return deque[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return deque[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return ((front == 0 && rear == size-1) || (front != 0 && rear ==(front - 1)%(size -1)));
    }
};
