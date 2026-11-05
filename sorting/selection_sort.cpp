#include<bits/stdc++.h>
using namespace std;
void selection_sort(int n ,int arr[])
{
  int min,temp;
  for(int i=0;i<=n-2;i++){
    min=i;
    for(int j=i;j<=n-1;j++){
        if(arr[j]<arr[min]){min=j;} 
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        
    }
  }
  cout<<"Sorted array:\n ";
  for(int i=0;i<n;i++) cout<<arr[i]<<" , ";
}
int main()
{
    int n;
   
    cout<<"Enter the numbers of elements in the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selection_sort(n,arr);
    return 0;
}