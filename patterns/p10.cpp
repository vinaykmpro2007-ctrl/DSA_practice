/*
    A
    A B
    A B C
    A B C D 

*/

#include<bits\stdc++.h>
using namespace std;
// void printp10(int n)
// {
//     for (int i=1;i<=n;i++)
//     { 
//         for(int j=0;j<=i;j++)
//         {
//             cout<<char('A'+j)<<" ";
//         }
//         cout<<endl;

//     }

// }
void printp10(int n)
{
    for (int i=n;i>0;i--)
    { 
        for(int j=0;j<=i;j++)
        {
            cout<<char('A'+j)<<" ";
        }
        cout<<endl;

    }

}

int main()
{
  int n;
  cout<<"Enter the number of lines:";
  cin>>n;
 printp10(n);
 return 0;
}
