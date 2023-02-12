#include <iostream>
using namespace std;

int selectionsort(int a[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[min]>a[j]) min=j;
        }
        if(i!=min) swap(a[min],a[i]);
    }
}

int main(){
    int i,n;
    cout<<"enter the limit of an array";
    cin>>n;
    int arr[n];
    cout<<"enter elements to array";
    for (i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"array before sorting\n";
    for (i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    selectionsort(arr,n);
    cout<<"\narray after sorting\n";
    for (i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}