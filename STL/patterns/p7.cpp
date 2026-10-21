/*
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/







#include<bits\stdc++.h>
using namespace std;
void printp7(int n)
{
    int k=0;
    for (int i=0;i<n;i++)
    {
        if (i%2==0)
           k=1;
        else 
           k=0;
        for (int j=0;j<=i;j++)
        {
            cout<<k<<" ";
            k=1-k;
        }
        cout<<endl;
    }


}
int main()
{
  int n;
  cout<<"Enter the number of lines:";
  cin>>n;
 printp7(n);
 return 0;
}
