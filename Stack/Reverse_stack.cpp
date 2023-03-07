#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack <int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return ;
    }
    int temp = st.top();
    st.pop();
    InsertAtBottom(st,ele);
    st.push(temp);
}

void reverse(stack <int> &st){
    if(st.empty()) return ;
    int temp = st.top();
    st.pop();
    reverse(st);
    InsertAtBottom(st,temp);
}

int main(){
    stack <int> Stack;
    Stack.push(100);
    Stack.push(100);
    Stack.push(200);
    Stack.push(400);
    Stack.push(2400);
    reverse(Stack);
    return 0;
}