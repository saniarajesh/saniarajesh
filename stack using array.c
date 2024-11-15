#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

int isFull() { return top == MAX - 1; }
int isEmpty() { return top == -1; }

void push(int value) {
    if (isFull()) 
        printf("Stack overflow\n");
    else 
        stack[++top] = value;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return -1;
    } else
        return stack[top--];
}

void display() {
    if (isEmpty())
        printf("Stack is empty\n");
    else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--)
            printf("%d\t", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("Choose the operation:\n");
        printf("1. Push\t2. Pop\t3. Display\t4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert:\n");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    printf("The element %d is popped\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
