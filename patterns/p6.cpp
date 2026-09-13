/* *
   * *
   * * *
   * * * *
   * * *
   * *
   * 
*/



#include<bits/stdc++.h>
using namespace std;
void printp6(int n)
{
   for (int i=1;i<2*n-1;i++)
   {  int s=i;
    if(i>n)
    {
        s=2*n-i;
    }
    for(int j=1;j<=s;j++)
    {
        cout<<"*";
    }
    cout<<endl;

   }
 
 
}
int main()
{ 
    int n;
    cout<<"Enter the number of lines: ";
    cin>>n;
    printp6(n);

    return 0;

}