#include<bits/stdc++.h>
using namespace std;
int slargest(int a[],int n){
    int largest=a[0];
    int slargest=-1;
    for(int i=0;i<n;i++){
        if(a[i]>largest){
            slargest=largest;
            largest=a[i];
        }
        if(a[i]<largest && slargest!=largest){
            slargest=a[i];
        }
    }
    return slargest;
}
int ssmallest(int a[],int n){
    int smallest=a[0];
    int ssmallest=INT_MAX;
    for(int i=0;i<n;i++){
    if(a[i]<smallest){
        ssmallest=smallest;
        smallest=a[i];
    }
    if(a[i]!=smallest && a[i]<ssmallest){
        ssmallest=a[i];
    }
}
 return ssmallest;
}
int main(){
    int n;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array:\n";
    
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<"Second largest="<<slargest(arr,n);
    cout<<"Secon smallest="<<ssmallest(arr,n);
    return 0;
}