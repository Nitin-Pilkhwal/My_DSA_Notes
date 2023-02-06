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
        cout<<arr[i];
    }
    for (i=0;i<n-1;i++){
        int flag=0;
        for(j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                flag=1;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }
        if (flag==0)
        {
            break;
        }
    }
    cout<<"\n \n array after sorting: ";
    for (i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }       
}