/*1
  1 2
  1 2 3 
  1 2 3 4 
  1 2 3 4 5
*/


#include<bits/stdc++.h>
using namespace std;
void printp1(int n)
{
    for (int i=1;i<n+1;i++)
    {
        for (int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of lines :";
    cin>>n;
    printp1(n);
    return 0;
}