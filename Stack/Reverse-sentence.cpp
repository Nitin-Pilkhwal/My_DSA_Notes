#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse_sentence(string sentence){
    stack<string> s;
    for(int i=0;i<sentence.size();i++){
        string word = "";
        while(sentence[i] != ' ' && i<sentence.size()){
            word+=sentence[i];
        }
        s.push(word);
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

int main(){
    string sentence ;
    sentence = " This is an example of reversing a sentence.";
    reverse_sentence(sentence);
    return 0;
}