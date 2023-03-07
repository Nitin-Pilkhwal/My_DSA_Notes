#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_valid(string s){
    stack <char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else{
            if(s[i] == ')' && st.top() == '(') st.pop();
            else if(s[i] == '}' && st.top() == '{') st.pop();
            else if(s[i] == ']' && st.top() == '[') st.pop();
            else return false;
        }
    }
    if(st.empty()) return true;
    return false;
}

int main(){
    string brackets = "{{[([{()}])]}}";
    if(is_valid(brackets)) cout<<"Valid Statement";
    else cout<<"Invalid Statement";
    //Output will be Valid Statement.
    return 0;
}