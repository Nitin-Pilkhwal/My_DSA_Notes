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

poly poly_sub(poly *poly1,poly *poly2,poly *result){
    // poly *result;
    // result=(poly*)malloc(sizeof(poly));
    while(poly1->link && poly2->link){
      if(poly1->pow > poly2->pow){
        result->pow=poly1->pow;
        result->coeft=poly1->coeft;
        poly1=poly1->link;
      }
      else if(poly1->pow < poly2->pow){
        result->pow=poly2->pow;
        result->coeft=poly2->coeft;
        poly2=poly2->link;
      }
      else{
        result->pow=poly1->pow;
        result->coeft=poly1->coeft - poly2->coeft;
        poly1 = poly1->link;
        poly2 = poly2->link;
      }
      result->link=(poly*)malloc(sizeof(poly));
      result=result->link;
      result->link=NULL;
    }
    while (poly1->link || poly2->link) {
        if (poly1->link) {
            result->pow = poly1->pow;
            result->coeft = poly1->coeft;
            poly1 = poly1->link;
        }
        if (poly2->link) {
            result->pow = poly2->pow;
            result->coeft = (poly2->coeft)*(-1);
            poly2 = poly2->link;
        }
        result->link=(poly*)malloc(sizeof(poly));
        result=result->link;
        result->link = NULL;
    }
    return *result;
}

int main(){
  poly *head,*poly1,*poly2,*result;
  int n1,n2;
  // head=(poly*)malloc(sizeof(poly));
  poly1=(poly*)malloc(sizeof(poly));
  poly2=(poly*)malloc(sizeof(poly));
  result=(poly*)malloc(sizeof(poly));

  printf("Enter highest power of 1st polynomial\n");
  scanf("%d",&n1);
  printf("Enter data in 1st polynomial\n");
  create(n1,poly1);
  printf("\n\n");

  printf("Enter highest power of 2nd polynomial\n");
  scanf("%d",&n2);
  printf("Enter data in 2nd polynomial\n");
  // create(n2,poly2);
  printf("\n\n");


  printf_poly(poly1);
  printf("\n\n");
  // printf_poly(poly2);
  printf("\n\n");
  
  poly_sub(poly1,poly2,result);
  printf_poly(result);
  return 0;

}