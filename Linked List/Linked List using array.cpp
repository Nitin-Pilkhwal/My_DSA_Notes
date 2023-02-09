#include<stdio.h>
#include<stdlib.h>
#define MAX 10 // Macro defines maximum no. of elements in the list. It is a user defined data type
struct
{
    int list[MAX];
    int element;     //new element to be inserted
    int pos;           //position of the element to be inserted or deleted
    int length;     //total no of elements
} l;
// enum boolean
// {
//     true, false
// } boolean;        //function prototypes

int menu(void);           //This function displays the list of operations
void create(void);       //This function creates initial set of elements
void insert(int, int);    //This function inserts the element at specified position
void delet(int);       //This function deletes the element at given position
void find(int);        //This function finds the position of the given element, if exists
void display(void);       //This function displays the elements in the list
bool islistfull(void);  //This function checks whether the list is full or not boolean
bool islistempty(void);        //This function checks whether the list is empty or not

void main()
{
    int ch;
    int element;
    int pos;
    l.length = 0;
    while(1)
    {
        ch = menu();
        switch (ch)
        {
             case 1:   l.length = 0;
             create();
             break;
             case 2:
             if (islistfull() != true)
             {
                  printf("Enter New element: ");
                  scanf("%d", &element);
                  printf("Enter the Position : ");
                  scanf("%d", &pos);
                  insert(element, pos);
             }
             else
             {
                  printf("List is Full. Cannot insert the element");
                  printf("\n Press any key to continue...");
                //   getch();
             }
             break;
             case 3:
             if (islistempty() != true)
             {
                  printf("Enter the position of element to be deleted : ");
                  scanf("%d", &pos);
                  delet(pos);
             }
             else
             {
                  printf("List is Empty.");
                  printf("\n Press any key to continue...");
                //   getch();
             }
             break;
             case 4:
             printf("No of elements in the list is %d", l.length);
             printf("\n Press any key to continue...");
            //  getch();
             break;
             case 5:
             printf("Enter the element to be searched : ");
             scanf("%d", &element);
             find(element);
             break;
             case 6:
             display();
             break;
             case 7:
             printf("Exit");
             exit(0);
             break;
             default:  printf("Invalid Choice");
             printf("\n Press any key to continue...");
             
        }
    }
}        //function to display the list of elements
int menu()
{
    int ch;
    //clrscr();
    printf("1. Create\n2. Insert\n3. Delete\n4. Count\n5. Find\n6. Display\n7.Exit\n\n Enter your choice : ");
    scanf("%d", &ch);
    printf("\n\n");
    return ch;
}      
void create(void)
{
    int element;
    int flag=1;
    while(flag==1)
    {
        printf("Enter element : ");
        scanf("%d", &element);
        l.list[l.length] = element;
        l.length++;
        printf("To insert another element press '1' : ");
        scanf("%d", &flag);
    }
}     
void display(void)
{
    int i;
    for (i=0; i<l.length; i++)
        printf("Element %d : %d \n", i+1, l.list[i]);
    printf("Press any key to continue...");
    // getch();
}  
void insert(int element, int pos)
{
    int i;
    if (pos == 0)
    {
        printf("\nCannot insert an element at 0th position");
        return;
    }

    if (pos-1 > l.length)
    {
        printf("\nOnly %d elements exit. Cannot insert at %d position", l.length, pos);
        printf("\n Press any key to continue...");
    }
    else
    {
        for (i=l.length; i>=pos-1; i--)
        {
            l.list[i+1] = l.list[i];
        }
        l.list[pos-1] = element;
        l.length++;
    }
}     
void delet(int pos)
{
    int i;
    if(pos == 0)
    {
        printf("\nCannot delete at an element 0th position");
        return;
    }
    if (pos > l.length)
    {
        printf("\n\n Only %d elements exit. Cannot delete", l.length, pos);
        printf("\n Press any key to continue...");
        return;
    }
    for (i=pos-1; i<l.length; i++)
    {
        l.list[i] = l.list[i+1];
    }
    l.length--;
}      
void find(int element)
{
    int i;
    int flag = 1;

    for (i=0; i<l.length; i++)
    {
        if(l.list[i] == element)
        {
            printf ("%d exists at %d position",element, i+1);
            flag = 0;
            printf("\n Press any key to continue...");
            break;
        }
    }
    if(flag)
    {
        printf("Element not found.\n Press any key to continue...");
    }
}  

bool islistfull(void)
{
    if (l.length == MAX)
        return true;
    else
        return false;
}   

bool islistempty(void)
{
    if (l.length == 0)
        return true;
    else
        return false;
}