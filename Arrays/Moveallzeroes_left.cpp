#include<bits/stdc++.h>
using namespace std;
// optimal solution sc=O(n) and tc=O(1)

void Zeroleftrotation(int a[], int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }
    cout<<"All zeroes roated to left of the array:\n";
     for(int i=0;i<n;i++)cout<<a[i]<<" ";
}


// brute force tc=O(2n) and sc=O(n)
// void Zeroleftrotation(int a[], int n){
//     int temp[n],j=0;
//     for(int i=0;i<n;i++){
//        if(a[i]!=0){
//           temp[j]=a[i];
//           j++;
//        }

//     }
//     for(int i=0;i<j;i++){
//         a[i]=temp[i];
//     }
//     for(int i=j;i<n;i++){
//         a[i]=0;
//     }
// cout<<"All zeroes roated to left of the array:\n";
//  for(int i=0;i<n;i++)cout<<a[i]<<" ";
// }
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];
    cout<<"Enter the elments of array:";
    for(int i=0;i<n;i++)cin>>a[i];
    Zeroleftrotation(a,n);
    return 0;
}