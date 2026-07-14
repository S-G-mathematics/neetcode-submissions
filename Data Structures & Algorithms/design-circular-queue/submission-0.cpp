class MyCircularQueue {
private:
    vector<int> data;
    int fll;
    int front;
    int rear;
    int size;

public:
    MyCircularQueue(int k) {
        data.resize(k, -1);
        fll = 0;
        front = -1;
        rear = -1;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        data[rear] = value;
        fll++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        data[front] = -1;

        if (fll == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        fll--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[rear];
    }

    bool isEmpty() {
        return fll == 0;
    }

    bool isFull() {
        return fll == size;
    }
};