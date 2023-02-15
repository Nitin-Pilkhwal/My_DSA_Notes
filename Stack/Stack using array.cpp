#include<stdio.h>
#include<stdlib.h>

void push(int arr[],int item);
void pop(int arr[]);
void disp_stack(int arr[]);
int peek(int arr[],int pos);

int size;
int top=-1;
int main(){
    int item;
    printf("Enter the size of stack");
    scanf("%d",&size);
    int arr1[size];
    
    int i=size;
    while(i--){
        printf("Enter the element you want to add in stack");
        scanf("%d",&item);
        push(arr1,item);
    }
    disp_stack(arr1);
    pop(arr1);
    disp_stack(arr1);
    peek(arr1,4);
    

}
void push(int arr[],int item){
    if(top==size-1)
        printf("\nStack overflow\n");
    else{
        top++;
        arr[top]=item;
    }
}

void pop(int arr[]){
    if(top==-1)
        printf("\nStack underflow\n");
    else{
        printf("\nItem removed is %d\n",arr[top--]);
    }
}

void disp_stack(int arr[]){
    for(int i=top;i>=0;i--){
        printf("Element in stack at index %d is %d\n",i,arr[i]);
    }
}
int peek(int arr[],int pos){
    int item;
    for(int i=0;(i<pos-1 && arr[i]!=NULL);i++){
        item=arr[i];
    }
    printf("Item at position %d is %d",pos,item);

}