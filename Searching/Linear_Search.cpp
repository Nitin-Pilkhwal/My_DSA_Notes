#include<iostream>
using namespace std;

int search(int arr[],int key,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key)
            return i;
    }
    return -1;
}

int main(){
    int a[10]={10,20,10,20};
    cout<<search(a,4,4);
    return 0;
}