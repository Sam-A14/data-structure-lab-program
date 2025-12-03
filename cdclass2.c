#include <stdio.h>
#define MAX 50

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = value;
        printf("%d pushed to stack.\n", value);
    }
}

int countConsecutive10() {
    int count = 0;
    int i = top;

    while (i >= 0 && stack[i] == 10) {
        count++;
        i--;
    }
    return count;
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    if (stack[top] == 10) {
        int cnt = countConsecutive10();
        if (cnt < 5) {
            printf("Cannot pop 10. Only %d consecutive 10s found. Need 5.\n", cnt);
            return;
        }
    }

    printf("%d popped from stack.\n", stack[top]);
    top--;
}


void swapAndPop(int value) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    int found = -1;

    
    for (int i = top; i >= 0; i--) {
        if (stack[i] == value) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("%d not found in stack.\n", value);
        return;
    }

    for (int i = found; i < top; i++) {
        int temp = stack[i];
        stack[i] = stack[i + 1];
        stack[i + 1] = temp;
    }

    printf("%d moved to top using swap.\n", value);
    pop();  
}


void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n===== STACK MENU =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Swap and Pop (non-10)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Enter value to pop using swap: ");
                scanf("%d", &value);
                swapAndPop(value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
