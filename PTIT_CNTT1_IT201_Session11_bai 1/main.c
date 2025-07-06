#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* makeNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* createList(int n) {
    if (n <= 0) return NULL;

    int value;
    printf("Nhập giá trị node 1: ");
    scanf("%d", &value);
    Node* head = makeNode(value);
    Node* current = head;

    for (int i = 2; i <= n; i++) {
        printf("Nhập giá trị node %d: ", i);
        scanf("%d", &value);
        Node* newNode = makeNode(value);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void) {
    int n;
    printf("Nhập số lượng node: ");
    scanf("%d", &n);

    Node* list = createList(n);
    print_list(list);

    return 0;
}
