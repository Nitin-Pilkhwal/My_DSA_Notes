#include <iostream>
using namespace std;

void IndSeqSearch(int a[],int n,int key){
    int g=3,i,j,set=0,start,end;
    int elements[g],indices[g],ind=0;
    for(int i=0;i<n;i+=g){
        indices[ind]=i;
        elements[ind]=a[i];
        ind++;
    }
        if (key < elements[0]) {
        printf("Not found");
        exit(0);
    }
    else {
        for (i = 1; i <= ind; i++)
            if (key <= elements[i]) {
                start = indices[i - 1];
                end = indices[i];
                set = 1;
                break;
            }
    }
    if (set == 0) {
        start = indices[g - 1];
        end = g;
    }
    for (i = start; i <= end; i++) {
        if (key == a[i]) {
            j = 1;
            break;
        }
    }
    if (j == 1)
        printf("Found at index %d", i);
    else
        printf("Not found");
}


int main(){
    int a[10]={10,20,10,20};
    IndSeqSearch(a,4,4);
    return 0;
}