/*1
  2 2
  3 3 3
  4 4 4 4
*/
#include<bits/stdc++.h>
using namespace std;
void printp2(int n)
{ 
    for (int i=1;i<n+1;i++)
    {
        for (int j=1;j<=i;j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of lines :";
    cin>>n;
    printp2(n);
    return 0;
}