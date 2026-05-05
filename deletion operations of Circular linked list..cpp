#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *head = NULL;
int size = 0;

// CREATE (same style)
NODE* create() {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    size++;
    return newnode;
}

// INSERT AT END (circular)
void insertEnd() {
    NODE *t, *newnode = create();

    if (head == NULL) {
        head = newnode;
        newnode->next = head;   // circular link
    } 
    else {
        t = head;
        while (t->next != head) {
            t = t->next;
        }
        t->next = newnode;
        newnode->next = head;
    }
}

// DISPLAY
void display() {
    NODE *t;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    t = head;
    do {
        printf("%d -> ", t->data);
        t = t->next;
    } while (t != head);

    printf("(back to head)\n");
}

/////////////////////////////////////////////////
// ?? DELETION OPERATIONS
/////////////////////////////////////////////////

// DELETE AT BEGIN
void deleteAtBegin() {
    NODE *temp, *last;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    // find last node
    last = head;
    while (last->next != head) {
        last = last->next;
    }

    printf("%d is removed\n", temp->data);

    head = head->next;
    last->next = head;   // maintain circle

    size--;
    free(temp);
}

// DELETE AT END
void deleteAtEnd() {
    NODE *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    printf("%d is removed\n", temp->data);

    prev->next = head;   // circular link
    size--;
    free(temp);
}

// DELETE AT POSITION
void deleteAtPosition() {
    int p, loc = 0;
    NODE *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &p);

    if (p == 1) {
        deleteAtBegin();
        return;
    }

    if (p == size) {
        deleteAtEnd();
        return;
    }

    if (p < 1 || p > size) {
        printf("No such position\n");
        return;
    }

    temp = head;

    while (temp->next != head) {
        loc++;
        if (loc == p) break;
        prev = temp;
        temp = temp->next;
    }

    printf("%d is removed\n", temp->data);

    prev->next = temp->next;
    size--;
    free(temp);
}

/////////////////////////////////////////////////

int main() {
    int ch;

    do {
        printf("\n1.Insert\n2.Delete Begin\n3.Delete End\n4.Delete Position\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertEnd(); break;
            case 2: deleteAtBegin(); break;
            case 3: deleteAtEnd(); break;
            case 4: deleteAtPosition(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }

    } while (1);

    return 0;
}