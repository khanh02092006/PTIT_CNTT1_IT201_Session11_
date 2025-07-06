#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

node* ceatenode(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) return NULL;
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

node* addnode(int n) {
    int value;
    printf("Nhập giá trị node 1: ");
    scanf("%d", &value);
    node* head = ceatenode(value);
    node* current = head;
    for (int i = 2; i <= n; i++) {
        printf("Nhập giá trị node %d: ", i);
        scanf("%d", &value);
        node* newnode = ceatenode(value);
        current->next = newnode;
        newnode->prev = current;
        current = newnode;
    }
    return head;
}

void printf_lit(node* head) {
    node* current = head;
    while (current != NULL) {
        printf(" %d <->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

node* themvaodau(node* head, int value) {
    node* newNode = ceatenode(value);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

node* themvaocuoi(node* head, int value) {
    node* newnode = ceatenode(value);
    if (head == NULL) return newnode;

    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
    return head;
}

int length(node* head) {
    int count = 0;
    node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

node* themvaovitribatki(node* head, int value, int k) {
    int n = length(head);
    if (k < 1 || k > n + 1) return head;

    if (k == 1) {
        return themvaodau(head, value);
    } else if (k == n + 1) {
        return themvaocuoi(head, value);
    } else {
        node* temp = head;
        for (int i = 1; i < k - 1; i++) {
            temp = temp->next;
        }

        node* newnode = ceatenode(value);
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newnode;
        temp->next = newnode;

        return head;
    }
}

int main(void) {
    int n;
    printf("Nhập số node ban đầu: ");
    scanf("%d", &n);

    node* list = addnode(n);

    printf("Danh sách ban đầu:\n");
    printf_lit(list);

    int value, pos;
    printf("Nhập giá trị muốn thêm: ");
    scanf("%d", &value);
    printf("Nhập vị trí muốn thêm (tính từ 1): ");
    scanf("%d", &pos);

    list = themvaovitribatki(list, value, pos);

    printf("Danh sách sau khi thêm:\n");
    printf_lit(list);

    return 0;
}
