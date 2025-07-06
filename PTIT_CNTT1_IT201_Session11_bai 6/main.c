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

node* ceatelit(int n) {
    int value;
    printf("Nhập phần tử node 1: ");
    scanf("%d", &value);
    node* head = ceatenode(value);
    node* current = head;

    for (int i = 2; i <= n; i++) {
        printf("Nhập phần tử node %d: ", i);
        scanf("%d", &value);
        node* newnode = ceatenode(value);
        current->next = newnode;
        newnode->prev = current;
        current = newnode;
    }

    return head;
}

node* removehead(node* head) {
    if (head == NULL) return NULL;
    node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

void print_lit(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void) {
    int n;
    printf("Nhập số phần tử ban đầu: ");
    scanf("%d", &n);

    node* list = ceatelit(n);

    printf("Danh sách ban đầu:\n");
    print_lit(list);

    list = removehead(list);

    printf("Danh sách sau khi xóa phần tử đầu:\n");
    print_lit(list);

    return 0;
}
