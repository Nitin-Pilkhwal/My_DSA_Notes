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
struct node * insert_first(struct node* head, int data);
struct node *nodeAtEnd(struct node *head,int data);
struct node *nodeAtIndex(struct node *head,int data,int index);
void delete_node(struct node *head,int index);
int data_finder(struct node *head,int x);
struct node* reverseList(struct node *head);


int main(){
    int n;
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter no. of nodes you want in a list.");
    scanf("%d",&n);

    create(n,head);

    printf_list(head);

    // nodeAtEnd(head,n);
    // printf("\n\n\n\n");
    // printf_list(head);

    head=nodeAtIndex(head,876,3);
    printf("\n\n\n\n");
    printf_list(head);

    head=insert_first(head,876);
    printf("\n\n\n\n");
    printf_list(head);

    delete_node(head,3);       //indexing starts from 1 not 0
    printf("\n\n\n\n");
    printf_list(head);

    // data finder
    int x;
    printf("Enter the data you want to find");
    scanf("%d",&x);
    int finder=data_finder(head,x);
    if(finder==0)
        printf("Data doesn't exist in the LL.");
    else
        printf("Data exist in the LL.");
    return 0;
}



struct node *create(int n,struct node*head){
    struct node*p;
    p=head;
    for(int i=0;i<n;i++){
        int x;
        printf("Enter data");
        scanf("%d",&x);
        p->data=x;
        p->next=(struct node*)malloc(sizeof(struct node));
        p=p->next;
        p->next=NULL;
    }
    head=p;
    return head;
}



void printf_list(struct node *temp){
    int i=1;
    while(temp->next!=0){
        printf("\nData at node no. %d  %d \n",i,temp->data);
        temp=temp->next;
        i++;
    }
}



struct node * insert_first(struct node* head, int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}



struct node *nodeAtEnd(struct node *head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    struct node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    // return head;
}



struct node *nodeAtIndex(struct node *head,int data,int index){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    int i=0;
    while(i!=index-2){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return head;
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

int data_finder(struct node *head,int x){
    struct node *p;
    p=head;
    int i=1;
    int found=0;
    while(p!=NULL){
        if(p->data==x){
            found=1;
            break;
        }
        p=p->next;
        i++;
    }
    return found;
}

struct node* reverseList(struct node *head)
    {
        // code here
        struct node *pre,*cur,*nex;
        pre=NULL;
        cur=head;
        nex=head;
        while(nex!=NULL){
            nex=nex->next;
            cur->next=pre;
            pre=cur;
            cur=nex;
        }
        head=pre;
        return head;
        
        // return head of reversed list
    }