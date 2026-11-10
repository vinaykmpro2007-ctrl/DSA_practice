#include<bits/stdc++.h>
using namespace std;
int fs(int arr[],int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){i++;}
        while(arr[j]>pivot && j>=low+1){j--;}
        if(i<j){swap(arr[i],arr[j]);}
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(int arr[],int low, int high){
    if(low<high){
        int pv=fs(arr,low,high);
        qs(arr,low,pv-1);
        qs(arr,pv+1,high);
    }
    else{return;}
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
    qs(arr,0,n-1);
    cout<<"Sorted array is:\n";
    for(int i=0;i<n;i++)cout<<arr[i]<<",";
    return 0;
}