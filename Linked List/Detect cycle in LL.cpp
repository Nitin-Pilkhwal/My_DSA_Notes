#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = new node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

bool detectLoop(struct node* h)
{
    unordered_set<node*> s;
    while (h != NULL) {
        if (s.find(h) != s.end())
            return true;
        s.insert(h);
        h = h->next;
    }
    return false;
}
int main()
{
    struct node* head = NULL; 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        cout << "Loop Found";
    else
        cout << "No Loop";
 
    return 0;
}