// #include <stdio.h>
#include <iostream>
using namespace std; 
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*p,*prev_node,*tail,*ptr;


struct node *create(int n,struct node *head);
void printf_list(struct node *temp);
struct node * insert_first(struct node* head, int data);
struct node *nodeAtEnd(struct node *head,int data);
struct node *nodeAtIndex(struct node *head,int data,int index);
void delete_node(struct node *head,int index);
void printf_list_backward(struct node *temp);
struct node *createDCLL(int n,struct node *head);
void printf_list_reverse(struct node *temp);


int main(){
    int n;
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter no. of nodes you want in a list.");
    scanf("%d",&n);

    create(n,head);

    printf_list(head);

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
    printf("\n\n\n\n");

    printf_list_reverse(head);
    
    // printf_list(head);
    return 0;
}

struct node *create(int n,struct node *head){
    int x;
    head->left=NULL;
    head->right=NULL;
    p=head;
    prev_node=head;
    for(int i=0;i<n;i++){
        printf("Enter data:");  
        scanf("%d",&x);
        p->data=x;
        prev_node=p;
        p->right=(struct node*)malloc(sizeof(struct node));
        p=p->right;
        p->left=prev_node;
        prev_node->right=p;
        p->right=NULL;
    }
    
    return p;
}

void printf_list(struct node *temp){
    p=temp;
    int i=1;
    while (p->right!=NULL)
    {
        printf("Data at node %d is %d \n",i,p->data);
        i++;
        p=p->right;
    }
    tail=p;
}

struct node * insert_first(struct node* head, int data){
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->left=NULL; 
    ptr->right=NULL;
    ptr->data=data; 
    head->left=ptr;
    ptr->right=head;
    head=ptr;
    return head;
}


// struct node *createDCLL(int n,struct node *head){
//     struct node *p,*tail;
//     p=head;
//     while(p->right!=NULL){
//         p=p->right;
//     }
//     p->right=head;
//     head=p;
//     return head;
// }
void printf_list_reverse(struct node *temp){
    p=temp;
    while (p->right!=NULL)
    {
        p=p->right;
    }
    tail=p;
    while(tail->left!=temp){
        printf("%d\n",tail->data);
        tail=tail->left;

    }
}
void delete_node(struct node *head,int index){
    p=head;
    while(index--){
        p=p->right;
    }
    prev_node=p->left->left;
    p->left=prev_node;
    prev_node->right=p;
}
struct node *nodeAtIndex(struct node *head,int data,int index){
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    while(index--){
        p=p->right;
    }
    ptr->right=p;
    ptr->left=p->left;
    p->left=ptr;
    p=ptr->left;
    p->right=ptr;
    return head;
}