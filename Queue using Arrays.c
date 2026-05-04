#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// ENQUEUE (Insert)
void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    }
    else {
        int value;
        printf("Enter value: ");
        scanf("%d", &value);

        if (front == -1) {   // first element
            front = 0;
        }

        rear = rear + 1;
        queue[rear] = value;

        printf("%d inserted\n", value);
    }
}

// DEQUEUE (Delete)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    }
    else {
        int value = queue[front];
        printf("%d removed\n", value);

        if (front == rear) {   // last element
            front = -1;
            rear = -1;
        }
        else {
            front = front + 1;
        }
    }
}

// PEEK
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    }
    else {
        printf("Front = %d\n", queue[front]);
        printf("Rear = %d\n", queue[rear]);
    }
}

// DISPLAY
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    }
    else {
        int i;
        printf("Queue elements:\n");

        for (i = front; i <= rear; i = i + 1) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// MAIN
int main() {
    int choice;

    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}