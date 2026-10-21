/*
   1         1
   12       21
   123     321
   1234   4321
   12345542321
*/



#include<bits\stdc++.h>
using namespace std;
void printp8(int n)
{   int i=1;
    for (i=1;i<=n;i++)
    { 
        for(int j=1;j<=i;j++)
            {cout<<j;}
        for(int j=1;j<2*(n-i);j++)
        {
            cout<<" ";
        }
        for(int j=i;j>=1;j--)
        {
            cout<<j;
        }
        cout<<endl;
    }
    
    
}

int main()
{
  int n;
  cout<<"Enter the number of lines:";
  cin>>n;
 printp8(n);
 return 0;
}