#include <iostream>
using namespace std;

int binarySearch(int a[],int n,int key){
    int l=0,h=n;
    while(l<h){
        int m=l+(h-l)/2;
        if(a[m]==key) return m;
        else if(a[m]>key) l=m+1;
        else h=m-1;
    }
    return -1;
}


int main(){
    int a[10]={10,20,10,20};
    cout<<binarySearch(a,4,4);
    return 0;
}