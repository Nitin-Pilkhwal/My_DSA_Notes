#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int data;
    struct stack *next;
}stack;

stack *top;

void push();
void pop();
void display();
int peek(int a);

int main(){
    int ch;
    while(1){
    printf("\nEnter your choice:\n");
    printf("\n1.push()\n2.pop()\n3.display()\n4.exit()\n5.peek()\n");
    scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(-1);
                break;
            case 5:
                peek(2);
                break;
            default:
                printf("\nINVALID INPUT!!!!");
        }
    }
}

void push(){
    int data;
    stack *ptr=(stack*)malloc(sizeof(stack));
    if(ptr==NULL)
        printf("\nMemory can't be allocate !!");
    else{
        printf("\nEnter the data:");
        scanf("%d",&data);
        if(top==NULL){
            ptr->data=data;
            ptr->next=NULL;
            top=ptr;
        }
        else{
            ptr->data=data;
            ptr->next=top;
            top=ptr;
        }
    }printf("\nItem pushed");
}

void pop(){
    stack *ptr;
    int item;
    if(top==NULL)
        printf("\nStack underflow");
    else{
        item=top->data;
        ptr=top;
        top=top->next;
        printf("Item removed %d",item);
        free(ptr);
    }
}

void display(){
    stack *ptr;
    int i=1;
    if(top==NULL)
        printf("\nStack underflow");
    else{
        ptr=top;
        while(ptr!=NULL){
            printf("Data at index %d is %d\n",i,ptr->data);
            i++;
            ptr=ptr->next;
        }
    }
}

int peek(int pos){
    stack *ptr;
    ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL)
        return ptr->data;
    else
        return -1;
}