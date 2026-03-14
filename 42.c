#include <stdio.h>
#define MAX 100

int queue[MAX], stack[MAX];
int front = 0, rear = -1;
int top = -1;

int main() {
    int n, i;

    scanf("%d", &n);

    // Input queue elements
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[++rear]);
    }

    // Push queue elements into stack
    for(i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }

    // Pop from stack back to queue
    for(i = front; i <= rear; i++) {
        queue[i] = stack[top--];
    }

    // Print reversed queue
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
