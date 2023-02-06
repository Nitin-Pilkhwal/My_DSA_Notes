#include <iostream>
using namespace std;


void main(){
    int i,j,n;
    cout<<"enter the limit of an array";
    cin>>n;
    int arr[n];
    cout<<"enter elements to array";
    for (i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"array before sorting";
    for (i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    for (i=1;i<n;i++){
        int temp=arr[i];
        for(j=i-1;j>=0;j--){
            if (arr[j]>temp){
                arr[j+1]=arr[j];
                }
        }
    }
}