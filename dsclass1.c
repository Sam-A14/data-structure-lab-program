#include <stdio.h>
#define MAX 50
int stack[MAX];
int top = -1;


void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = value;
        printf("%d pushed.\n", value);
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


void bringNon10ToTop() {
    int i;


    for (i = top; i >= 0; i--) {
        if (stack[i] != 10) {
            break;
        }
    }

    if (i < 0) return;  

    
    for (int j = i; j < top; j++) {
        int temp = stack[j];
        stack[j] = stack[j + 1];
        stack[j + 1] = temp;
    }

    printf("Automatically swapped %d to top.\n", stack[top]);
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    
    if (stack[top] == 10) {
        int cnt = countConsecutive10();
        if (cnt < 5) {
            printf(" Cannot pop 10. Only %d consecutive 10s found. Need 5.\n", cnt);

            
            bringNon10ToTop();

           
            if (stack[top] == 10) {
                printf("Still cannot pop. No non-10 available.\n");
                return;
            }
        }
    }

    printf("%d popped.\n", stack[top]);
    top--;
}


void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
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
        printf("2. Pop (automatic)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                display();
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
