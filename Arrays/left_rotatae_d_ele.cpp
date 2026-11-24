#include<bits/stdc++.h>
using namespace std;
// Brute force : tc=O(d)+O(n-d)+O(d)=O(n ) but the sc=O(1)
// because of temp
// void Leftrotateone(int a[],int n,int d){
//     int temp[n];
//     d=d%n;
//     for(int i=0;i<d;i++){
//         temp[i]=a[i];
//     }
//     for(int i=d;i<n;i++){
//         a[i-d]=a[i];
//     }wq
//     for(int i=n-d;i<n;i++){
//         a[i]=temp[i-(n-d)];
//     }
//     cout<<"Array rotated by "<<d<<"rotations:\n";
//     for(int i=0;i<n;i++)cout<<a[i];

   

// }
// optimal solution: tc=O(n) no sc
Leftrotateone(int a[],int n,int d){
    d=d%n;
    reverse(a,a+d);
    reverse(a+d,a+n);
    reverse(a,a+n);
    cout<<"Array rotated by "<<d<<"Rotations(optimal solution):\n";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";

}
int main(){
    int n,d;
    cout<<"Enter the size of array:";
    cin>>n;
    int a[n];
    cout<<"Enter the elments of array:";
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<"Enter the number of rotations:";
    cin>>d;
    Leftrotateone(a,n,d);
    return 0;

}