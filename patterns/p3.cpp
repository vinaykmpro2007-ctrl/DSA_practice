/* 1 2 3 4 5
   1 2 3 4
   1 2 3 
   1 2
   1
*/
#include<bits/stdc++.h>
using namespace std;
void printp3(int n)
{
    for (int i=n;i>0;i--)
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
    printp3(n);
    return 0;
}