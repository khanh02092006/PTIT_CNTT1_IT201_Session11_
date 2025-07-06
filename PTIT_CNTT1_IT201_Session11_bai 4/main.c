#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

node* createList(int n) {
    int value;
    printf("Nhập giá trị node 1: ");
    scanf("%d", &value);
    node* head = createNode(value);
    node* current = head;

    for (int i = 2; i <= n; i++) {
        printf("Nhập giá trị node %d: ", i);
        scanf("%d", &value);
        node* newNode = createNode(value);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int getLength(node* head) {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main(void) {
    int n;
    do {
        printf("Nhập số phần tử trong danh sách: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("Số lượng không hợp lệ, nhập lại!\n");
        }
    } while (n <= 0);

    node* list = createList(n);
    printList(list);

    int len = getLength(list);
    printf("Độ dài danh sách là: %d\n", len);

    return 0;
}
