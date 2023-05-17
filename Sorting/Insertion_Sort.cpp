#include <iostream>
using namespace std;


int main(){
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
        int key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout<<"array after sorting";
    for (i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}