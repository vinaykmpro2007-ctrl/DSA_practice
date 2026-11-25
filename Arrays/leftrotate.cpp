#include<bits/stdc++.h>
using namespace std;
void Leftrotateone(int a[],int n){
    int temp;
    temp=a[0];
    for(int i=1;i<n;i++){
        a[i-1]=a[i];
    }
    a[n-1]=temp;
    cout<<"Left rotated by one array:\n";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";

}
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;c
    int a[n];
    cout<<"Enter the elments of array:";
    for(int i=0;i<n;i++)cin>>a[i];
    Leftrotateone(a,n);
    return 0;

}