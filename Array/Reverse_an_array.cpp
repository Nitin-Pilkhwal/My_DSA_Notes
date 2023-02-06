#include<iostream>
using namespace std;

void print(int arr[],int);

int main(){
    int arr[]={11,233,5,2,45,13,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    return 0;
}

//Function to print elements of an array in reverse order.
void print(int arr[],int size){
    for(int i=size-1;i>=0;i--)
        cout<<arr[i]<<" ";
}

//function which acctually reverse the array.
void reversearray(int arr[],int end){
    int size=end-1;
    int start=0;
    int temp;
    while(start<size){
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

//Function to print elements in array.
void printarray(int arr[],int end){
    for(int i=0;i<end;i++){
        cout<<arr[i]<<" ";
    }
}