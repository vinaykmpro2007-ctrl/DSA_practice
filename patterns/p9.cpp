/*
   1
   2 3
   4 5 6
   7 8 9 10


*/


#include<bits\stdc++.h>
using namespace std;

void printp9(int n)
{ int c=1;
    for(int i=1;i<=n;i++)
    {

        
        for(int j=1;j<=i;j++)
        {cout<<c<<" ";
        c++;  
        }
        cout<<endl;
    }

}
int main()
{
  int n;
  cout<<"Enter the number of lines:";
  cin>>n;
 printp9(n);
 return 0;
}