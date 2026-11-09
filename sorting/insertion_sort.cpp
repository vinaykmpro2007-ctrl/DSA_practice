#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int n,int arr[])
{
  for (int i=0;i<n;i++)
  {
    int j=i,temp;
    while(j>0 && arr[j-1]>arr[j]){
        temp=arr[j-1];
        arr[j-1]=arr[j];
        arr[j]=temp;
        j--;
    }
  }
  cout<<"Sorted array:\n";
  for(int i=0;i<n;i++)cout<<arr[i]<<",";
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
    insertion_sort(n,arr);
    return 0;
}