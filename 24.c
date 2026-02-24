#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* insert(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct node* deleteKey(struct node* head, int key) {
    if (head == NULL)
        return head;

    if (head->data == key) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node* curr = head;
    while (curr->next != NULL && curr->next->data != key)
        curr = curr->next;

    if (curr->next != NULL) {
        struct node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    return head;
}

void display(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, x, key;
    struct node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insert(head, x);
    }

    scanf("%d", &key);

    head = deleteKey(head, key);
    display(head);

    return 0;
}
