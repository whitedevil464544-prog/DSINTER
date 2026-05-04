#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;
int count = 0;

// PUSH
void push() {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    }
    else {
        int value;
        printf("Enter value to push: ");
        scanf("%d", &value);

        top = top + 1;        // move top
        stack[top] = value;   // insert value
        count = count + 1;

        printf("%d inserted\n", value);
    }
}

// POP
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    }
    else {
        int value = stack[top];  // get top value
        top = top - 1;           // move down
        count = count - 1;

        printf("%d removed\n", value);
    }
}

// PEEK
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Top element is %d\n", stack[top]);
    }
}

// DISPLAY
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    }
    else {
        int i;
        printf("Stack elements:\n");

        for (i = top; i >= 0; i = i - 1) {
            printf("%d\n", stack[i]);
        }
    }
}

// MAIN
int main() {
    int choice;

    do {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Count\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: printf("Total elements = %d\n", count); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }

    } while (choice != 6);

    return 0;
}