#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    pq[size] = x;
    size++;

    // Sort the array so smallest element stays first
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(pq[i] > pq[j]) {
                int temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
        }
    }
}

// Delete highest priority element
void delete() {
    if(size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for(int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

// Peek highest priority element
void peek() {
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0) {
            delete();
        }
        else if(strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
