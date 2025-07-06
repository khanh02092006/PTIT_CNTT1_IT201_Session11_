#include <stdio.h>
#include <stdlib.h>

typedef  struct
{
    int data;
    struct  node* next;
    struct node* prev;
}node;
node *ceatenode(int value)
{
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL) return NULL;
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
node *ceatalit(int n)
{
    int value;
printf("nhap gia ttri node 1:");
    scanf("%d",&value);
    node *head=ceatenode(value);
    node * current= head;
    for (int i=2;i<=n;i++)
    {
        printf(" nhap gia tri node %d",i);
        scanf("%d",&value);
        node *newnode=ceatenode(value);
        current->next=newnode;
        newnode-> prev=current;
        current=newnode;
    }
    return head;
}
node* themdau(node *head, int value)
{
    node * newnode =ceatenode(value);
    newnode->next=head;
    if(head==NULL)
    {
        head->prev=newnode;
    }
    return newnode;
}
void pfint_lit(node* head)
{
    node *current=head;
    while(current!=NULL)
    {
        printf("%d<-> ",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
int main(void)
{
    int n;
    do
    {
        printf(" nhap so luong phan tu danh sach ");
        scanf("%d",&n);
        if (n<=0)
        {
            printf("so luong phan tu khong hop le");

        }
    } while (n<=0);
    node * list=ceatalit(n);
    int value;
    printf(" nhap so nguyen them vao dau danh sach ");
    scanf("%d",&value);
    list=themdau(list,value);
    pfint_lit(list);

    return 0;
}