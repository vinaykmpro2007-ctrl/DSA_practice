/*     *           * * * * * *
      * *           * * * * * 
     * * *           * * * *
    * * * *           * * *
   * * * * *           * *
                        *
    Pyramid patterns 
*/
// #include<bits\stdc++.h>
// using namespace std;
// void printp4(int n)
// {
//     for (int i=0;i<n;i++)
//     {
//         for (int j=0;j<n-i-1;j++)
//         {
//             cout<<" ";
//         }
//         for (int j=0;j<2*i+1;j++)
//         {
//             cout<<"*";

//         }
//         for (int j=0;j<n-i-1;j++)
//         {
//             cout<<" ";
//         }
//         cout<<endl;
        
//     }
// }
// int main()
// {
//     int n;
//     cout<<"Enter the number of lines :";
//     cin>>n;
//     printp4(n);
//     return 0;
// }
// for same patterns in reverse
#include<bits\stdc++.h>
using namespace std;
void printp4(int n)
{
    for (int i=0;i<n;i++)
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
int main()
{
    int n;
    cout<<"Enter the number of lines :";
    cin>>n;
    printp4(n);
    return 0;
}
