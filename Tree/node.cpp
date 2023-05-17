#include <iostream>
using namespace std;

//Creating Node
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main(){
    struct Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    /*
        1
       / \
      2   3 
    */
    root->left = new Node(4);
    root->right = new Node(5);
    /*
                   1
                  / \
                 2   3 
                / \
               4   5 
    */
    return 0;
}