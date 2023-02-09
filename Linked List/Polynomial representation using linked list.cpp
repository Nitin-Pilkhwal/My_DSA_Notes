#include<iostream>
using namespace std;

struct node
{ 
int coeft;
struct node *link;
int pow;
};
typedef struct node poly;
poly* create(int pow,poly *head){
    int coeff;
    poly *temp;
    temp=head;
    while(pow>=0){
      printf("Enter the coeff with degree %d: ",pow);
      scanf("%d",&coeff);
      temp->coeft=coeff;
      temp->pow=pow;
      temp->link=(poly*)malloc(sizeof(poly));
      temp=temp->link;
      temp->link=NULL;
      pow--;
    }
    return temp;
}

void printf_poly(struct node *temp){
    // int i=1;
    poly *p;
    p=temp;
    while(p->link!=0){
        if(p->coeft>=0)
            printf("+%d x^%d ",p->coeft,p->pow);
        else
            printf("%d x^%d ",p->coeft,p->pow);
        p=p->link;
    }
}