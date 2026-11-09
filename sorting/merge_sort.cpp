#include<bits/stdc++.h>
using namespace std;
void merge_sorts(int arr[],int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid&&right<=high)
    {
        if(arr[left]<arr[right])
        {
            temp.push_back(arr[left]);
            left++;      
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;      
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    

}
void merge_sort(int arr[],int low,int high)
{
    int mid=(low+high)/2;
    if(low==high)return;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge_sorts(arr,low,mid,high);
    

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
    merge_sort(arr,0,n-1);
    cout<<"Sorted array is:\n";
    for(int i=0;i<n;i++)cout<<arr[i]<<",";
    return 0;
}