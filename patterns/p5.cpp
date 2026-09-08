/*    *
     * *
    * * *
   * * * *
   * * * *
    * * * 
     * *
      * 
   
      Diamond patterns
*/
#include<bits\stdc++.h>
using namespace std;
void printp5(int n)
{

    for (int i=0;i<n;i++)
    { 
        if (i<n/2)
        {
            for (int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }

        for (int j=0;j<2*i+1;j++)
        {
            cout<<"*";

        }
        for (int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
        
        }
    }
    for (int i=0;i<n;i++)
    {
        if (i>=n/2)
        {
             for (int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for (int j=0;j<2*n-(2*i+1);j++)
        {
            cout<<"*";

        }
        for (int j=0;j<i;j++)
        {
            cout<<" ";
        }
        cout<<endl;
        
        }
        
    }
}
int main()
{
    int n;
    cout<<"Enter the number of lines :";
    cin>>n;
    printp5(n);
    return 0;
}

