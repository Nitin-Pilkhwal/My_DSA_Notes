// #include <stdio.h>
#include <iostream>
using namespace std; 
struct node
{
    int data;
    struct node *next;
};


struct node *create(int n,struct node *head);
void printf_list(struct node *temp);
struct node *adderathead(struct node *head,int data);
struct node *nodeAtIndex(struct node *head,int data,int index);
void delete_node(struct node *head,int index);
struct node *nodeAtEnd(struct node *head,int data);


int main(){
    int n;
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter no. of nodes you want in a list.");
    scanf("%d",&n);

    create(n,head);
    printf_list(head);

    printf("\n\n");
    // head=adderathead(head,7654321);
    // printf_list(head);

    
    // head=nodeAtEnd(head,876);
    // printf("\n\n\n\n");
    // printf_list(head);

    // head=nodeAtIndex(head,876,4);
    // printf("\n\n\n\n");
    // printf_list(head);

    // head=insert_first(head,876);
    // printf("\n\n\n\n");
    // printf_list(head);

    // delete_node(head,3);       //indexing starts from 1 not 0
    // printf("\n\n\n\n");
    // printf_list(head);
    return 0;
}

struct node *create(int n,struct node *head){
    struct node*p;
    p=head;
    int x;
    for(int i=0;i<n;i++){
        printf("Enter data to the node");
        scanf("%d",&x);
        p->data=x;
        p->next=(struct node*)malloc(sizeof(struct node));
        p=p->next;
        p->next=NULL;
    }p->next=head;
}

void printf_list(struct node *temp){
    struct node*p;
    p=temp;
    int i=1;
    while(p->next!=temp){
        printf("Data at node %d is %d \n",i,p->data);
        i++;
        p=p->next;
    }
}   

struct node *adderathead(struct node *head,int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p;
    p=head;
    ptr->data=data;
    ptr->next=NULL;
    while(p->next!=head)
        p=p->next;
    p->next=ptr;
    ptr->next=head;
    return ptr;
}

void delete_node(struct node *head,int index){
    struct node* p=head;
    int i=1;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    p->next=p->next->next;
    return ;
}

struct node *nodeAtIndex(struct node *head,int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return head;
}

struct node *nodeAtEnd(struct node *head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=data;
    ptr->next=NULL;
    return head;
}