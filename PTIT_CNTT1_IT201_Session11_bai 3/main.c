#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
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
    printf("Nhập phần tử node 1: ");
    scanf("%d", &value);
    node* head = createNode(value);
    node* current = head;

    for (int i = 2; i <= n; i++) {
        printf("Nhập phần tử node %d: ", i);
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

void searchList(node* head, int target) {
    node* current = head;
    int pos = 1;
    int found = 0;

    while (current != NULL) {
        if (current->data == target) {
            printf("Tìm thấy %d ở vị trí %d\n", target, pos);
            found = 1;
            break;
        }
        current = current->next;
        pos++;
    }

    if (!found) {
        printf("Không tìm thấy %d trong danh sách.\n", target);
    }
}

int main(void) {
    int n;
    printf("Nhập số phần tử trong danh sách: ");
    scanf("%d", &n);

    node* head = createList(n);
    printList(head);

    int target;
    printf("Nhập giá trị cần tìm trong danh sách: ");
    scanf("%d", &target);

    if (target <= 0) {
        printf("Giá trị không hợp lệ.\n");
    } else {
        searchList(head, target);
    }

    return 0;
}
