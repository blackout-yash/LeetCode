class MyCircularDeque {
public:
	int *arr;
	int front, rear, size;
	MyCircularDeque(int k) {
		size = k;
		arr = new int[k];
		front = rear = -1;
	}

	bool insertFront(int value) {
		if (isFull()) return 0;
		else if (front == -1) front = 0;
		else front = (front - 1 + size) % size;
		arr[front] = value;
		if (rear == -1) rear = front;
		return 1;
	}

	bool insertLast(int value) {
		if (isFull()) return 0;
		rear = (rear + 1) % size;
		arr[rear] = value;
		if (front == -1) front = rear;
		return 1;
	}

	bool deleteFront() {
		if (isEmpty()) return 0;
		else if (front == rear) front = rear = -1;
		else front = (front + 1) % size;
		return 1;
	}

	bool deleteLast() {
		if (isEmpty()) return 0;
		else if (front == rear) front = rear = -1;
		else rear = (rear - 1 + size) % size;
		return 1;
	}

	int getFront() {
		if (isEmpty()) return -1;
		return arr[front];
	}

	int getRear() {
		if (isEmpty()) return -1;
		return arr[rear];
	}

	bool isEmpty() {
		return (front == -1);
	}

	bool isFull() {
		return ((rear + 1) % size) == front;
	}
};