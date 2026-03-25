#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue structure for BFS
struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    int front, rear, size;
    struct QNode* arr;
};

// Create queue
struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    q->size = n;
    q->arr = (struct QNode*)malloc(n * sizeof(struct QNode));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].node = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue(n);
    enqueue(q, root, 0);

    int i = 1;
    while (!isEmpty(q) && i < n) {
        struct QNode temp = dequeue(q);
        struct Node* curr = temp.node;

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left, 0);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right, 0);
        }
        i++;
    }
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root, int n) {
    if (!root) return;

    struct Queue* q = createQueue(n);

    // Range of HD
    int minHD = 0, maxHD = 0;

    // Temporary storage (array of arrays)
    int store[200][200]; // assuming limits
    int count[200] = {0};

    enqueue(q, root, 0);

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct Node* curr = temp.node;
        int hd = temp.hd;

        int index = hd + 100; // shift index to avoid negative

        store[index][count[index]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            enqueue(q, curr->left, hd - 1);

        if (curr->right)
            enqueue(q, curr->right, hd + 1);
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + 100;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", store[idx][j]);
        }
        printf("\n");
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);
    verticalOrder(root, n);

    return 0;
}
