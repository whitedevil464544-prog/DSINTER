#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *head = NULL;
int size = 0;

// CREATE (your style)
NODE* create() {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    size++;
    return newnode;
}

// INSERT AT END (to build list)
void insertEnd() {
    NODE *t, *newnode = create();

    if (head == NULL) {
        head = newnode;
    } else {
        t = head;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = newnode;
    }
}

// DISPLAY
void display() {
    NODE *t = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

/////////////////////////////////////////////////
// ?? DELETION OPERATIONS
/////////////////////////////////////////////////

// DELETE AT BEGIN
void deleteAtBegin() {
    NODE *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("%d is removed\n", temp->data);
    head = head->next;
    size--;
    free(temp);
}

// DELETE AT END (minimal style)
void deleteAtEnd() {
    NODE *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("%d is removed\n", temp->data);
    prev->next = NULL;
    size--;
    free(temp);
}

// DELETE AT POSITION (clean logic)
void deleteAtPosition() {
    int p, i = 1,loc=0;
    NODE *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &p);

    // BEGIN
    if (p == 1) {
        deleteAtBegin();
        return;
    }

    // END
    if (p == size) {
        deleteAtEnd();
        return;
    }

    // INVALID
    if (p < 1 || p > size) {
        printf("No such position\n");
        return;
    }
    
    else { 
   temp=head;
    
   while(temp->next!=NULL) 
     { 
         loc++; 
        if(loc==p) 
            break; 
        prev=temp; 
        temp=temp->next; 
     } 
   printf("%d is removed\n",temp->data); 
   prev->next=temp->next; 
   size--; 
   free(temp); 
   } 
    
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