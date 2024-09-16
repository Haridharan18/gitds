#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *s);
void pop(Stack *s);
void displayStack(Stack *s);

int main() {
    Stack s;  // Declare an instance of Stack
    s.top = -1;  // Initialize the stack

    int choice;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&s);
                break;

            case 2:
                pop(&s);
                break;

            case 3:
                displayStack(&s);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void push(Stack *s) {
    int value;
    // Check if the stack is full
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &value);
    s->arr[++(s->top)] = value;
}

void pop(Stack *s) {
    // Check if the stack is empty
    if (s->top == -1) {
        printf("Stack underflow\n");
        return;
    }
    printf("Popped value: %d\n", s->arr[s->top--]);
}

void displayStack(Stack *s) {
    // Check if the stack is empty
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}
