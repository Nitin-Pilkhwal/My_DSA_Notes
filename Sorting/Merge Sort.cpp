#include <iostream>
using namespace std;

int merge(int a[],int l,int m,int r){
    int i,j,k,n1,n2;
    n1= m-l+1;
    n2= r-m;

    int L[n1],R[n2];

    for(i=0;i<n1;i++)
        L[i] = a[l + i];
    for(j=0;j<n2;j++)
        R[j] = a[m+1 + j];
    
    i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
      while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
int mergesort(int a[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
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
    mergesort(arr,0,n);
    cout<<"\narray after sorting\n";
    for (i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}